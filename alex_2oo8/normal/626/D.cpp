#include<bits/stdc++.h>

using namespace std;

const int MX = 5001;

int cnt[MX], d[MX];
long long f[MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		cnt[x]++;
	}
	
	for (int i = 0; i < MX; i++)
		for (int j = i + 1; j < MX; j++)
			d[j - i] += cnt[j] * cnt[i];
	
	for (int i = 1; i < MX; i++)
		for (int j = 1; i + j < MX; j++)
			f[i + j] += d[i] * 1ll * d[j];
	
	long double ans = 0.0, s = 0.0;
	for (int i = 0; i < MX; i++) {
		ans += d[i] * s;
		s += f[i];
	}
	
	for (int i = 0; i < 3; i++) ans /= n * (n - 1) / 2;
	
	printf("%.12f\n", (double)ans);
	
	return 0;
}