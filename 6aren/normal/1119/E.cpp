#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	long long sur = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		long long u; 
		cin >> u;
		long long t = min(u / 2, sur);
		sur -= t;
		u -= t * 2;
		ans += t;
		ans += u / 3;
		sur += u % 3;
	}
	cout << ans;
	return 0;
}