#include <iostream>
#include <map>
#include <cassert>
#include <vector>
#include <algorithm>
#include <deque>

const int MAX_LENGTH = 1 << 19;
const int MAX_QUERY = 1 << 20;
const int INF = 1023456789;

using namespace std;

class segtree {
  int *tree, *lend, *rend, size;

  void make_node (int vertex, int _lend, int _rend) {
    tree[vertex] = INF;
    lend[vertex] = _lend;
    rend[vertex] = _rend;

    if (rend[vertex] - lend[vertex] > 1) {
      make_node(2 * vertex,     lend[vertex], (lend[vertex] + rend[vertex]) / 2);
      make_node(2 * vertex + 1, (lend[vertex] + rend[vertex]) / 2, rend[vertex]);
    }
  }

  void update (int vertex) {
    if (vertex != 0) {
      if (tree[vertex] != min(tree[2 * vertex], tree[2 * vertex + 1])) {
        tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
        update(vertex / 2);
      }
    }
  }

public:
  segtree (int _size) {
    size = _size;
    tree = new int [2 * size + 5];
    lend = new int [2 * size + 5];
    rend = new int [2 * size + 5];

    make_node(1, 0, size);
  }

  void set (int index, int value) {
    tree[size + index] = value;
    update((size + index) / 2);
  }

  int get (int vertex, int ql, int qr) {
    ql = max(lend[vertex], ql);
    qr = min(rend[vertex], qr);
  
    if (ql >= qr) {
      return INF;
    } else if (ql == lend[vertex] && qr == rend[vertex]) {
      return tree[vertex];
    } else {
      return min(get(2 * vertex, ql, qr),
                 get(2 * vertex + 1, ql, qr));
    }
  }
};

struct query {
  int type, left, right, val, index;

  query () {
  }

  query (int _type, int _left, int _right, int _val) {
    assert(_type == 1);

    type = _type;
    left = _left;
    right = _right;
    val = _val;
  }

  query (int _type, int _index, int _val) {
    assert(_type == 0);
    
    type = _type;
    index = _index;
    val = _val;
  }
};

bool operator< (query p, query q) {
  if (p.val == q.val) {
    return p.type < q.type;
  } else {
    return p.val > q.val;
  }
}

struct element {
  int loc, val;

  element () {
  }

  element (int _loc, int _val) {
    loc = _loc;
    val = _val;
  }
} elements [MAX_LENGTH];

bool operator< (element p, element q) {
  if (p.val == q.val) {
    return p.loc < q.loc;
  } else {
    return p.val < q.val;
  }
}

int arr [MAX_LENGTH], nxt [MAX_LENGTH], jump [MAX_LENGTH];
int dp [MAX_LENGTH], prev [MAX_LENGTH];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_LENGTH; i++) {
    nxt[i] = INF;
    jump[i] = INF;
    prev[i] = -1;
  }

  int length;
  cin >> length;

  map<int, int> last;
  vector<query> queries;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    if (last.find(arr[i]) != last.end()) {
      nxt[last[arr[i]]] = i;
      queries.push_back(query(0, last[arr[i]], i));
      queries.push_back(query(1, last[arr[i]] + 1, i, i + 1));
    }
    last[arr[i]] = i;
    elements[i] = element(i, arr[i]);
  }

  segtree nxtmin (MAX_LENGTH);
  sort(queries.begin(), queries.end());
  for (int i = 0; i < (int) queries.size(); i++) {
    if (queries[i].type == 0) {
      nxtmin.set(queries[i].index, queries[i].val);
    } else {
      jump[queries[i].left - 1] = 
        nxtmin.get(1, queries[i].left, queries[i].right) + 1;
    }
  }

  sort(elements, elements + length);
  for (int i = 0; i < length; i++) {
    if (elements[i].val == elements[i + 3].val) {
      jump[elements[i].loc] = min(jump[elements[i].loc], 
                                  elements[i + 3].loc + 1);
    }
  }

  for (int i = 0; i < length; i++) {
    if (jump[i] < INF) {
      if (dp[jump[i]] <= dp[i]) {
        dp[jump[i]] = dp[i] + 1;
        prev[jump[i]] = i;
      }
    }

    if (dp[i + 1] < dp[i]) {
      dp[i + 1] = dp[i];
      prev[i + 1] = prev[i];
    }
  }

  deque<int> ans;
  for (int i = prev[length]; i != -1; i = prev[i]) {
    ans.push_front(arr[jump[i] - 1]);
    ans.push_front(arr[i]);
    ans.push_front(arr[jump[i] - 1]);
    ans.push_front(arr[i]);
  }

  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}