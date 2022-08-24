#pragma warning(disable:4996)
#include<stdio.h>
bool E[19][19];
int n, m;
long long D[19][524288], Res;
int main()
{
	int a, b, i, j, k, c;
	scanf("%d%d", &n, &m);
	while (m--){
		scanf("%d%d", &a, &b);
		a--, b--;
		E[a][b] = E[b][a] = true;
	}
	m = 1 << n;
	for (i = 0; i < n - 2; i++){
		D[i][1 << i] = 1;
	}
	for (i = 1; i < m; i++){
		c = 0;
		for (j = n - 1; j >= 0; j--)if ((1 << j)&i)c++, a = j;
		for (j = a; j < n; j++){
			if (!((1 << j)&i))continue;
			if (E[j][a] && c>=3)Res += D[j][i];
			for (k = a + 1; k < n; k++){
				if ((1 << k)&i)continue;
				if (E[j][k])D[k][i + (1 << k)] += D[j][i];
			}
		}
	}
	printf("%lld\n", Res / 2);
}