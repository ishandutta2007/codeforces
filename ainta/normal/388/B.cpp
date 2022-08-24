#include<stdio.h>
int w[92][92], k, i, j;
void make(int a, int b){
	w[a][b] = w[b][a] = 1;
}
int main(){
	scanf("%d", &k);
	for (i = 2; i < 31; i++){
		make(i, i + 1);
		make(i + 30, i + 31);
		make(i + 30, i + 61);
		make(i + 60, i + 31);
		make(i + 60, i + 61);
	}
	make(0, 31); make(1, 32); make(1, 62);
	if (k & 1)k ^= 1, make(2, 1);
	for (i = 1; i < 31; i++){
		if (k&(1 << i))make((1 + i) % 31 + 1, 31 + i), make((1 + i) % 32 + 1, 61 + i);
	}
	printf("92\n");
	for (i = 0; i < 92; i++){
		for (j = 0; j < 92; j++){
			printf(w[i][j] ? "Y" : "N");
		}
		printf("\n");
	}
	return 0;
}