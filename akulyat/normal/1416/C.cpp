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
ll ans, inv;
vector<ll> v;
vector<ll> cnt;
vector<ll> have;
bool viv = false;

void work(vector<ll> &v, ll b) {
	if (v.empty() || b == -1)
		return;
	vector<ll> z, o;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] & (1 << b)) {
			o.push_back(v[i]);
		}
		else {
			z.push_back(v[i]);
			cnt[b] += o.size();
		}
	}
	have[b] += ((ll)z.size()) * o.size();
	if (viv) {
		cout << "o = ";
		for (auto i : o)
			cout << i << ' ';
		cout << endl;
		cout << "z = ";
		for (auto i : z)
			cout << i << ' ';
		cout << endl;
	}	
	work(o, b - 1);
	work(z, b - 1);
}

void solve() {
	cin >> n;
	v.resize(n);
	cnt.resize(32);
	have.resize(32);
	for (auto &i : v)
		cin >> i;
	work(v, 30);


	for (int i = 0; i < 32; i++) {
		if (viv)
			cout << cnt[i] << ' ' << have[i] << endl;
		if (cnt[i] * 2 > have[i])
			ans += (1 << i), cnt[i] = have[i] -= cnt[i];
		inv += cnt[i];
	}
	cout << inv << ' ' << ans << '\n';
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