#include <bits/stdc++.h>
#define M 600010
#define PII pair <int, int>

using namespace std;

int n;

int A[M], B[M];

int ans1, Ans1[M], ans2, Ans2[M];

int tmp[M];

bool cmp(int x, int y) {
	return A[x] > B[y];
}

void Do(int &ans, int *Ans) {
	int t = 0;
	for(int i = 1; i <= n; i++) if(A[i] < B[i]) tmp[++t] = i;
	sort(tmp + 1, tmp + t + 1, cmp); //???
	ans = t;
	for(int i = 1; i <= t; i++) Ans[i] = tmp[i];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	Do(ans1, Ans1);
	for(int i = 1; i <= n; i++) swap(A[i], B[i]);
	Do(ans2, Ans2);
	if(ans1 > ans2) {
		printf("%d\n", ans1);
		for(int i = 1; i <= ans1; i++) printf("%d ", Ans1[i]);
	} else {
		printf("%d\n", ans2);
		for(int i = ans2; i >= 1; i--) printf("%d ", Ans2[i]);
	}
	return 0;
}