#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N], b[N];

struct Seg {
  int l, r;
  int max_bord;
};

ll calc(const Seg& s, ll x, ll k, ll y) {
  vector<int> v{a + s.l, a + s.r + 1};
  ll ans = 0;
  ll mx = *max_element(v.begin(), v.end());
  if (v.size() < k && mx > s.max_bord) {
    return -1;
  }

  ans = (v.size() % k) * y;

  if (x <= k * y) {
    ans += v.size() / k * x;
  } else {
    if (mx < s.max_bord) {
      ans += (v.size() / k * k) * y;
    } else {
      ans += x + (v.size() / k * k - k) * y;
    }
  }
  return ans;
}

void solve() {
  int n, m;
  ll x, k, y;
  cin >> n >> m;
  cin >> x >> k >> y;
  map<int, int> pos;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  vector<int> poses;
  bool ok = true;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    if (!pos.count(b[i])) ok = false;
    poses.push_back(pos[b[i]]);
  }
  for (int i = 0; i + 1 < poses.size(); ++i) {
    if (poses[i] > poses[i + 1]) {
      ok = false;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return;
  }

  vector<Seg> segs; 
  for (int i = 0; i + 1 < poses.size(); ++i) {
    if (poses[i] + 1 != poses[i + 1]) {
      segs.push_back(Seg{poses[i] + 1, poses[i + 1] - 1, max(a[poses[i]], a[poses[i + 1]])});
    }
  }

  if (poses[0] > 0) {
    segs.push_back(Seg{0, poses[0] - 1, a[poses[0]]});
  }
  if (poses.back() < n - 1) {
    segs.push_back(Seg{poses.back() + 1, n - 1, a[poses.back()]});
  }

  ll ans = 0;
  for (auto& seg: segs) {
    auto tmp = calc(seg, x, k, y);
    if (tmp == -1) {
      cout << -1 << endl;
      return;
    }
    ans += tmp;
  }
  cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}