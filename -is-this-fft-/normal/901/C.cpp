#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> adj [MAX_N];
vector<int> ch [MAX_N];
int lvl [MAX_N];
int up [MAX_N];
int dn [MAX_N];

void dfs (int u, int p) {
  lvl[u] = lvl[p] + 1;

  for (int nxt : adj[u]) {
    if (lvl[nxt] == 0) {
      ch[u].push_back(nxt);
      dfs(nxt, u);
    } else if (lvl[nxt] < lvl[u] && nxt != p) {
      up[u] = 1;
    } else if (lvl[nxt] > lvl[u]) {
      dn[u] = 1;
    }
  }
}

int mn [MAX_N];
int mx [MAX_N];
vector<pair<int, int>> forb;
void build_forb (int u) {
  if (up[u]) {
    mn[u] = u;
    mx[u] = u;
  }
  
  for (int nxt : ch[u]) {
    build_forb(nxt);

    if (up[nxt]) {
      assert(!up[u]);
      up[u] = 1;
      mn[u] = min(mn[nxt], u);
      mx[u] = max(mx[nxt], u);
    }
  }

  if (dn[u]) {
    up[u] = 0;
    forb.push_back(make_pair(mn[u], mx[u]));
  }
}

int min_all [MAX_N];

typedef long long ll;

ll cum [MAX_N];
int leasti [MAX_N];

ll sums (ll x) {
  return x * (x + 1) / 2;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (lvl[i] == 0) {
      dfs(i, 0);
      build_forb(i);
    }
  }

  min_all[1] = 1;
  for (auto pr : forb) {
    min_all[pr.second] = max(min_all[pr.second], pr.first + 1);
  }

  for (int i = 2; i <= n; i++) {
    min_all[i] = max(min_all[i], min_all[i - 1]);
  }

  for (int i = 1; i <= n; i++) {
    cum[i] = (ll) (i - min_all[i] + 1) + cum[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    leasti[min_all[i]] = max(leasti[min_all[i]], i);
  }

  for (int i = 2; i <= n; i++) {
    leasti[i] = max(leasti[i], leasti[i - 1]);
  }
  
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    r++;

    int m = leasti[l] + 1;
    m = min(m, r);
    m = max(l, m);
    
    ll lf = cum[r - 1] - cum[m - 1];
    ll rf = (ll) -l * (ll) (m - l) + sums(m - 1) - sums(l - 1) + (ll) (m - l);
    cout << lf + rf << '\n';
  }
}