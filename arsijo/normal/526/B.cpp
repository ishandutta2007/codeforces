/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define sqr(a) ((a) * (a))
#define si short int
#define endl "\n"
#define mod % 1743
const ld E = 1e-9;
const int MAX = 1000000;

ll ar[MAX];
ll m, k;

void update(ll pos, ll add) {
	if (pos >= k)
		return;
	if (pos >= m)
		ar[pos] += add;
	update(pos * 2, add);
	update(pos * 2 + 1, add);
}

int check(ll pos) {
	if (pos >= k)
		return -1;
	if (pos >= m)
		return ar[pos];
	return max(check(pos * 2), check(pos * 2 + 1));
}

int main() {

	ll n;
	cin >> n;
	m = pow(2, n), k = pow(2, n + 1);

	ms(ar);

	for (int i = 1; i < k; i++) {
		if (i < m) {
			ll l, r;
			cin >> l >> r;
			ar[i * 2] = ar[i] + l;
			ar[i * 2 + 1] = ar[i] + r;
		}
	}

	ll ans = 0;
	ll ma = 0;
	for(int i = m; i < k; i++)
		ma = max(ma, ar[i]);

	for (int i = 1; i < k; i++) {
		ll a = check(i);
		if (a < ma) {
			ll g = ma - a;
			ans += g;
			update(i, g);
		}
	}

	cout << ans;

}