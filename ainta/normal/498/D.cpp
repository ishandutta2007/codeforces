#include<stdio.h>
#define SZ 131072
int n;
int IT[262144][60];
void UDT(int a){
	while (a != 1){
		a >>= 1;
		for (int x = 0; x < 60; x++){
			IT[a][x] = IT[a * 2][x] + IT[a * 2 + 1][(x + IT[a * 2][x]) % 60];
		}
	}
}
void Do(int a, int b){
	a += SZ;
	int i;
	for (i = 0; i < 60; i++){
		if (i%b == 0)IT[a][i] = 2;
		else IT[a][i] = 1;
	}
	UDT(a);
}
int Sum(int a, int b){
	a += SZ, b += SZ;
	int P[20], cnt = 0, res = 0, i;
	while (a <= b){
		if (a & 1){
			res += IT[a][res % 60];
		}
		if (!(b & 1))P[cnt++] = b;
		a = (a + 1) >> 1, b = (b - 1) >> 1;
	}
	for (i = cnt - 1; i >= 0; i--){
		res += IT[P[i]][res % 60];
	}
	return res;
}
int main(){
	int i, Q, a, b;
	char p[2];
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		Do(i, a);
	}
	scanf("%d", &Q);
	while (Q--){
		scanf("%s", p);
		scanf("%d%d", &a, &b);
		if (p[0] == 'C'){
			Do(a, b);
		}
		else printf("%d\n", Sum(a, b - 1));
	}
}
/*
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "w", stdout);
	int i, a, b;
	srand(2);
	printf("100000\n");
	for (i = 1; i <= 100000; i++)printf("%d ", rand() % 5 + 2);
	printf("\n100000\n");
	for (i = 0; i < 100000; i++){
		while (1){
			a = rand() % 100001 + 1;
			b = rand() % 100001 + 1;
			if (a < b)break;
		}
		printf("A %d %d\n", a, b);
	}
}*/