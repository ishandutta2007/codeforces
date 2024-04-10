#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e5;

ll l[63], r[63], tsz[63], add[63];

int get_lvl(ll x) {
	for(int i = 0; i < 63; i++)
		if(l[i] <= x && x <= r[i])
			return i;
	assert(false);
}

ll mul(ll a, ll b, ll mod) {
	if(!b) return 0;
	if(b & 1) return (a + mul(a, b - 1, mod)) % mod;
	a = mul(a, b >> 1, mod);
	return (a + a) % mod;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 0; i < 63; i++) l[i] = (1ULL << i), r[i] = (1ULL << (i + 1)) - 1, tsz[i] = r[i] - l[i] + 1;
	int q; cin >> q;
	while(q--) {
		int type;
		ll v;
		cin >> type >> v;
		int lvl = get_lvl(v);
		if(type == 1) {
			ll k; cin >> k;
			k %= tsz[lvl];
			if(k < 0) k += tsz[lvl];
			add[lvl] = (add[lvl] + k) % tsz[lvl];
		} else if(type == 2) {
			ll k; cin >> k;
			k %= tsz[lvl];
			if(k < 0) k += tsz[lvl];
			for(int i = lvl; i < 63; i++) {
				ll x = mul(1ULL << (i - lvl), k, tsz[i]);
				add[i] = (add[i] + x) % tsz[i];
			}
		} else {
			int lvl = get_lvl(v);
			v = l[lvl] + (v + add[lvl]) % tsz[lvl];
			while(v) {
				int lvl = get_lvl(v);
				ll x = v - l[lvl];
				x = (x - add[lvl] + tsz[lvl]) % tsz[lvl];
				cout << l[lvl] + x << ' ';
				v >>= 1;
			}
			cout << '\n';
		}
	}
}