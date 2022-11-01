#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i) a[i] += a[i - 1];
	}
	ll pos = 0, sub = 0;
	while(q--) {
		ll k; cin >> k;
		if(a[n - 1] - (pos ? a[pos - 1] : 0) - sub <= k) {
			pos = sub = 0;
		} else {
			int lf = pos, rg = n - 1;
			while(lf < rg) {
				int md = (lf + rg) >> 1;
				if(a[md] - (pos ? a[pos - 1] : 0) - sub > k) rg = md;
				else lf = md + 1;
			}
			sub = a[lf] - (pos ? a[pos - 1] : 0) - sub - k;
			pos = lf;
			sub = a[pos] - (pos ? a[pos - 1] : 0) - sub;
		}
		cout << n - pos << '\n';
	}
}