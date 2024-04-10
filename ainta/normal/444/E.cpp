#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
struct A{
	int a, b, c;
	bool operator <(const A &p)const{
		return c < p.c;
	}
}w[3010];
int S, X[3010], par[3010], C[3010];
int find(int a){
	if (a == par[a])return a;
	return par[a] = find(par[a]);
}
bool merge(int a, int b){
	int x = find(a), y = find(b);
	if (x != y){
		X[x] += X[y], C[x] += C[y]; X[y] = C[y] = 0;
		par[y] = x;
		if (S - X[x] < C[x])return false;
	}
	return true;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++){
		scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &X[i]);
		par[i] = i;
		S += X[i];
		C[i] = 1;
	}
	sort(w, w + n - 1);
	for (i = 0; i < n - 1; i++){
		if (!merge(w[i].a, w[i].b))break;
	}
	printf("%d\n", w[i].c);
}