#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

int n, k;
vector<ll> v;
bool viv = false;

ll val(ll v) {
	ll res = 0;
	while (v) {
		res += v % 10;
		v /= 10;
	}
	return res;
}

ll sum(ll l, ll r) {
	ll res = 0;
	for (ll i = l; i <= r; i++)
		res += val(i);
	return res;
}

ll sum(ll val) {
	return sum(val, val + k);
}

ll fr(ll b) {
	ll res = 0;
	for (int i = b; i <= b + k; i++)
		res += val(i);
	return res;
}

ll get(ll val) {
	ll res = 0;
	ll st = 1;
	int it = 0;
	while (val) {
		int d = min(val, 9ll);
		if (it == 0)
			d = min(d, 8);
		res += d * st;
		st *= 10;
		val -= d;
		it++;
	}
	return res;
}

void solve() {
	cin >> n >> k;

	vector<ll> ans;
	for (int i = 0; i < 10; i++) {
		for (int l = 0; l < 20; l++) {
			int big = max(0, (i + k - 10) + 1);
			int sm = k + 1 - big;
			ll msum = sm * 9 * l + fr(i);
			ll need = n - msum;
			if (viv) {
				cout << "with end = " << i << " and " << l << " (9) see: " << endl;
				cout << "sm = " << sm << endl;
				cout << "big = " << big << endl;
				cout << "msum = " << msum << endl;
				cout << "need = " << need << endl;
			}

			if (need >= 0 && need % (k + 1) == 0) {
				need /= (k + 1);
				ll st = get(need);
				for (int j = 0; j < l; j++)
					st *= 10, st += 9;
				st *= 10;
				st += i;
				if (sum(st) == n) {
					ans.push_back(st);
					if (viv)
						cout << "!!!!! Add " << st << endl;
				}
			}
		}
	}
	if (viv) {
		for (auto i : ans)
			cout << i << ' ';
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "________________________________" << endl;
		cout << endl;
		cout << endl;
		cout << "________________________________" << endl;
		cout << endl;
		cout << endl;
		cout << "________________________________" << endl;
		cout << endl;
		cout << endl;
		cout << "________________________________" << endl;
	}

	if (ans.size() == 0) {
		cout << -1 << '\n';
	} else {
		ll res = ans[0];
		for (auto i : ans)
			res = min(res, i);
		cout << res << '\n';
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}