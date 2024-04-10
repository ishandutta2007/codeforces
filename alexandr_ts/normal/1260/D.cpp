#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int solder[N];

struct Obs {
  int l, r, d;
} a[N];

ll calc(int weak_solder, int n, int k) {
  ll ans = n + 1;
  vector<pair<int, int>> events;
  for (int i = 0; i < k; ++i) {
    if (a[i].d > weak_solder) {
      events.push_back({a[i].l, 1});
      events.push_back({a[i].r, -1});
    }
  }
  sort(events.begin(), events.end());

  int bal = 0;
  int last_l = 0;
  for (auto [x, type]: events) {
    if (bal == 0 && type == 1) {
      last_l = x;
    }
    if (bal == 1 && type == -1) {
      ans += 2 * (x - last_l);
    }
    bal += type;
  }
  return ans;
}

void solve() {
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  for (int i = 0; i < m; ++i) {
    cin >> solder[i];
  }
  sort(solder, solder + m, greater<int>());

  for (int i = 0; i < k; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].d;
    a[i].l--;
  } 

  int tl = -1, tr = m;
  while (tr - tl > 1) {
    int tm = (tl + tr) / 2;
    if (calc(solder[tm], n, k) <= t) {
      tl = tm;
    } else {
      tr = tm;
    }
  }
  cout << tl + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}