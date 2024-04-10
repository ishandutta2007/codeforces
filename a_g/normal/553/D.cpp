#include <bits/stdc++.h>
using namespace std;

struct frac {
  int num, denom;
};

bool operator < (const frac& a, const frac& b) {
  return 1LL*a.num*b.denom < 1LL*b.num*a.denom;
}

bool operator > (const frac& a, const frac& b) {
  return b < a;
}

const int N = 1e5+5;
bool fortress[N];
vector<int> G[N];
int active_nbrs[N], expiration_time[N];
pair<frac, int> tree[2*N];
int n;

void upd(int v) {
  int i = v+n;
  tree[i] = make_pair(frac{active_nbrs[v], (int)G[v].size()}, v);
  for (; i > 1; i >>= 1) {
    tree[i>>1] = min(tree[i], tree[i^1]);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    v--;
    fortress[v] = 1;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int v = 0; v < n; v++) {
    for (int u: G[v]) {
      if (!fortress[u]) active_nbrs[v]++;
    }
    if (fortress[v]) active_nbrs[v] = (int)G[v].size()+1;
    tree[v+n] = make_pair(frac{active_nbrs[v], (int)G[v].size()}, v);
  }
  for (int i = 2*n-1; i > 1; i--) {
    tree[i>>1] = min(tree[i], tree[i^1]);
  }

  frac best_ratio = tree[1].first;
  int best_time = 0;
  for (int i = 0; i < n-k-1; i++) {
    int v = tree[1].second;
    expiration_time[v] = i+1;
    active_nbrs[v] = (int)G[v].size()+1;
    upd(v);
    for (int u: G[v]) {
      if (!expiration_time[u] && !fortress[u]) {
        active_nbrs[u]--;
        upd(u);
      }
    }
    if (tree[1].first > best_ratio) {
      best_ratio = tree[1].first;
      best_time = i+1;
    }
  }
  expiration_time[tree[1].second] = n-k;
  cout << n-k-best_time << '\n';
  for (int v = 0; v < n; v++) {
    if (!fortress[v] && expiration_time[v] > best_time) {
      cout << v+1 << ' ';
    }
  }
  cout << '\n';
}