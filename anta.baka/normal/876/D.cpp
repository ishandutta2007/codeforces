#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p[300000], s, ans[300000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n; cout << 1 << ' '; s = n;
	for(int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}
	for(int i = n - 1; i >= 0; i--) {
		ans[i] = i + 1 - s;
		s = min(s, n - p[i] - 1);
	}
	for(int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}