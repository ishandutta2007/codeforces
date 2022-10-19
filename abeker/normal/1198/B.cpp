#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, Q;
int bal[MAXN];
int val[MAXN];
int suff[MAXN], lst[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", bal + i);
	
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int t, p, x;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &p, &x);
			bal[p] = x;
			lst[p] = i;
		}
		else
			scanf("%d", val + i);
	}
	
	for (int i = Q - 1; i >= 0; i--)
		suff[i] = max(val[i], suff[i + 1]);
	
	for (int i = 1; i <= N; i++)
		printf("%d ", max(bal[i], suff[lst[i]]));
	puts("");
	
	return 0;
}