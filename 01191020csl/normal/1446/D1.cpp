#include<bits/stdc++.h>
using namespace std;
int a[200001], cnt[200001];
int p[200001];
int res[400001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], ++cnt[a[i]];
	int num, maxn = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[i] > maxn) num = i, maxn = cnt[i];
		else if (cnt[i] == maxn) num = -1;
	if (num == -1) {
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for (int k = 1; k <= 100; k++)
		if (k != num && cnt[k]) {
			for (int i = 1; i <= n; i++) {
				p[i] = p[i-1];
				if (a[i] == num) ++p[i];
				if (a[i] == k) --p[i];
			}
			memset(res, 0x3f, sizeof(res));
			for (int i = 0; i <= n; i++) {
				int &x = res[n+p[i]];
				if (x <= n) ans = max(ans, i-x);
				else x = i;
			}
		}
	cout << ans << endl;
}