#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int l = 16;
int a[N];
int n;

vector<int> nbrs[N];

int timer;
int tin[N], tout[N];
int up[N][l+1];

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

fenwick<long long> ft(2*N);

void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i-1]][i-1];

  for (int u : nbrs[v]) {
    if (u != p)
      dfs(u, v);
  }

  tout[v] = ++timer;
  ft.add(tin[v], a[v]);
  ft.add(tout[v], -a[v]);
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

void preprocess(int root) {
  timer = 0;
  dfs(root, root);
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = abs(x);
  }

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    nbrs[u].push_back(v);
    nbrs[v].push_back(u);
  }
  preprocess(1);

  while (q--) {
    int k, b, c;
    cin >> k >> b >> c;
    if (k == 1) {
      int diff = abs(c)-a[b];
      ft.add(tin[b], diff);
      ft.add(tout[b], -diff);
      a[b] = abs(c);
    }
    else {
      int v = lca(b, c);
      long long ans = 2*(ft.query(tin[b]) + ft.query(tin[c]) - 2*ft.query(tin[v])) + 2*a[v]-a[b]-a[c];
      cout << ans << '\n';
    }
  }
}