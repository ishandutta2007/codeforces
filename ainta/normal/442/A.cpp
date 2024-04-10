#pragma warning(disable:4996)
#include<stdio.h>
char p[110][5];
char pp[6] = "RGBYW";
int n, C[110];
int main()
{
	int i, j, k, c, Res = 10, chk;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", p[i]);
	}
	for (i = 0; i < (1 << 10); i++){
		for (j = 0; j < n; j++)C[j] = 0;
		c = 0;
		for (j = 0; j < 10; j++){
			if (i&(1 << j))c++;
		}
		for (j = 0; j < 5; j++){
			if (i&(1 << j)){
				for (k = 0; k < n; k++){
					if (pp[j] == p[k][0]){
						C[k] += (1 << j);
					}
				}
			}
		}
		for (j = 5; j < 10; j++){
			if (i&(1 << j)){
				for (k = 0; k < n; k++){
					if (j - 5 + '1' == p[k][1]){
						C[k] += (1 << j);
					}
				}
			}
		}
		chk = 0;
		for (j = 0; j < n; j++){
			for (k = j + 1; k < n; k++){
				if (C[j] == C[k] && (p[j][0] != p[k][0] || p[j][1] != p[k][1]))chk = 1;
			}
		}
		if (!chk && Res > c)Res = c;
	}
	printf("%d\n", Res);
}