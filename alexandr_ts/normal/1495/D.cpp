#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 610;

vector<int> g[N];
int dist[N][N];

void calc_dists(int st, int n) {
  fill(dist[st], dist[st] + n, INF);
  dist[st][st] = 0;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u: g[v]) {
      if (dist[st][u] == INF) {
        dist[st][u] = dist[st][v] + 1;
        q.push(u); 
      }
    }
  }
}

int ans[N][N];

int calc(int v1, int v2, int n) {
  vector<pair<int, int>> d(n);
  for (int i = 0; i < n; ++i) {
    d[i] = {dist[i][v1] + dist[i][v2] - dist[v1][v2], i};
    if (d[i].first % 2) {
      return 0;
    }
    d[i].first /= 2;
  }
  auto d2 = d;
  sort(d.begin(), d.end());
  int cnt0 = 0;
  for (int i = 0; i < n; ++i) {
    cnt0 += (d[i].first == 0);
  }
  if (cnt0 != dist[v1][v2] + 1) {
    return 0;
  }

  int i = 0;
  while (i < n && d[i].first == 0) {
    i++;
  }
  ll ans = 1;
  for (; i < n; ++i) {
    int v = d[i].second; 
    ll cnt_good = 0;
    for (auto u: g[v]) {
      if (d2[u].first == d2[v].first - 1) {
        cnt_good++; 
      }
    }
    ans = (ans * cnt_good) % MOD;
  }

  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[--v].push_back(--u);
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    calc_dists(i, n);
  }

  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << dist[i][j] << " ";
    }
  cout << endl;
  }
  */

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans[i][j] = ans[j][i] = calc(i, j, n);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}