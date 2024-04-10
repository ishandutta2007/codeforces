#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
 
ll n, k, cnt, cnt2;
vector<ll> m;
vector<ll> dif;
vector<vector<ll>> v;
bool viv = false;

bool ask(ll v) {
	if (cnt >= (4 * n * n) / (2 * k)) {
		return false;
	}
	cout << "? " << v + 1 << endl;
	string s;
	cin >> s;
	cnt++;
	return s[0] == 'Y';
}

void forg(ll num) {
	for (ll i = 0; i < k - v[num].size(); i++)
		ask(v[num][0]);
}

void forget(ll num = -1) {
	if (cnt2 >= 30000) {
		forg(num);
		return;
	}
	cout << "R" << endl;
	cnt2++;
}

void prepare() {
	v.resize(n / k);
	for (ll i = 0; i < n; i++)
		v[i / k].push_back(i);
}


void shorter() {
	for (ll i = 0; i < v.size(); i++) {
		vector<ll> u;
		for (auto s : v[i]) {
			auto ver = ask(s);
			if (!ver)
				u.push_back(s);
		}
		v[i] = u;
	}
	forget();
}


void s2(ll num) {
	for (ll i = 0; i < num; i++) 
		if (v[num].size() && v[i].size()) {		
			vector<ll> vi, vnum;
			forget(i);
			for (auto val : v[i])			
				ask(val);
			for (auto val : v[num]) {
				auto res = ask(val);
				if (!res || val == v[num].back() && v[num].size() > 1)
					vnum.push_back(val);
			}
			if (v[num].size() > 1) {
				for (ll j = 0; j < k + 1 - v[num].size(); j++)
					ask(v[num].back());
				for (ll j = 0; j < k - v[i].size(); j++)
					ask(v[num].back());

				for (auto val : v[i]) {
					auto res = ask(val);
					if (!res)
						vi.push_back(val);
				}
				v[i] = vi;
			}

			v[num] = vnum;
		}
}

void solve() {
	cin >> n >> k;
	prepare();
	shorter();
	for (ll i = 0; i < n / k; i++)
		s2(i);

	ll ans = 0;
	for (ll i = 0; i < n / k; i++)
		ans += v[i].size();
	cout << "! " << ans << endl;
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}