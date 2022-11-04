#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

int n, m;

PII X[100010];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= 4 * n + 1; i++) scanf("%d%d", &X[i].x, &X[i].y);
	for(int T = 1; T <= 4 * n + 1; T++) {
		int mx1 = -1e9, mn1 = 1e9, mx2 = -1e9, mn2 = 1e9;
		for(int i = 1; i <= 4 * n + 1; i++) if(i != T)
		mx1 = max(mx1, X[i].x), mn1 = min(mn1, X[i].x), mx2 = max(X[i].y, mx2), mn2 = min(X[i].y, mn2);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, flag = 1;
		for(int i = 1; i <= 4 * n + 1; i++) if(i != T) {
			cnt1 += X[i].x == mx1, cnt2 += X[i].x == mn1, cnt3 += X[i].y == mx2, cnt4 += X[i].y == mn2;
			if(X[i].x != mx1 && X[i].x != mn1 && X[i].y != mx2 && X[i].y != mn2) flag = 0;
		}
		if(flag && ((X[T].x != mx1 && X[T].x != mn1 && X[T].y != mx2 && X[T].y != mn2) || !(mn1 <= X[T].x && X[T].x <= mx1 && mn2 <= X[T].y && X[T].y <= mx2)) && cnt1 >= n && cnt2 >= n && cnt3 >= n && cnt4 >= n) {
			printf("%d %d\n", X[T].x, X[T].y);
			return 0;
		}
	}
	return 0;
}