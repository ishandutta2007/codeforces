#pragma warning(disable:4996)
#include<stdio.h>
int n, w[310], i, j, S;
int main(){
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	while (1){
		S = 0;
		for (i = 1; i <= n; i++)S += w[i];
		if (!S)break;
		for (i = 2; i <= n; i++){
			printf("R");
			if (w[i]){
				printf("P");
				w[i]--;
			}
		}
		for (i = n - 1; i >= 1; i--){
			printf("L");
			if (w[i]){
				printf("P");
				w[i]--;
			}
		}
	}
	return 0;
}