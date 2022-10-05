#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<ll> v, ans;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.resize(m + 1, -1);
	ans.resize(m + 1, -1);
	ans[0] = v[0] = 0;
	for (int st = 0; st < n; st++) {
		if (viv) {
			cout << "\tv: ";
			for (auto i : v)
				cout << i << ' ';
			cout << endl;
			cout << "\tans: ";
			for (auto i : ans)
				cout << i << ' ';
			cout << endl;
		}
		ll ti, xib, yi;
		cin >> ti >> xib >> yi;

		for (int i = 0; i <= m; i++) {
			if (v[i] != -1 && v[i] != yi) {
				ll pl = m + 1;
				if (ti == 1) {
					ll val = i;
					ll add = xib / (100 * kk);
					add += (xib % (100 * kk)) != 0;
					val += add;
					pl = val;
				} else {
					ll val = i;
					ll mul = xib;
					val *= mul;
					int add = val % (100 * kk) != 0;
					val /= (100 * kk);
					val += add;
					pl = val;
				}
 				if (pl <= m) {
					if (v[pl] == -1)
						v[pl] = v[i] + 1;
					else
						v[pl] = min(v[pl], v[i] + 1);
				}
			}
		}

		for (int i = 0; i <= m; i++)
			if (ans[i] == -1 && v[i] != -1)
				ans[i] = st + 1;
		for (auto &i : v)
			if (i != -1)
				i = 0;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}