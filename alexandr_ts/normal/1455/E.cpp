#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e15;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e5 + 10;

struct Pt {
  ll x, y;
};

ll seg_dist(ll l1, ll r1, ll l2, ll r2) {
  if (l1 >= r2) return l1 - r2;
  if (l2 >= r1) return l2 - r1;
  return 0;
}

ll calc(const vector<Pt>& a) {
  ll l_x_01 = min(a[0].x, a[1].x);
  ll r_x_01 = max(a[0].x, a[1].x);
  ll l_x_23 = min(a[2].x, a[3].x);
  ll r_x_23 = max(a[2].x, a[3].x);


  ll answer = abs(a[0].x - a[1].x) + abs(a[2].x - a[3].x);

  ll max_x = max(r_x_01 - l_x_23, r_x_23 - l_x_01);
  ll min_x = seg_dist(l_x_01, r_x_01, l_x_23, r_x_23);

  ll l_y_03 = min(a[0].y, a[3].y);
  ll r_y_03 = max(a[0].y, a[3].y);
  ll l_y_12 = min(a[1].y, a[2].y);
  ll r_y_12 = max(a[1].y, a[2].y);

  answer += abs(a[0].y - a[3].y) + abs(a[1].y - a[2].y);

  ll max_y = max(r_y_03 - l_y_12, r_y_12 - l_y_03);
  ll min_y = seg_dist(l_y_03, r_y_03, l_y_12, r_y_12);

  ll xy_dist = seg_dist(min_x, max_x, min_y, max_y);
  answer += xy_dist * 2;
  return answer;
}

void solve() {
  vector<Pt> a(4), b(4);
  for (int i = 0; i < 4; ++i) {
    cin >> b[i].x >> b[i].y;
  }

  vector<int> perm{0, 1, 2, 3};

  ll ans = INF;
  do {
    for (int i = 0; i < 4; ++i) {
      a[i] = b[perm[i]];
    }
    ans = min(ans, calc(a));
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans << "\n";
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