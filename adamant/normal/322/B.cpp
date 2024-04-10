#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 2e5 + 42;
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, g, b;
	cin >> r >> g >> b;
	int ans = 0;
	int t = min({r, g, b});
	ans = max(ans, r / 3 + g / 3 + b / 3);
	if(t >= 1) ans = max(ans, (r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3 + 1);
	if(t >= 2) ans = max(ans, (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3 + 2);
	if(t >= 3) ans = max(ans, (r - 3) / 3 + (g - 3) / 3 + (b - 3) / 3 + 3);
	cout << ans << endl;
	return 0;
}