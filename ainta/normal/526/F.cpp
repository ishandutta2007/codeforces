#include<stdio.h>
#include<algorithm>
#define SZ 524288
using namespace std;
int w[301000], n;
long long Res;
struct IdxTree{
	int M, C;
}IT[SZ+SZ+1];
int Mx[301000], Mn[301000];
void UDT(int nd){
	IT[nd] = IT[nd*2];
	if (IT[nd].M > IT[nd * 2 + 1].M)IT[nd] = IT[nd * 2 + 1];
	else if (IT[nd].M == IT[nd * 2 + 1].M)IT[nd].C += IT[nd * 2 + 1].C;
}
void Add(int nd, int M, int C){
	nd += SZ;
	IT[nd].M = M, IT[nd].C = C;
	while (nd!=1){
		nd >>= 1;
		UDT(nd);
	}
}
int Gap(int b, int e){
	int r = 999999999;
	b += SZ, e += SZ;
	while (b <= e){
		r = min(r, IT[b].M);
		r = min(r, IT[e].M);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int Sum(int b, int e, int t){
	int r = 0;
	b += SZ, e += SZ;
	while (b <= e){
		if (b & 1){
			if (IT[b].M == t)r += IT[b].C;
		}
		if (!(e & 1)){
			if (IT[e].M == t)r += IT[e].C;
		}
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
void Do(int b, int e){
	int i, MMx = -1, MMn = n + 1, bb, t, ee;
	if (b == e){
		Res++;
		return;
	}
	int m = (b + e) >> 1, pv;
	Do(b, m);
	Do(m + 1, e);
	for (i = m; i >= b; i--){
		if (MMx < w[i])MMx = w[i];
		if (MMn > w[i])MMn = w[i];
		Mx[i] = MMx, Mn[i] = MMn;
	}
	MMx = -1, MMn = n + 1;
	for (i = m + 1; i <= e; i++){
		if (MMx < w[i])MMx = w[i];
		if (MMn > w[i])MMn = w[i];
		Mx[i] = MMx, Mn[i] = MMn;
	}
	for (i = m + 1; i <= e; i++){
		Add(i, Mx[i] - i, 1);
	}
	pv = m;
	for (i = m; i >= b; i--){
		while (pv + 1 <= e && Mn[pv + 1] > Mn[i])pv++;
		bb = i + Mx[i] - Mn[i];
		if (bb == m)bb = m + 1;
		if (bb > pv)continue;
		t = Gap(bb, bb);
		if (t <= Mn[i] - i)Res++;
		bb++;
		if (bb > pv)continue;
		t = Gap(bb, pv);
		if (t != Mn[i] - i)continue;
		Res += Sum(bb, pv, t);
	}
	for (i = b; i <= m; i++){
		Add(i, Mx[i] + i, 1);
	}
	pv = m + 1;
	for (i = m + 1; i <= e; i++){
		while (pv - 1 >= b && Mn[pv - 1] > Mn[i])pv--;
		ee = i - (Mx[i] - Mn[i]);
		if (ee == m + 1)ee = m;
		if (ee < pv)continue;
		t = Gap(ee, ee);
		if (t <= Mn[i] + i)Res++;
		ee--;
		if (ee < pv)continue;
		t = Gap(pv, ee);
		if (t != Mn[i] + i)continue;
		Res += Sum(pv, ee, t);
	}
}
int main(){
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		w[a] = b;
	}
	Do(1, n);
	printf("%lld\n", Res);
}