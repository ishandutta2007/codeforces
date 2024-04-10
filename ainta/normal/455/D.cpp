#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[256][2000], D[256][100010], n, C[256], SZ, pp[100010];
int Ans;
void init(){
	int i, j, c = 0;
	for (i = 0; i <= SZ; i++){
		for (j = 1; j <= C[i]; j++){
			pp[c++] = w[i][j];
			D[i][w[i][j]] = 0;
		}
		C[i] = 0;
	}
	for (i = 0; i < n; i++){
		w[i >> 9][++C[i >> 9]] = pp[i];
		D[i >> 9][pp[i]]++;
	}
}
int Find(int a){
	int i, S = 0, x;
	for (i = 0; i <= SZ; i++){
		if (S + C[i] >= a)break;
		S += C[i];
	}
	x = i;
	return (x << 11) + a - S;
}
int Gap(int x, int b, int e, int k){
	int i, c = 0;
	for (i = b; i <= e; i++){
		if (w[x][i] == k)c++;
	}
	return c;
}
int Count(int b, int e, int k){
	int b1 = Find(b) , b2, e1 = Find(e), e2, r = 0, i;
	b2 = b1 & 2047, e2 = e1 & 2047;
	b1 >>= 11; e1 >>= 11;
	if (b1 == e1)return Gap(b1, b2, e2, k);
	r += Gap(b1, b2, C[b1], k);
	r += Gap(e1, 1, e2, k);
	for (i = b1 + 1; i <= e1 - 1; i++){
		r += D[i][k];
	}
	return r;
}
void Del(int x, int y){
	int i;
	D[x][w[x][y]]--;
	for (i = y; i < C[x]; i++)w[x][i] = w[x][i + 1];
	C[x]--;
}
void Ins(int x, int y, int k){
	int i;
	for (i = C[x]; i >= y; i--){
		w[x][i + 1] = w[x][i];
	}
	D[x][k]++;
	w[x][y] = k;
	C[x]++;
}
void rotate(int b, int e){
	int b1 = Find(b), b2, e1 = Find(e), e2, k;
	b2 = b1 & 2047, e2 = e1 & 2047;
	b1 >>= 11; e1 >>= 11;
	k = w[e1][e2];
	Del(e1, e2);
	Ins(b1, b2, k);
}
int main()
{
	int i, a, Q, b, c, d;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a);
		w[i >> 9][++C[i >> 9]] = a;
		D[i >> 9][a]++;
	}
	SZ = (n - 1) >> 9;
	scanf("%d", &Q);
	while (Q--){
		if (Q % 500 == 0){
			init();
		}
		scanf("%d%d%d", &a, &b, &c);
		b = (b + Ans - 1) % n + 1;
		c = (c + Ans - 1) % n + 1;
		if (b > c)swap(b, c);
		if (a == 1){
			rotate(b, c);
		}
		else{
			scanf("%d", &d);
			d = (d + Ans - 1) % n + 1;
			Ans = Count(b, c, d);
			printf("%d\n", Ans);
		}
	}
}