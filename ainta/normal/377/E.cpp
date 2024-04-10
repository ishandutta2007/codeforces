#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N_ 200010
int n, C, top;
long long st[N_], st2[N_];
long long m;
struct A{
	int v, c;
	bool operator <(const A &p)const{
		return c != p.c ? c<p.c : v>p.v;
	}
}w[N_];
struct P{ long long a, b; };
P Do(long long x, int M){
	P t;
	t.a = (x - st2[M] - 1) / st[M] + 1;
	t.b = t.a * st[M] + st2[M] - x;
	return t;
}
int Find(int B, int E, long long x){
	if (B == E)return B;
	P t, t2;
	int R, M;
	while (B < E){
		M = (B + E - 1) >> 1;
		t = Do(x, M);
		t2 = Do(x, M + 1);
		if (t.a < t2.a || (t.a == t2.a && t.b > t2.b)) R = M, E = M;
		else R = M + 1, B = M + 1;
	}
	return R;
}
int main(){
	int i, R;
	P t;
	scanf("%d%lld", &n, &m);
	for (i = 0; i < n; i++){
		scanf("%d%d", &w[i].v, &w[i].c);
	}
	sort(w, w + n);
	st[++top] = w[0].v, st2[top] = 0;
	for (i = 0; i < n; i++){
		if (st[top] >= w[i].v)continue;
		R = Find(1, top, w[i].c);
		t = Do(w[i].c, R);
		t.b -= t.a * w[i].v;
		t.a = w[i].v;
		while (top > 1 && (st2[top - 1] - t.b)*(st[top] - st[top - 1]) < (st2[top - 1] - st2[top])*(t.a - st[top - 1]))top--;
		st[++top] = t.a, st2[top] = t.b;
	}
	R = Find(1, top, m);
	printf("%lld\n", Do(m, R).a);
}