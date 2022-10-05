#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> a;
 
void solve() {
	cin >> n;
	a.resize(n);
	int ans = 0;
	for (auto &i : a) {
		cin >> i;
		ans += (i - 1) / (2 * a[0] - 1);
	}
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}