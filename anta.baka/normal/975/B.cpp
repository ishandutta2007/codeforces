#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

ll go(vector<ll> a, int pos, ll x) {
	a[pos] = 0;
	for(int i = 0; i < 14; i++) a[i] += x / 14;
	x %= 14;
	for(int d = 1; d < 14 && x; d++) {
		int i = (pos + d) % 14;
		a[i]++;
		x--;
	}
	ll ret = 0;
	for(ll c : a) if(!(c & 1)) ret += c;
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<ll> a(14);
	for(int i = 0; i < 14; i++) cin >> a[i];
	ll ans = 0;
	for(int i = 0; i < 14; i++) if(a[i]) ans = max(ans, go(a, i, a[i]));
	cout << ans;
}