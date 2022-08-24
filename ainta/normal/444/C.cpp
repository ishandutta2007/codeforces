#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define SZ 131072
using namespace std;
int n, m, G[100010];
struct IdxTree{
	long long S, K;
	int col;
}IT[SZ * 2 + 2];
void spread(int node, int b, int m, int e){
	long long K = IT[node].K;
	int col = IT[node].col;
	IT[node * 2].K += K, IT[node * 2 + 1].K += K;
	IT[node * 2].S += (m - b + 1)*K, IT[node * 2 + 1].S += (e - m)*K;
	IT[node].K = 0;
	if(IT[node].col)IT[node * 2].col = IT[node * 2 + 1].col = IT[node].col;
}
void Ins(int node, int b, int e, int s, int l, int x){
	if (b == s && e == l && IT[node].col){
		int t = abs(x - IT[node].col);
		IT[node].col = x;
		IT[node].K += t, IT[node].S += (long long)t*(e - b + 1);
		return;
	}
	int m = (b + e) >> 1;
	spread(node, b, m, e);
	if (s <= m){
		Ins(node * 2, b, m, s, min(m, l), x);
	}
	if (l > m){
		Ins(node * 2 + 1, m + 1, e, max(m + 1, s), l, x);
	}
	IT[node].S = IT[node * 2].S + IT[node * 2 + 1].S;
	if (IT[node * 2].col && IT[node * 2].col == IT[node * 2 + 1].col)IT[node].col = IT[node * 2].col;
	else IT[node].col = 0;
}
long long Gap(int node, int b, int e, int s, int l){
	if (b == s && e == l){
		return IT[node].S;
	}
	int m = (b + e) >> 1;
	spread(node, b, m, e);
	long long r = 0;
	if (s <= m){
		r += Gap(node * 2, b, m, s, min(l, m));
	}
	if (l > m){
		r += Gap(node * 2 + 1, m + 1, e, max(m + 1, s), l);
	}
	return r;
}
void init(int node, int b, int e){
	if (b > n)return;
	if (b == e){
		IT[node].col = b;
		return;
	}
	int m = (b + e) >> 1;
	init(node * 2, b, m);
	init(node * 2 + 1, m + 1, e);
}
int main()
{
	int i, ty, a, b, c;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n + 1; i++){
		G[i] = i;
	}
	init(1, 1, SZ);
	while (m--){
		scanf("%d%d%d", &ty, &a, &b);
		if (ty == 1){
			scanf("%d", &c);
			Ins(1, 1, SZ, a, b, c);
		}
		else{
			printf("%lld\n", Gap(1, 1, SZ, a, b));
		}
	}
}