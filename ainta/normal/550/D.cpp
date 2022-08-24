#include<stdio.h>
int K, w[10100][2], cnt, deg[210];
bool v[210][210];
void Add(int a, int b){
	cnt++;
	w[cnt][0] = a; w[cnt][1] = b;
}
void Do(){
	int i, j;
	for (i = 2; i <= K; i++)Add(1, i);
	for (i = 2; i <= K; i++){
		Add(i, K + 1);
		Add(i, K + 2);
	}
	Add(K + 1, K + 2);
	for (i = 2; i <= K; i++){
		for (j = i + 1; j <= K; j++){
			if (j == i + K / 2)continue;
			Add(i, j);
		}
	}
}
int main(){
	int i;
	scanf("%d", &K);
	if (K % 2 == 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (K == 1){
		printf("2 1\n1 2\n");
		return 0;
	}
	printf("%d %d\n", (K + 2) * 2, (K + 2)*K);
	printf("%d %d\n", 1, K + 3);
	Do();
	for (i = 1; i <= cnt; i++)printf("%d %d\n", w[i][0], w[i][1]);
	for (i = 1; i <= cnt; i++)printf("%d %d\n", w[i][0] + K + 2, w[i][1] + K + 2);
	return 0;
}