#include<cstdio>
#include<algorithm>
using namespace std;
int D[1010000];
int S[1010000][10];
int Calc(int a) {
	if (a < 10)return a;
	int t = Calc(a / 10);
	if (a % 10)t *= (a % 10);
	return t;
}
int main() {
	int i, j;
	for (i = 1; i <= 1000000; i++) {
		for (j = 0; j < 10; j++)S[i][j] = S[i - 1][j];
		if (i < 10) {
			D[i] = i;
		}
		else {
			int t = Calc(i);
			D[i] = D[t];
		}
		S[i][D[i]]++;
	}
	int Q, l, r, k;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", S[r][k] - S[l - 1][k]);
	}
}