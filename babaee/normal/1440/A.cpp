#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, c0, c1, h, s0 = 0, s1 = 0;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		for (char c : s) {
			if (c == '0') s0++;
			else s1++;
		}

		ll ans = c0 * s0 + c1 * s1;
		ll tans = 0;
		if (c0 > c1) {
			while (s0 > 0) {
				s0--;
				s1++;
				tans += h;
				ans = min(ans, tans + c0 * s0 + c1 * s1);
			}
		} else {
			while (s1 > 0) {
				s1--;
				s0++;
				tans += h;
				ans = min(ans, tans + c0 * s0 + c1 * s1);
			}	
		}

		cout << ans << endl;
	}	
	return 0;
}