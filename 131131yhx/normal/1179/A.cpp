#include <bits/stdc++.h>
#define M 100010
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long ll;

int n, q;

int A[M * 5], l, r;

PII Ans[M * 5];

int main() {
	scanf("%d%d", &n, &q);
	l = 1, r = n;
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	int t = 0;
	int mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, A[i]);
	while(A[l] != mx) {
		Ans[++t] = PII(A[l], A[l + 1]);
		l++, r++;
		A[l] = max(Ans[t].x, Ans[t].y);
		A[r] = min(Ans[t].x, Ans[t].y);
	}
	t++;
	while(q--) {
		ll x;
		scanf("%lld", &x);
		if(x < t) printf("%d %d\n", Ans[x].x, Ans[x].y);
		else printf("%d %d\n", A[l], A[l + (x - t) % (n - 1) + 1]);
	}
	return 0;
}