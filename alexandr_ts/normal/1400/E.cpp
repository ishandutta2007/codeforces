#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 5e3 + 10;
 
int a[N];
 
int calc0(int l, int r);
 
int calc(int l, int r) {
	if (l > r) return 0;
	int mn = INF, cnt = 0;
	for (int i = l; i <= r; ++i) {
		if (a[i] < mn) {
			mn = a[i], cnt = 1;
		} else if (a[i] == mn) {
			++cnt;
		}
	}
 
	int ans = (r - l + 1);
	for (int i = l; i <= r; ++i) {
		a[i] -= mn;
	}
	return min(ans, calc0(l, r) + mn);
}
 
int calc0(int l, int r) {
	int ans = 0;
	while (a[l] == 0 && l <= r) {
		++l;
	}
	while (a[r] == 0 && r >= l) {
		--r;
	}
	if (l > r) return 0;
	int prv = -1;
	for (int i = l; i <= r; ++i) {
		if (a[i] && (i == l || !a[i - 1])) prv = i;
		if (a[i] && (i == r || !a[i + 1])) {
			ans += calc(prv, i);
		}
	}
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << calc0(0, n - 1) << endl;	
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}