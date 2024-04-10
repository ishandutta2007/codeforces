#include<bits/stdc++.h>
using namespace std;
bitset<500> f[501], tmp;
int a[501], b[501];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) tmp[i] = 1;
	long long sa = 0, sb = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], sa += a[i], sb += b[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (f[i-1]<<a[i]%k)|(f[i-1]>>k-a[i]%k);
		for (int j = 1; j < k; j++)
			if (j <= a[i] && k - j <= b[i])
				f[i] |= (f[i-1]<<(a[i]-j)%k)|(f[i-1]>>k-(a[i]-j)%k);
		f[i] &= tmp;
	}
	long long ans = 0;
	for (int i = 0; i < k; i++)
		if (f[n][i]) {
			int tmp = (sa+sb-i+k)%k;
			ans = max(ans, (sa+sb-i-tmp)/k);
		}
	cout << ans << endl;
}