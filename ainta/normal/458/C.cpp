#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define SZ 16384
using namespace std;
struct IdxTree{
	int C, Sum;
}IT[SZ*2+2];
int n, cnt[100010], w[101000][2], S, SS, Res;
struct A{
	int a, num;
	bool operator < (const A &p)const{
		return a < p.a;
	}
}ord[100010], p[100010];
void Ins(int a, int b){
	int x = SZ + a;
	IT[x].C += b;
	IT[x].Sum += a*b;
	while (x != 1){
		x >>= 1;
		IT[x].C = IT[x * 2].C + IT[x * 2 + 1].C;
		IT[x].Sum = IT[x * 2].Sum + IT[x * 2 + 1].Sum;
	}
}
int Gap(int node, int b, int e, int c){
	if (b == e){
		return c*b;
	}
	int m = (b + e) >> 1;
	if (IT[node * 2].C >= c){
		return Gap(node * 2, b, m, c);
	}
	return IT[node * 2].Sum + Gap(node * 2 + 1, m + 1, e, c - IT[node * 2].C);
}
int main()
{
	int i, pv, m = 0, t;
	Res = 2100000000;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &w[i][0], &w[i][1]);
		if (w[i][0] == 0){
			S++;
			continue;
		}
		cnt[w[i][0]]++;
		ord[++m].a = w[i][1];
		ord[m].num = w[i][0];
		Ins(w[i][1], 1);
	}
	sort(ord + 1, ord + m + 1);
	for (i = 1; i <= m; i++){
		p[i].num = ord[i].a;
		p[i].a = cnt[ord[i].num]--;
	}
	sort(p + 1, p + m + 1);
	pv = m;
	for (i = n; i >= 1; i--){
		while (pv && p[pv].a >= i){
			Ins(p[pv].num, -1);
			SS += p[pv].num;
			S++;
			pv--;
		}
		if (S > i)break;
		t = SS + Gap(1, 0, SZ-1, i - S);
		if (Res > t)Res = t;
	}
	printf("%d\n", Res);
}