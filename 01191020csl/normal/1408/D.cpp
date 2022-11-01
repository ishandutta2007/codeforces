#include<bits/stdc++.h>
using namespace std;
int maxn[1000001];
int a[2001], b[2001], c[2001], d[2001];
int main() {
	for (int i = 0; i <= 1000000; i++) maxn[i] = -1;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= m; i++) cin >> c[i] >> d[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] <= c[j] && b[i] <= d[j])
				maxn[c[j]-a[i]] = max(maxn[c[j]-a[i]], d[j]-b[i]);
	int ans = 1000001;
	for (int i = 1000000; i; i--) maxn[i-1] = max(maxn[i-1], maxn[i]);
	for (int i = 0; i <= 1000000; i++) ans = min(ans, maxn[i] + i + 1);
	cout << ans << endl;
}