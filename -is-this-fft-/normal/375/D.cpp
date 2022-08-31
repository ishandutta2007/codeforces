#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_SIZE = 100005;
const int MAX_QUERY = 100005;
const int MAX_COLOR = 100005;

using namespace std;

class fenwick {
  int* tree;
  int size;

public:
  fenwick (int s) {
    size = s;
    tree = new int [size + 1];

    for (int i = 0; i < size + 1; i++) {
      tree[i] = 0;
    }
  }

  void add (int index, int val) {
    if (index > 0) {
      for (int i = index; i <= size; i += (i & -i)) {
	tree[i] += val;
      }
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= (i & -i)) {
      ans += tree[i];
    }
    return ans;
  }
};

int bginx [MAX_SIZE], endinx [MAX_SIZE], cur;
vector<int> adjacency [MAX_SIZE];
void traverse (int index, int parent) {
  cur++;
  bginx[index] = cur;
  for (int i = 0; i < adjacency[index].size(); i++) {
    if (adjacency[index][i] != parent) {
      traverse(adjacency[index][i], index);
    }
  }
  endinx[index] = cur;
}

int sqrt_int (int square, int start, int end) {
  int mid = (start + end) / 2;
  if (mid * mid <= square && square < (mid + 1) * (mid + 1)) {
    return mid;
  } else if (square < mid * mid) {
    return sqrt_int(square, start, mid);
  } else {
    return sqrt_int(square, mid + 1, end);
  }
}

struct query {
  int left, right, mincnt, index;
};

int slicesize;
bool operator< (query p, query q) {
  if (p.left / slicesize == q.left / slicesize) {
    return p.right < q.right;
  } else {
    return p.left / slicesize < q.left / slicesize;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int verticec, queryc;
  cin >> verticec >> queryc;

  int scolor [MAX_SIZE];
  for (int i = 1; i <= verticec; i++) {
    cin >> scolor[i];
  }

  for (int i = 0; i < verticec - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjacency[a].push_back(b);
    adjacency[b].push_back(a);
  }

  traverse(1, 0);
  
  int color [MAX_SIZE];
  for (int i = 1; i <= verticec; i++) {
    color[bginx[i]] = scolor[i];
  }

  query queries [MAX_QUERY];
  for (int i = 0; i < queryc; i++) {
    int root;
    cin >> root;
    queries[i].left = bginx[root];
    queries[i].right = endinx[root];
    cin >> queries[i].mincnt;
    queries[i].index = i;
  }
  
  slicesize = sqrt_int(verticec + 1, 0, 1 << 15);
  sort(queries, queries + queryc);

  int colorc [MAX_COLOR], ans [MAX_QUERY];
  fenwick countcnt (MAX_SIZE);

  for (int i = 0; i < MAX_COLOR; i++) {
    colorc[i] = 0;
  }

  /*for (int i = 0; i < MAX_QUERY; i++) {
    ans[i] = 0;
    }*/
  
  int lptr = 0, rptr = 0;
  for (int i = 0; i < queryc; i++) {
    while (rptr < queries[i].right) {
      ++rptr;
      ++colorc[color[rptr]];
      countcnt.add(colorc[color[rptr]] - 1, -1);
      countcnt.add(colorc[color[rptr]], 1);
    }

    while (lptr > queries[i].left) {
      --lptr;
      ++colorc[color[lptr]];
      countcnt.add(colorc[color[lptr]] - 1, -1);
      countcnt.add(colorc[color[lptr]], 1);
    }

    while (rptr > queries[i].right) {
      --colorc[color[rptr]];
      countcnt.add(colorc[color[rptr]] + 1, -1);
      countcnt.add(colorc[color[rptr]], 1);
      --rptr;
    }

    while (lptr < queries[i].left) {
      --colorc[color[lptr]];
      countcnt.add(colorc[color[lptr]] + 1, -1);
      countcnt.add(colorc[color[lptr]], 1);
      ++lptr;
    }

    ans[queries[i].index] = countcnt.get(verticec) - 
      countcnt.get(queries[i].mincnt - 1);
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << endl;
  }
}