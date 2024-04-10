#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 100005;

ll a[N], pref[N], n, m, k;

double ans = 0;

double check(int x) {
	if (x > m) return 0;
	int u = min((n - x) * k, m - x);
	return (double) (pref[n] - pref[x] + u) / (n - x); 
}

int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, check(i));
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
/* 
g++ online.cpp -o online.exe
*/