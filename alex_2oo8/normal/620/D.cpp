#include<bits/stdc++.h>

using namespace std;

const int MX = 2000;

int n, m, a[MX], b[MX], c[MX * MX], d[MX * MX];

void solve0(long long &ans, bool w) {
	long long s = 0;
	for (int i = 0; i < n; i++) s += a[i];
	for (int i = 0; i < m; i++) s -= b[i];
	
	if (abs(s) <= ans) {
		ans = abs(s);
		
		if (w) {
			printf("%lld\n0\n", ans);
			
			exit(0);
		}
	}
}

void solve1(long long &ans, bool w) {
	long long s = 0;
	for (int i = 0; i < n; i++) s += a[i];
	for (int i = 0; i < m; i++) s -= b[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (abs(s - 2ll * a[i] + 2ll * b[j]) <= ans) {
				ans = abs(s - 2ll * a[i] + 2ll * b[j]);
				
				if (w) {
					printf("%lld\n1\n%d %d\n", ans, i + 1, j + 1);
					
					exit(0);
				}
			}
}

void solve2(long long &ans, bool w) {
	if (min(n, m) < 2) return;
	
	long long s = 0;
	for (int i = 0; i < n; i++) s += a[i];
	for (int i = 0; i < m; i++) s -= b[i];
	
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			c[k++] = a[i] + a[j];
	
	int p = 0;
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			d[p++] = b[i] + b[j];
	
	sort(c, c + k);
	sort(d, d + p);
	
	for (int i = 0, j = 0; i < k; i++) {
		while (j + 1 < p && abs(s - 2ll * c[i] + 2ll * d[j + 1]) <= abs(s - 2ll * c[i] + 2ll * d[j])) j++;
		
		if (abs(s - 2ll * c[i] + 2ll * d[j]) <= ans) {
			ans = abs(s - 2ll * c[i] + 2ll * d[j]);
			
			if (w) {
				int a1, a2, b1, b2;
				
				for (int x = 0; x < n; x++)
					for (int y = x + 1; y < n; y++)
						if (a[x] + a[y] == c[i]) {
							a1 = x + 1;
							a2 = y + 1;
						}
				
				for (int x = 0; x < m; x++)
					for (int y = x + 1; y < m; y++)
						if (b[x] + b[y] == d[j]) {
							b1 = x + 1;
							b2 = y + 1;
						}
				
				printf("%lld\n2\n%d %d\n%d %d\n", ans, a1, b1, a2, b2);
				
				exit(0);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", b + i);
	
	long long ans = (long long)(1e18);
	
	solve0(ans, false);
	solve1(ans, false);
	solve2(ans, false);
	
	solve0(ans, true);
	solve1(ans, true);
	solve2(ans, true);
	
	return 0;
}