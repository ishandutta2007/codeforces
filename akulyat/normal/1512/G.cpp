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

ll n;
vector<ll> v;
vector<ll> pans;
bool viv = false;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	vector<ll> mn(last + 1, mod);

	for (int i = 2; i <= last; i++) {
		if (prime[i]) {
			res.push_back(i);
			mn[i] = i;
		}
		if ((ll)i * i <= last)
			for (int j = i * i; j <= last; j += i) {
				mn[j] = min(mn[j], (ll)i);
				prime[j] = false;
			}
	}
	vector<ll> ans(last + 1, 1);
	pans[1] = 1;
	for (int i = 2; i <= last; i++) {
		if (i <= 10 && viv)
			cout << "see: " << i << ' ' << mn[i] << endl;
		assert(mn[i] != mod);
		assert(!(i % mn[i]));
		ans[i] = ans[i / mn[i]];
		if ((i / mn[i]) % mn[i])
			ans[i] *= (mn[i] + 1);
		else {
			ans[i] += (ans[i] - ans[(i / mn[i]) / mn[i]]) * mn[i];
		}
		if (ans[i] < pans.size())
			pans[ans[i]] = min(pans[ans[i]], (ll)i);
		if (i <= 10 && viv) 
			cout << "\t\tans: " << i << ' ' << ans[i] << '\n';
	}
	return res;
}


void prepare() {
	pans.resize(10 * ml + 3, mod);
	erat(10 * ml + kk);
	for (auto &i : pans)
		if (i == mod)
			i = -1;
}


void solve() {
	int k;
	cin >> k;
	cout << pans[k] << '\n';
}


int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}