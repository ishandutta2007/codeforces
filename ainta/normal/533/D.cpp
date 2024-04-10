#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 524288
#define INF 2000000010
int w[101000], n, P[101000];
int L[101000], R[101000], Res, cnt;
int IT1[SZ + SZ + 2], IT2[SZ + SZ + 2];
struct Stack{
	int num, c;
}st[101000];
int top;
struct AA{
	int b, e;
}P1[101000], P2[101000];
void Push(int num, int c){
	top++;
	st[top].c = c;
	st[top].num = num;
}
struct Ord{
	int x;
	int chk;
	bool operator<(const Ord &p)const{
		return x < p.x;
	}
}O[501000];
void Push2(int x, int chk){
	cnt++;
	O[cnt].x = x;
	O[cnt].chk = chk;
}
void Ins1(int b, int e, int x){
	b += SZ, e += SZ;
	while (b <= e){
		if (b & 1)IT1[b] = max(IT1[b], x);
		if (!(e & 1))IT1[e] = max(IT1[e], x);
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
}
void Ins2(int b, int e, int x){
	b += SZ, e += SZ;
	while (b <= e){
		if (b & 1)IT2[b] = min(IT2[b], x);
		if (!(e & 1))IT2[e] = min(IT2[e], x);
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
}
int Gap1(int x){
	x += SZ;
	int r = -INF;
	while (x){
		r = max(r, IT1[x]);
		x >>= 1;
	}
	return r;
}
int Gap2(int x){
	x += SZ;
	int r = INF;
	while (x){
		r = min(r, IT2[x]);
		x >>= 1;
	}
	return r;
}
int main(){
	int i, x, c, t;
	scanf("%d", &n);
	for (i = 0; i <= n + 1; i++){
		scanf("%d", &w[i]);
	}
	Res = w[n + 1] - w[0];
	for (i = 1; i <= n; i++){
		scanf("%d", &P[i]);
		P[i] *= 2;
		if (P[i] > w[n + 1] - w[0])P[i] = w[n + 1] - w[0];
	}
	Push(0, INF);
	for (i = 1; i <= n; i++){
		while (top && st[top].c < w[i])top--;
		x = st[top].num;
		c = w[i] + P[i] - (w[i] - w[x]);
		L[i] = c;
		if (L[i] >= w[n + 1]){
			printf("0\n");
			return 0;
		}
		while (top && st[top].c <= c)top--;
		Push(i, c);
		if (c > w[i]){
			Push2(w[i] + 1, i);
			Push2(c, n + i);
		}
	}
	top = 0;
	Push(n + 1, -INF);
	for (i = n; i >= 1; i--){
		while (top && st[top].c > w[i])top--;
		x = st[top].num;
		c = w[i] - (P[i] - (w[x] - w[i]));
		R[i] = c;
		while (top && st[top].c >= c)top--;
		Push(i, c);
		if (c < w[i]){
			Push2(c, n*2 + i);
			Push2(w[i] - 1, n*3 + i);
		}
	}
	sort(O + 1, O + cnt + 1);
	c = 0;
	for (i = 1; i <= cnt; i++){
		if (i == 1 || O[i].x != O[i - 1].x)c++;
		t = (O[i].chk - 1) % n + 1;
		if (O[i].chk <= n)P1[t].b = c;
		else if (O[i].chk <= 2 * n)P1[t].e = c;
		else if (O[i].chk <= 3 * n)P2[t].b = c;
		else P2[t].e = c;
	}
	for (i = 1; i <= SZ + SZ; i++){
		IT1[i] = -INF;
		IT2[i] = INF;
	}
	Ins1(1, c, 0);
	Ins2(1, c, w[n + 1]);
	for (i = 1; i <= n; i++){
		if (P1[i].b){
			Ins1(P1[i].b, P1[i].e, w[i]);
		}
		if (P2[i].b){
			Ins2(P2[i].b, P2[i].e, w[i]);
		}
	}
	for (i = 1; i <= c; i++){
		long long t = Gap2(i);
		t = t - Gap1(i);
		if (Res > t)Res = t;
	}
	if (Res % 2 == 1)printf("%d.5\n", Res / 2);
	else printf("%d\n", Res / 2);
	return 0;
}