#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
int a[MAXN], b[MAXN];
int mx[MAXN][2];
int check(int k, int n) {
	int chosen = 0;
	for (int i = 0; i < n; i++) {
		if (chosen <= b[i] && chosen+1+a[i] >= k) {
			chosen++;
		}
	}
	return chosen >= k;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int s = 0;
		int e = n;
		while (s != e) {
			int m = (s+e+1)/2;
			if (check(m, n)) s = m;
			else e = m-1;
		}
		printf("%d\n", s);
	}
}