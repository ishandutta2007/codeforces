#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(maxn, 0);
	for(int i = 0; i < n; i++) {
		int x; cin >> x; x--; a[x] = 1;
	}
	int ans = 0;
	int cur = 0;
	for(int i = 0; i < maxn; i++) {
		cur += a[i];
		if(i >= m) cur -= a[i - m];
		if(cur == k) ans++, cur--, a[i] = 0;
	}
	cout << ans;
}