#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e5 + 10;

unordered_set<int> g[N];
bool used[N];
int us[N];
int siz[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    if (!g[i].empty()) {
      g[i].clear();
    }
    used[i] = false;
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[--v].insert(--u);
    g[u].insert(v);
  }

  if ((ll)k * (k - 1) / 2 > m) {
    cout << "-1\n";
    return;
  }

  set<pair<int, int>> sz; 
  for (int i = 0; i < n; ++i) {
    sz.insert({g[i].size(), i}); 
    siz[i] = g[i].size();
  }

  mt19937 gen(123);
  
  while (sz.size() >= k) {
    int v = sz.begin()->second;
    int cnt = sz.begin()->first;
    if (cnt >= k) {
      assert(sz.size() > k);
      cout << 1 << " " << sz.size() << "\n";
      for (auto [s, v]: sz) {
        cout << v + 1 << " ";
      }
      cout << "\n";
      return;
    }
    if (cnt == k - 1) {
      int ptr = 0;
      for (auto u: g[v]) {
        if (!used[u]) {
          us[ptr++] = u;
        }
      }
      assert(ptr == k - 1);
      shuffle(us, us + ptr, gen);
      bool ok = true;
      for (int i = 0; ok && i < ptr; ++i) {
        for (int j = i + 1; ok && j < ptr; ++j) {
          ok &= g[us[i]].count(us[j]);
        }
      }
      if (ok) {
        cout << 2 << "\n";
        us[ptr] = v;
        for (int i = 0; i < k; ++i) {
          cout << us[i] + 1 << " ";
        } 
        cout << "\n";
        return;
      }
    }
    used[v] = true;
    sz.erase(sz.begin());
    for (auto u: g[v]) {
      if (!used[u]) {
        sz.erase({siz[u], u});
        --siz[u];
        sz.insert({siz[u], u});
      }
    }
  }
  cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}