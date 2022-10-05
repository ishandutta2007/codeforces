#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	int l_2 = (n - 3) / 3;
	int ans = l_2 - 1;
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