#include<bits/stdc++.h>

#define left ololo
#define right olololo

using namespace std;

const int MX = 200000, INF = 1000000000;

int a[MX], left[MX], right[MX];

int main() {
	int n, m, last;
	scanf("%d %d %d", &n, &m, &last);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		a[i] = abs(x - last);
		
		last = x;
	}
	
	a[0] = a[n] = INF;
	left[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (a[i] > a[j]) j = left[j];
		
		left[i] = j;
	}
	
	right[n] = n;
	for (int i = n - 1; i > 0; i--) {
		int j = i + 1;
		while (a[i] >= a[j]) j = right[j];
		
		right[i] = j;
	}
	
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		
		long long ans = 0;
		for (int i = l; i < r; i++) ans += a[i] * 1LL * (min(right[i], r) - i) * 1LL * (i - max(left[i], l - 1));
		
		printf("%I64d\n", ans);
	}
	
	return 0;
}