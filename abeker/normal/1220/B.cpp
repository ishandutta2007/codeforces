#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;

int N;
ll mat[MAXN][MAXN];
ll a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%lld", mat[i] + j);
	
	ll prod = round(sqrt(mat[0][1] * mat[0][2]) * sqrt(mat[1][2]));	
	a[0] = prod / mat[1][2];
	a[1] = prod / mat[0][2];
	a[2] = prod / mat[0][1];
	
	for (int i = 3; i < N; i++)
		a[i] = mat[0][i] / a[0];
	
	for (int i = 0; i < N; i++)
		printf("%lld ", a[i]);
	puts("");
	
	return 0;
}