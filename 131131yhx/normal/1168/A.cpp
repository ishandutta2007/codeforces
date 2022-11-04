#include <bits/stdc++.h>

using namespace std;

int n, m;

int A[300010];

bool check(int x) {
	int nw = 0;
	for(int i = 1; i <= n; i++) {
		if(A[i] + x < m) {
			if(A[i] + x < nw) return 0;
			if(A[i] >= nw) nw = A[i];
		} else {
			int a = (A[i] + x) % m;
			if(a < nw && nw <= A[i]) nw = A[i];
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	int ans = m - 1;
	for(int l = 0, r = m - 1; l <= r; ) {
		int md = (l + r) / 2;
		if(check(md)) ans = md, r = md - 1; else l = md + 1;
	}
	printf("%d\n", ans);
	return 0;
}