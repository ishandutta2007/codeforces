#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];
unordered_set<long long> S;

bool can(int c, int n) {
	if (c == 0) return true;
	
	long long st = ((long long)(c) << 20) + n;
	if (S.count(st) == 1) return true;
	
	while (n > 0 && a[n - 1] > c) n--;
	
	if (n == 0) return false;
	
	if (can(c - a[n - 1], n - 1)) {
		S.insert(st);
		
		return true;
	}
	
	return false;
}

int f[MX];

int main() {
	int c, n;
	scanf("%d %d", &c, &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	sort(a, a + n);

	long long r = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > r + 1) break;
		
		r += a[i];
	}
	
	if (c - a[n - 1] <= r) printf("Greed is good\n");
	else {
		for (int i = n - 1, C = c; i >= 0; i--)
			if (C >= a[i]) {
				if (a[i] < C) {
					f[a[i] + 1]++;
					f[C]--;
				}
				
				C -= a[i];
			}
		
		int ans;
		for (ans = 2; f[ans] == 0 || can(c - ans, n); ans++) f[ans + 1] += f[ans];
		
		printf("%d\n", ans);
	}
	
	return 0;
}