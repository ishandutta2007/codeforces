#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int a[MAXN];

int calc(int t) {
	int res = 0;
	for (int i = 0; i < N; i++) 
		if (a[i] != t)
			res += abs(a[i] - t) - 1;
	return res;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	int opt = 0, ans = 1e9;
	for (int i = 1; i <= 100; i++) {
		int cand = calc(i);
		if (cand < ans) {
			ans = cand;
			opt = i;
		}
	}
	
	printf("%d %d\n", opt, ans);
	
	return 0;
}