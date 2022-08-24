#include<stdio.h>
#include<algorithm>
#define SZ 1048576
#define INF 1111111111
using namespace std;
int n, m, X[1010000], C[201000], IT[SZ+SZ+2][3], D[201000];
long long Res;
struct A{
	int x, num;
	bool operator<(const A &p)const{
		return x < p.x;
	}
}ord[1010000];
struct B{
	int b, e, num;
	bool operator<(const B &p)const{
		return e < p.e;
	}
}w[201000], P[201000];
void Ins(int pv, int a, int b){
	a += SZ;
	if(pv == 1)IT[a][pv] = min(IT[a][pv], b);
	else IT[a][pv] = max(IT[a][pv], b);
	while (a != 1){
		a >>= 1;
		if (pv == 1)IT[a][pv] = min(IT[a * 2][pv], IT[a * 2 + 1][pv]);
		else IT[a][pv] = max(IT[a * 2][pv], IT[a * 2 + 1][pv]);
	}
}
int Gap(int pv, int b, int e){
	int r;
	if (pv == 1)r = INF;
	else r = 0;
	b += SZ, e += SZ;
	while (b <= e){
		if (pv == 1) r = min(r, min(IT[e][pv], IT[b][pv]));
		else r = max(r, max(IT[e][pv], IT[b][pv]));
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
	return r;
}
int main(){
	scanf("%d%d", &n, &m);
	int i, cnt = 0, pv;
	long long t;
	for (i = 1; i <= n; i++){
		scanf("%d%d", &ord[i].x, &ord[i + n].x);
		w[i].num = i;
	}
	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &ord[i + n*2].x, &ord[i + n*2+m].x, &C[i]);
		P[i].num = i;
	}
	for (i = 1; i <= n * 2 + m * 2; i++)ord[i].num = i;
	sort(ord + 1, ord + n * 2 + m * 2 + 1);
	for (i = 1; i <= n*2+m*2; i++){
		if (i == 1 || ord[i].x != ord[i - 1].x){
			cnt++;
			X[cnt] = ord[i].x;
		}
		if (ord[i].num <= n)w[ord[i].num].b = cnt;
		else if (ord[i].num <= n * 2)w[ord[i].num - n].e = cnt;
		else if (ord[i].num <= n * 2 + m)P[ord[i].num-n*2].b = cnt;
		else P[ord[i].num - n*2-m].e = cnt;
	}
	sort(w + 1, w + n + 1);
	sort(P + 1, P + m + 1);
	for (i = 1; i <= SZ + SZ; i++)IT[i][1] = INF;
	for (i = 1; i <= n; i++){
		Ins(0, w[i].b, X[w[i].e]);
		Ins(1, w[i].e, X[w[i].b]);
	}
	for (i = 1; i <= m; i++){
		D[i] = max(D[i], min(Gap(0, 1, P[i].b), X[P[i].e]) - X[P[i].b]);
		D[i] = max(D[i], X[P[i].e] - max(Gap(1, P[i].e, cnt), X[P[i].b]));
	}
	pv = 1;
	for (i = 1; i <= m; i++){
		while (pv <= n && w[pv].e <= P[i].e){
			Ins(2, w[pv].b, X[w[pv].e] - X[w[pv].b]);
			pv++;
		}
		D[i] = max(D[i], Gap(2, P[i].b, P[i].e));
	}
	for (i = 1; i <= m; i++){
		t = (long long)C[P[i].num] * D[i];
		if (Res < t){
			Res = t;
			pv = i;
		}
	}
	printf("%lld\n", Res);
	if (Res == 0)return 0;
	for (i = 1; i <= n; i++){
		t = min(X[w[i].e], X[P[pv].e]) - max(X[w[i].b], X[P[pv].b]);
		t = t * C[P[pv].num];
		if (Res == t)break;
	}
	printf("%d %d\n", w[i].num, P[pv].num);
}