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
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum[n + 1], total[n + 1];
	sum[0] = total[0] = 0;
	for(int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + a[i];
		total[i + 1] = sum[i + 1];
		if(i + 1 >= m) {
			total[i + 1] += total[i + 1 - m];
		}
		cout << total[i + 1] << " ";
	}
	return 0;
}