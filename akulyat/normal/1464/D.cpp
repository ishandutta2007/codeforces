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
vector<ll> p;
bool viv = false;
vector<ll> d;

void work(int pl, int &len) {
	d[pl] = 1;
	len++;
	if (d[p[pl]] != -1)
		return;
	work(p[pl], len);
}

ll beat(vector<ll> c) {
	ll cnt1 = 0, cnt2 = 0;
	ll res = 0;
	while (c.size()) {
		ll v = c.back();
		c.pop_back();
		while (v > 3)
			res++, v -= 3;
		if (v == 1)
			cnt1++;
		if (v == 2)
			cnt2++;
	}
	while (cnt1 && cnt2)
		res++, cnt1--, cnt2--;
	while (cnt2 >= 3)
		res += 3, cnt2 -= 3;
	while (cnt1 >= 3)
		res += 2, cnt1 -= 3;
	if (cnt1 == 2)
		res++, cnt1 -= 2, cnt2++;

	if (cnt1 == 1 && cnt2 == 0)
		return mod;
	return res;
}

ll beat2(vector<ll> c) {
	ll cnt1 = 0, cnt2 = 0;
	ll res = 0;
	bool need = true;
	while (c.size()) {
		ll v = c.back();
		c.pop_back();
		while (v > 3 && (v != 4 || !need)) {
			res++, v -= 3;
		}
		if (v == 4)
			need = false;
		if (v == 1)
			cnt1++;
		if (v == 2)
			cnt2++;
	}
	if (need) {
		if (cnt2 >= 2)
			cnt2 -= 2; 
		else {
			if (cnt2 >= 1 && cnt1 >= 2) {
				res++;
				cnt2 -= 1;
				cnt1 -= 2;
			} else {
				if (cnt1 >= 4) {
					res += 2;
					cnt1 -= 4;
				}
			}
		}
	}
	while (cnt1 && cnt2)
		res++, cnt1--, cnt2--;
	while (cnt2 >= 3)
		res += 3, cnt2 -= 3;
	while (cnt1 >= 3)
		res += 2, cnt1 -= 3;
	if (cnt1 == 2)
		res++, cnt1 -= 2, cnt2++;

	if (cnt1 == 1)
		res += 1;
	return res;
}

void solve() {
	cin >> n;
	p.resize(n);
	for (auto &i : p)
		cin >> i, i--;

	ll fn = n;
	ll ans = 1;
	ll cnt = 0;
	while (fn % 3)
		ans *= 2, fn -= 2, cnt++;
	while (fn){
		ans *= 3, fn -= 3;				
		ans %= mod;
	}

	bool need_4 = (cnt == 2);


	d.assign(n, -1);
	vector<ll> c;
	for (int i = 0; i < n; i++) 
		if (d[i] == -1) {
			int len = 0;
			work(i, len);
			c.push_back(len);
		}
	if (viv) {
		cout << "\t\tc = ";
		for (auto i : c) {
			cout << i << ' ';
		}
		cout << endl;
	}
	sort(c.begin(), c.end());
	ll ans1 = beat(c);
	ll ans2 = mod;
	if (n % 3 == 1)
		ans2 = beat2(c);
	ll ans3 = min(ans1, ans2);
	cout << ans << ' ' << ans3 << '\n';
	if (viv)
		cout << "\t\t was " << ans1 << ' ' << ans2 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}