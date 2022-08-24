#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define SZ 131072
using namespace std;
int n, m, i, w[100010];
struct Seg{
	long long S;
	int M;
}Seg[SZ*2+1];
long long Sum(int node, int b, int e, int s, int l)
{
	s = max(b, s), l = min(e, l);
	if (b == s&&e == l)return Seg[node].S;
	int m = (b + e) >> 1;
	long long r = 0;
	if (s <= m)r += Sum(node * 2, b, m, s, l);
	if (l > m)r += Sum(node * 2 + 1, m + 1, e, s, l);
	return r;
}
void Do(int node, int b, int e, int s, int l, int mod, int x)
{
	if (!x && Seg[node].M < mod)return;
	s = max(b, s), l = min(e, l);
	if (b == e){
		int t = x ? mod : w[b] % mod;
		Seg[node].S += t - w[b];
		Seg[node].M = w[b] = t;
		return;
	}
	int m = (b + e) >> 1;
	long long r = 0;
	if (s <= m)Do(node * 2, b, m, s, l, mod, x);
	if (l > m)Do(node * 2 + 1, m + 1, e, s, l, mod, x);
	Seg[node].S = Seg[node * 2].S + Seg[node * 2 + 1].S;
	Seg[node].M = max(Seg[node * 2].M, Seg[node * 2 + 1].M);
}
void init(int node, int b, int e)
{
	if (b == e){
		Seg[node].S = Seg[node].M = w[b];
		return;
	}
	int m = (b + e) >> 1;
	init(node * 2, b, m);
	if (m < n){
		init(node * 2 + 1, m + 1, e);
	}
	Seg[node].S = Seg[node * 2].S + Seg[node * 2 + 1].S;
	Seg[node].M = max(Seg[node * 2].M, Seg[node * 2 + 1].M);
}
int main()
{
	int i, t = 1, a, b, c, d;
	long long res;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	init(1, 1, SZ);
	while (m--){
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1){
			printf("%lld\n", Sum(1, 1, SZ, b, c));
		}
		if (a == 2){
			scanf("%d", &d);
			Do(1, 1, SZ, b, c, d, 0);
		}
		if (a == 3){
			Do(1, 1, SZ, b, b, c, 1);
		}
	}
}