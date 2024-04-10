#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 15000 + 7;

vector <int> g[N];
int u[N];
int par[N];

bool cyc[N];

vector <int> arr;

int id[N];

void dfs(int v, int pr = -1) {
  u[v] = 1;
  for (int to : g[v]) {
    if (to == pr) continue;
    if (!u[to]) {
      par[to] = v;
      dfs(to, v);
    } else if (u[to] == 1) {
      int x = v;
      while (x != par[to]) {
        cyc[x] = true;
        arr.push_back(x);
        x = par[x];
      }
    }
  }
  u[v] = 2;
}

bool vis[N];

int zhfs(int v) {
  vis[v] = true;
  int sum = 1;
  for (int to : g[v]) {
    if (!vis[to]) {
      sum += zhfs(to);
    }
  }
  return sum;
}

int sz[N];
int dp[N];
int ndp[N];
int sum[N];
int ans[N];

map <pair <int, int>, pair <int, int> > st;
pair <int, int> sysum;

int ofans[N];
int osz[N];

int tot = 0;

pair <int, int> rofl[N];

pair <int, int> flex(int v, int par) {
  /*
  if (st.count({v, par})) {
    return st[{v, par}];
  }
  */
  if (!cyc[v]) {
    int sum = 0;
    int sz = 1;
    for (int to : g[v]) {
      if (to != par) {
        auto go = flex(to, v);
        sum += go.first;
        sz += go.second;
      }
    }
    return {sum + sz, sz};
  } else {
    int sum = ans[v];
    int sz = 1;
    sum += sysum.first - ofans[v];
    sz += sysum.second - osz[v];
    if (par != -1) {
      sum += ofans[v] - rofl[par].first;
      sz += osz[v] - rofl[par].second - 1;
    }
    return {sum + sz, sz};
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  par[0] = -1;
  dfs(0);
  for (int v : arr) {
    vis[v] = true;
  }
  tot = 0;
  for (int i = 0; i < (int) arr.size(); i++) {
    id[arr[i]] = i;
    sz[i] = zhfs(arr[i]);
    tot += sz[i];
  }
  int m = (int) arr.size();
  for (int len = m - 1; len > 0; len--) {
    int sum = 0;
    for (int i = 0; i < len; i++) sum += sz[i];
    for (int i = 0; i < m; i++) {
      int j = i - 1;
      if (j < 0) j += m;
      ndp[i] = max(dp[i], dp[j]) + tot - sum;
      sum -= sz[i];
      int go = i + len;
      if (go >= m) go -= m;
      sum += sz[go];
    }
    for (int i = 0; i < m; i++) {
      dp[i] = ndp[i];
    }
  }
  for (int i = 0; i < m; i++) {
    ans[arr[i]] = dp[i];
  }
  for (int v : arr) {
    sysum.second++;
    osz[v]++;
    for (int to : g[v]) {
      if (!cyc[to]) {
        auto go = flex(to, v);
        rofl[to] = go;
        ofans[v] += go.first;
        osz[v] += go.second;
        sysum.first += go.first;
        sysum.second += go.second;
      }
    }
  }
  pair <int, int> ans = make_pair(0, 0);
  for (int i = 0; i < n; i++) {
    ans = max(ans, flex(i, -1));
  }
  cout << ans.first << '\n';
}