#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> idx;
int cur = 0;

int get_idx (int p) {
  if (idx.count(p) == 0) {
    cur++;
    idx[p] = cur;
  }
  return idx[p];
}

const int maxn = 400005;
const int mod = 1000000007;
const int inf = 1023456789;
typedef long long llong;

struct maxt {
  int operator() (int p, int q) {
    return max(p, q);
  }
};

struct mint {
  int operator() (int p, int q) {
    return min(p, q);
  }
};

template<typename T, class comp>
class segtree {
  T* tree;
  int segstart, segsize, treeh;
  T ident;

  int rstart (int vertex, int height) {
    return (vertex << height) - segstart;
  }

  int rend (int vertex, int height) {
    return rstart(vertex + 1, height) - 1;
  }

  T ttop (int left, int right, int root, int height) {
    left = std::max(left, rstart(root, height));
    right = std::min(right, rend(root, height));

    if (left == rstart(root, height) && 
	right == rend(root, height)) {
      return tree[root];
    } else if (left > right) {
      return ident;
    } else {
      return comp()(ttop(left, right, root << 1, height - 1),
		    ttop(left, right, root << 1 ^ 1, height - 1));
    }
  }

public:
  segtree (int s, T id) {
    ident = id;

    for (int i = 2; i < 20; i++) {
      if (s < 1 << i) {
	segstart = 1 << i;
	segsize = segstart * 2;
	treeh = i;
	break;
      }
    }
      
    tree = new T [segsize];
    for (int i = 0; i < segsize; i++) {
      tree[i] = id;
    }
  }

  T top (int left, int right) {
    return ttop(left, right, 1, treeh);
  }

  void set (int index, T val) {
    tree[index + segstart] = val;
    
    for (int i = index + segstart; i != 1; i >>= 1) {
      if (tree[i >> 1] != comp()(tree[i], tree[i ^ 1])) {
	tree[i >> 1] = comp()(tree[i], tree[i ^ 1]);
      } else {
	break;
      }
    }
  }
};

int adds [maxn], rems [maxn], arr [maxn];
int is_buy [maxn], is_sell [maxn];
int accept [maxn], is_lbc [maxn];

int main () {
  ios::sync_with_stdio(false);

  int queryc;
  cin >> queryc;

  segtree<int, mint> mintree (maxn, inf);
  segtree<int, maxt> maxtree (maxn, -inf);
  
  for (int i = 0; i < queryc; i++) {
    string type;
    cin >> type >> arr[i];

    if (type == "ADD") {
      adds[get_idx(arr[i])] = i;
    } else {
      accept[i] = 1;
      rems[get_idx(arr[i])] = i;
      mintree.set(i, arr[i]);
      maxtree.set(i, arr[i]);
    }
  }

  for (int i = 1; i <= cur; i++) {
    if (rems[i] == 0) {
      rems[i] = queryc;
    }
  }
  
  for (int i = 0; i < queryc; i++) {
    if (i == adds[get_idx(arr[i])]) {
      if (mintree.top(adds[get_idx(arr[i])], rems[get_idx(arr[i])]) < arr[i]) {
      } else {
        is_buy[i] = 1;
      }
      if (maxtree.top(adds[get_idx(arr[i])], rems[get_idx(arr[i])]) > arr[i]) {
      } else {
        is_sell[i] = 1;
      }
    }
  }
  
  priority_queue<int, vector<int>, greater<int>> sells;
  priority_queue<int, vector<int>, less<int>> buys;
  int ambig = -inf;
  sells.push(inf);
  buys.push(-inf);
  for (int i = 0; i < queryc; i++) {
    if (!accept[i]) {
      if (is_buy[i]) {
        if (sells.top() < arr[i] && sells.top() != -inf) {
          is_buy[i] = false;
        }
      }

      if (is_sell[i]) {
        if (buys.top() > arr[i] && buys.top() != inf) {
          is_sell[i] = false;
        }
      }
      
      if (is_buy[i] && is_sell[i]) {
        ambig = arr[i];
      } else if (is_buy[i]) {
        buys.push(arr[i]);
      } else if (is_sell[i]) {
        sells.push(arr[i]);
      } else {
        cout << 0 << endl;
        return 0;
      }
    } else {
      int j = adds[get_idx(arr[i])];

      if (is_buy[j] && is_sell[j]) {
        if (ambig != arr[i]) {
          cout << 0 << endl;
          return 0;
        }
        ambig = -inf;
      } else if (is_buy[j]) {
        if (buys.top() != arr[i]) {
          cout << 0 << endl;
          return 0;
        }
        buys.pop();
      } else if (is_sell[j]) {
        if (sells.top() != arr[i]) {
          cout << 0 << endl;
          return 0;
        }
        sells.pop();
      }
    }
  }

  int lbc = 0;
  for (int i = 1; i <= cur; i++) {
    if (rems[i] == queryc && is_buy[adds[i]] && is_sell[adds[i]]) {
      is_lbc[adds[i]] = 1;
      lbc++;
    }
  }
  
  llong ans = 1;
  for (int i = 0; i < queryc; i++) {
    if (!accept[i] && !is_lbc[i]) {
      ans *= (is_buy[i] + is_sell[i]);
      ans %= mod;
    }
  }
  ans *= lbc + 1;
  ans %= mod;
  cout << ans << endl;
}