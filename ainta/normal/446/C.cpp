#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
struct SegTree{
	long long Sum;
	long long A, B;
}IT[SZ*2+2];
long long Mod = 1000000009, F[300100];
long long F2[300100][2];
int n, m, w[300100];
void UDT(int node){
	IT[node].Sum = (IT[node * 2].Sum + IT[node * 2 + 1].Sum) % Mod;
}
void init(int node, int b, int e){
	if (b == e){
		if (b <= n)IT[node].Sum = w[b];
		return;
	}
	int m = (b + e) >> 1;
	init(node * 2, b, m);
	init(node * 2 + 1, m + 1, e);
	UDT(node);
}
long long Next(long long a, long long b, int K){
	return (F2[K][0] * a + F2[K][1] * b) % Mod;
}
void spread(int node, int b, int m, int e){
	long long A = IT[node].A, B = IT[node].B, T;
	if (A == 0 && B == 0)return;
	int c1 = node * 2, c2 = node * 2 + 1;
	IT[node].A = IT[node].B = 0;
	IT[c1].A = (IT[c1].A + A) % Mod, IT[c1].B = (IT[c1].B + B) % Mod;
	IT[c2].A = (IT[c2].A + Next(A, B, m - b + 2)) % Mod;
	T = Next(A, B, m - b + 3);
	IT[c2].B = (IT[c2].B + T) % Mod;
	IT[c1].Sum = (IT[c1].Sum + T - B + Mod) % Mod;
	IT[c2].Sum = (IT[c2].Sum + Next(A, B, e - b + 3) - T + Mod) % Mod;
}
void Ins(int node, int b, int e, int s, int l, int x){
	if (b == s && e == l){
		IT[node].Sum = (IT[node].Sum + F[x + e - b + 2] - F[x + 1] + Mod) % Mod;
		IT[node].A = (IT[node].A + F[x]) % Mod;
		IT[node].B = (IT[node].B + F[x + 1]) % Mod;
		return;
	}
	int m = (b + e) >> 1;
	spread(node, b, m, e);
	if (s <= m)Ins(node * 2, b, m, s, min(m, l), x);
	if (l > m)Ins(node * 2 + 1, m + 1, e, max(m + 1, s), l, x + m + 1 - min(s, m + 1));
	UDT(node);
}
long long Gap(int node, int b, int e, int s, int l){
	if (b == s && e == l)return IT[node].Sum;
	int m = (b + e) >> 1;
	long long res = 0;
	spread(node, b, m, e);
	if (s <= m)res += Gap(node * 2, b, m, s, min(m, l));
	if (l > m)res += Gap(node * 2 + 1, m + 1, e, max(m + 1, s), l);
	return res%Mod;
}
int main()
{
	int i, a, b, c;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	init(1, 1, SZ);
	F[1] = F[2] = 1;
	F2[1][0] = 1; F2[2][1] = 1;
	for (i = 3; i <= 300010; i++){
		F[i] = (F[i - 1] + F[i - 2]) % Mod;
		F2[i][0] = (F2[i - 1][0] + F2[i - 2][0])%Mod;
		F2[i][1] = (F2[i - 1][1] + F2[i - 2][1])%Mod;
	}
	while (m--){
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1){
			Ins(1, 1, SZ, b, c, 1);
		}
		else{
			printf("%lld\n", Gap(1, 1, SZ, b, c)%Mod);
		}
	}
}