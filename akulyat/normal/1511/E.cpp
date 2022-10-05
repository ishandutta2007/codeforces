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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
int w = 0;
vector<string> v;
vector<ll> pp;
bool viv = false;


bool nice(int i, int j) {
	return v[i][j] == 'o';
}

ll pw(int pr) {
	if (pr > w || pr < 0)
		return 0;
	return pp[pr];
}

void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	for (auto s : v)
		for (auto i : s)
			w += (i == 'o');

	pp.resize(1, 1);
	for (int i = 1; i <= w; i++)
		pp.push_back(pp.back() * 2), pp.back() %= mod;

	vector<ll> sum(4, 0);
	for (int i = 4; i <= w; i++) {
		sum.push_back(sum.back());
		if (!(i & 1))
			sum.back() += pw(w - i);
		sum.back() %= mod;
	}

	ll ans = 0;
	for (int j = 0; j < m; j++) {
		int line = 0;
		for (int i = 0; i < n; i++) {
			if (!nice(i, j)) 
				line = 0;
			else
				line++;
			if (line >= 2) {
				ans += pp[w - 2];
				if (viv)
					cout << "add " << pp[w - 2] << endl;
				if (line & 1) {
					if (viv)
						cout << "odd " << line << " dec " << pp[w - line] << endl;
					ans -= pp[w - line];
				}
				ans -= sum[line];
				if (viv)
					cout << " dec " << sum[line] << endl;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int line = 0;
		for (int j = 0; j < m; j++) {
			if (!nice(i, j)) 
				line = 0;
			else
				line++;
			if (line >= 2) {
				ans += pp[w - 2];
				if (viv)
					cout << "add " << pp[w - 2] << endl;
				if (line & 1) {
					if (viv)
						cout << "odd " << line << " dec " << pp[w - line] << endl;
					ans -= pp[w - line];
				}
				ans -= sum[line];
				if (viv)
					cout << " dec " << sum[line] << endl;
			}
		}
	}

	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
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