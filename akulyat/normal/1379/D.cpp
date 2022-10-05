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

ll n, h, m, k;
vector<ll> th, tmm;
bool viv = false;


void solve() {
	cin >> n >> h >> m >> k;
	k--;
	if (k == 0) {
		cout << 0 << ' ' << 0 << endl;
		exit(0);
	}
	th.resize(n);
	tmm.resize(n);
	for (int i = 0; i < n; i++)
		cin >> th[i] >> tmm[i], tmm[i] %= (m / 2);

	vector<ll> all;
	for (auto i : tmm)
		all.push_back(i);
	sort(all.rbegin(), all.rend());

	for (int i = 0; i < n; i++) 
		all.push_back(all[i]);

	int r = 0;
	pll ans = {n + 1, 0};
	for (int i = 0; i < n; i++) 
		if (i == n - 1 || all[i] != all[i + 1]) {
			ll go = all[i];
			ll bl = go - 1;
			ll br = go - k;
			r = max(r, i);

			while (all[r + 1] >= br && all[r + 1] <= bl || all[r + 1] - m / 2 >= br && all[r + 1] - m / 2 <= bl)
				r++;
			pll lans = {r - i, go};
			ans = min(ans, lans);

			if (viv) {
				cout << "See " << i << ' ' << r << endl;
				cout << "ban: " << bl << ' ' << br << endl;
			}
		}

	ll bl = ans.S - 1;
	ll br = ans.S - k;
	vector<ll> ban;
	for (int i = 0; i < n; i++) {
		if (tmm[i] <= bl && tmm[i] >= br || tmm[i] - m / 2 <= bl && tmm[i] - m / 2 >= br)
			ban.push_back(i);
	}
	assert(ans.F == ban.size());
	if (viv)
		cout << ans.F << ' ';
	cout << ban.size() << ' ';

	cout << ans.S << ' ';
	cout << endl;
	for (auto i : ban)
		cout << i + 1 << ' ';
	cout << endl;
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}