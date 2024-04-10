#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[201], P[4][201], Res = 9999999;
bool E[201][201], v[201];
void Do(int x){
	int i, j, k, ck, c = n;
	for (i = 1; i <= n; i++)v[i] = false;
	while (1){
		while (1){
			ck = 0;
			for (i = 1; i <= n; i++){
				if (v[i] || w[i] != x)continue;
				for (j = 1; j <= n; j++){
					if (!v[j] && E[j][i])break;
				}
				if (j == n + 1){
					v[i] = true;
					ck = 1;
				}
			}
			if (!ck)break;
		}
		for (i = 1; i <= n; i++)if (!v[i])break;
		if (i == n + 1)break;
		c++;
		x = x % 3 + 1;
	}
	if (Res > c)Res = c;
}
int main()
{
	int i, c, a, x;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &c);
		while (c--){
			scanf("%d", &a);
			E[a][i] = true;
		}
	}
	Do(1);
	Do(2);
	Do(3);
	printf("%d\n", Res);
}