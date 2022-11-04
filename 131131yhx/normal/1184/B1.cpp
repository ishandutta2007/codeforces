#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

int n, m;

PII X[100010];

int S[100010], tmp[100010], Ans[100010];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &S[i]);
	for(int i = 1; i <= m; i++) scanf("%d%d", &X[i].x, &X[i].y);
	sort(X + 1, X + m + 1);
	for(int i = 2; i <= m; i++) X[i].y += X[i - 1].y;
	for(int i = 1; i <= n; i++) printf("%d ", X[(lower_bound(X + 1, X + m + 1, PII(S[i] + 1, -1e9)) - X - 1)].y);
	return 0;
}