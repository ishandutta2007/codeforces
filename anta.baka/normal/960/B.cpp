#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e5;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k1, k2; cin >> n >> k1 >> k2;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	multiset<int> setik;
	for(int i = 0; i < n; i++) setik.insert(abs(a[i] - b[i]));
	for(int i = 0; i < k1 + k2; i++) {
		int x = *--setik.end();
		setik.erase(--setik.end());
		setik.insert(abs(x - 1));
	}
	ll ans = 0;
	for(int x : setik) ans += ll(x) * x;
	cout << ans;
}