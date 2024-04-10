#include<stdio.h>
#include<algorithm>
using namespace std;
double D[6][5], Res;
int n, w[6][2], i, j, b, e;
double inv(int a){
	return 1.0 / a;
}
int main(){
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &w[i][0], &w[i][1]);
	}
	for (i = 1; i <= 10000; i++){
		for (j = 0; j <= n; j++){
			D[j][0] = D[j][1] = D[j][2] = D[j][3] = D[j][4] = 0.0;
		}
		D[0][0] = 1.0;
		for (j = 1; j <= n; j++){
			b = w[j][0], e = w[j][1];
			if (b <= i && i <= e)D[j][1] += D[j - 1][0] * inv(e - b + 1);
			if (i < e)D[j][2] += D[j - 1][0] * inv(e - b + 1) * (e - max(i + 1, b) + 1);
			if (b < i)D[j][0] += D[j - 1][0] * inv(e - b + 1) * (min(i - 1, e) - b + 1);

			if (b <= i && i <= e)D[j][4] += D[j - 1][1] * inv(e - b + 1);
			if (i < e)D[j][3] += D[j - 1][1] * inv(e - b + 1) * (e - max(i + 1, b) + 1);
			if (b < i)D[j][1] += D[j - 1][1] * inv(e - b + 1) * (min(i - 1, e) - b + 1);

			if (b <= i && i <= e)D[j][3] += D[j - 1][2] * inv(e - b + 1);
			if (b < i)D[j][2] += D[j - 1][2] * inv(e - b + 1) * (min(i - 1, e) - b + 1);

			if (b <= i)D[j][3] += D[j - 1][3] * inv(e - b + 1) * (min(i, e) - b + 1);

			if (b <= i)D[j][4] += D[j - 1][4] * inv(e - b + 1) * (min(i, e) - b + 1);
			if (i < e)D[j][3] += D[j - 1][4] * inv(e - b + 1) * (e - max(i + 1, b) + 1);
		}
		Res += (D[n][3] + D[n][4]) * i;
	}
	printf("%.11lf\n", Res);
}