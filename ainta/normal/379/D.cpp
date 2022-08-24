#pragma warning(disable:4996)
#include<stdio.h>
int k, n, m, ck;
long long w[110][2], x, t, P[110][3];
void Print(long long a, long long b){
	long long i;
	for (i = 1; i <= b; i++){
		printf("AC");
	}
	for (i = b * 2 + 1; i <= a; i++){
		printf("Z");
	}
}
int main()
{
	long long i, j, a, b;
	scanf("%d%lld%d%d", &k, &x, &n, &m);
	w[1][0] = 1, w[2][1] = 1;
	for (i = 3; i <= k; i++){
		w[i][0] = w[i - 1][0] + w[i - 2][0];
		w[i][1] = w[i - 1][1] + w[i - 2][1];
		P[i][0] = P[i - 1][0] + P[i - 2][0];
		P[i][1] = P[i - 1][1] + P[i - 2][1];
		P[i][2] = P[i - 1][2] + P[i - 2][2];
		if (i == 3)P[i][0]++;
		else if (i % 2 == 0)P[i][1]++;
		else P[i][2]++;
	}
	for (i = 0; i <= n / 2; i++){
		for (j = 0; j <= m / 2; j++){
			if (i * w[k][0] + j * w[k][1] > x)break;
			t = x - w[k][0] * i - w[k][1] * j;
			if (t == 0){
				ck = 1;
				Print(n, i);
				printf("\n");
				Print(m, j);
				break;
			}
			a = n - i * 2, b = m - j * 2;
			if (t == w[k][0]+w[k][1]-1 && a >= 2 && b >= 2){
				printf("C");
				Print(n - 2, i);
				printf("A");
				printf("\n");
				printf("C");
				Print(m - 2, j);
				printf("A");
				ck = 1;
				break;
			}
			if (t == P[k][0] && a && b){
				Print(n - 1, i);
				printf("A");
				printf("\n");
				printf("C");
				Print(m - 1, j);
				ck = 1;
				break;
			}
			if (t == P[k][1] && a && b){
				printf("C");
				Print(n - 1, i);
				printf("\n");
				Print(m - 1, j);
				printf("A");
				ck = 1;
				break;
			}
			if (t == P[k][2] && b >= 2){
				Print(n, i);
				printf("\n");
				printf("C");
				Print(m - 2, j);
				printf("A");
				ck = 1;
				break;
			}
			if (t == P[k][0] + P[k][2] && b >= 2 && a){
				Print(n - 1, i);
				printf("A");
				printf("\n");
				printf("C");
				Print(m - 2, j);
				printf("A");
				ck = 1;
				break;
			}
			if (t == P[k][1] + P[k][2] && b >= 2 && a){
				printf("C");
				Print(n - 1, i);
				printf("\n");
				printf("C");
				Print(m - 2, j);
				printf("A");
				ck = 1;
				break;
			}
		}
		if (ck)break;
	}
	if (!ck){
		printf("Happy new year!\n");
	}
	return 0;
}