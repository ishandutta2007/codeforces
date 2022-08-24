#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, P[100010], SZ;
int X[510][710], C[510];
int XX[100010];
long long Gap[510], Sum[510];
void init_row(int a){
	Gap[a] = 0;
	int i;
	long long S = 0;
	for (i = 1; i <= C[a]; i++){
		Gap[a] += (long long)X[a][i] * (i - 1) - S;
		S = S + X[a][i];
	}
	Sum[a] = S;
}
void init2()
{
	int i, j;
	for (i = 1; i <= SZ; i++){
		init_row(i);
	}
}
void init()
{
	int i, j, cnt = 0;
	for (i = 1; i <= SZ; i++){
		for (j = 1; j <= C[i]; j++){
			XX[++cnt] = X[i][j];
		}
		C[i] = 0;
	}
	for (i = 1; i <= cnt; i++){
		X[(i >> 9) + 1][++C[(i >> 9) + 1]] = XX[i];
	}
	init2();
}
long long Calc3(int a, int b, int c){
	long long S = 0, Res = 0;
	int i;
	for (i = b; i <= c; i++){
		Res += (long long)X[a][i] * (i - b) - S;
		S += X[a][i];
	}
	return Res;
}
long long Calc2(int b1, int b2, int e1, int e2)
{
	if (b1 > e1 || (b1 == e1&&b2 > e2))return 0;
	if (b1 == e1){
		return Calc3(b1, b2, e2);
	}
	int i;
	long long cnt = 0, c1, Res = 0, S;
	Res += Calc3(b1, b2, C[b1]);
	Res += Calc3(e1, 1, e2);
	for (i = b1 + 1; i <= e1 - 1; i++){
		cnt += C[i];
		Res += Gap[i];
	}
	cnt += C[b1] - b2 + 1;
	cnt += e2;
	S = 0;
	for (i = b2; i <= C[b1]; i++){
		S += X[b1][i];
	}
	Res -= S * (cnt - (C[b1] - b2 + 1));
	S = 0;
	for (i = 1; i <= e2; i++){
		S += X[e1][i];
	}
	Res += S * (cnt - e2);
	c1 = C[b1] - b2 + 1;
	for (i = b1 + 1; i <= e1 - 1; i++){
		Res += Sum[i] * (c1 * 2 + C[i] - cnt);
		c1 += C[i];
	}
	return Res;
}
long long Calc(int x1, int x2){
	int a, b, c, d, i;
	for (i = 1; i <= SZ; i++){
		if (X[i][C[i]] >= x1)break;
	}
	a = i;
	if (a == SZ + 1)return 0;
	for (i = SZ; i >= 1; i--){
		if (X[i][1] <= x2)break;
	}
	b = i;
	if (i == 0)return 0;
	for (i = 1; i <= C[a]; i++){
		if (X[a][i] >= x1)break;
	}
	c = i;
	for (i = C[b]; i >= 1; i--){
		if (X[b][i] <= x2)break;
	}
	d = i;
	return Calc2(a, c, b, d);
}
void Del2(int a, int b){
	int i;
	for (i = b; i <= C[a]; i++){
		X[a][i] = X[a][i + 1];
	}
	C[a]--;
	init_row(a);
}
void Del(int x){
	int i, a, b;
	for (i = 1; i <= SZ; i++){
		if (X[i][C[i]] >= x)break;
	}
	a = i;
	for (i = 1; i <= C[a]; i++){
		if (X[a][i] == x)break;
	}
	b = i;
	Del2(a, b);
}
void Ins2(int a, int b, int x){
	int i;
	for (i = C[a] + 1; i > b; i--)X[a][i] = X[a][i - 1];
	X[a][b] = x;
	C[a]++;
	init_row(a);
}
void Ins(int x){
	int i, a, b;
	for (i = 1; i <= SZ; i++){
		if (X[i][C[i]] >= x)break;
	}
	a = i;
	if (a == SZ + 1) a = SZ;
	for (i = 1; i <= C[a]; i++){
		if (X[a][i] >= x)break;
	}
	b = i;
	Ins2(a, b, x);
	if (C[a] == 705)init();
}
void Do(int a, int x){
	Del(P[a]);
	P[a] = x;
	Ins(P[a]);
}
int main()
{
	int i, j, a, b, c;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &P[i]);
		XX[i] = P[i];
	}
	scanf("%d", &m);
	sort(XX + 1, XX + n + 1);
	for (i = 1; i <= n; i++){
		X[(i >> 9) + 1][++C[(i >> 9) + 1]] = XX[i];
	}
	SZ = (n >> 9) + 1;
	init2();
	while (m--){
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1){
			Do(b, P[b] + c);
		}
		else{
			printf("%lld\n", Calc(b, c));
		}
	}
	return 0;
}