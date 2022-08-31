#pragma warning(disable:4996)
#include<stdio.h>
int n, C[8], a, i;
int main(){
	scanf("%d", &n);
	for(i=0;i<n;i++){ scanf("%d", &a); C[a]++; }
	if (C[1] != n / 3 || C[4] + C[6] != n / 3 || C[2] + C[3] != n / 3 || C[3] > C[6]){
		printf("-1\n");
		return 0;
	}
	while (C[3]--){
		printf("1 3 6\n");
		C[6]--;
	}
	while (C[4]--){
		printf("1 2 4\n");
	}
	while (C[6]--){
		printf("1 2 6\n");
	}
}