#include<stdio.h>
#include<algorithm>
using namespace std;
int par[201000], n, SZ[201000], Res[201000];
struct A{
	int a, num;
	bool operator<(const A &p)const{
		return a < p.a;
	}
}w[201000];
int Find(int a){
	return par[a] == a ? a : par[a] = Find(par[a]);
}
void Merge(int a, int b){
	a = Find(a);
	b = Find(b);
	SZ[a] += SZ[b];
	SZ[b] = 0;
	par[b] = a;
}
int main(){
	int i, x, y;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i].a);
		w[i].num = i;
	}
	sort(w + 1, w + n + 1);
	for (i = n; i >= 1; i--){
		x = w[i].num;
		par[x] = x;
		SZ[x] = 1;
		if (par[x - 1])Merge(x, x - 1);
		if (par[x + 1])Merge(x, x + 1);
		y = SZ[Find(x)];
		if(!Res[y])Res[y] = w[i].a;
	}
	for (i = n; i >= 1; i--){
		if (Res[i] > Res[i - 1])Res[i - 1] = Res[i];
	}
	for (i = 1; i <= n; i++)printf("%d ", Res[i]);
}