#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
struct A{
	int l, v, r, x;
	bool operator <(const A &p)const{
		return l < p.l;
	}
}w[101000];
struct B{
	int v, k;
	bool operator <(const B &p)const{
		return v != p.v ? v < p.v : k < p.k;
	}
}tp;
set<B>Set;
set<B>::iterator it;
int n;
struct ST{
	int k, M, pv;
}IT[1048577];
void spread(int node){
	int c1 = node * 2, c2 = node * 2 + 1;
	IT[c1].k += IT[node].k, IT[c2].k += IT[node].k;
	IT[c1].M += IT[node].k, IT[c2].M += IT[node].k;
	IT[node].k = 0;
}
void Add(int node, int b, int e, int s, int l, int x){
	if (!IT[node].pv)IT[node].pv = b;
	if (b == s && e == l){
		IT[node].k += x;
		IT[node].M += x;
		return;
	}
	int m = (b + e) >> 1;
	if(IT[node].k)spread(node);
	if (m >= s)Add(node * 2, b, m, s, min(l, m), x);
	if (m < l)Add(node * 2 + 1, m + 1, e, max(s, m+1), l, x);
	IT[node].M = IT[node * 2].M, IT[node].pv = IT[node * 2].pv;
	if (IT[node].M < IT[node * 2 + 1].M)IT[node].M = IT[node * 2 + 1].M, IT[node].pv = IT[node * 2 + 1].pv;
}
int main()
{
	int i, s, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d%d%d", &w[i].l, &w[i].v, &w[i].r);
		w[i].x = i + 1;
	}
	sort(w, w + n);
	for (i = 0; i < n; i++){
		while (!Set.empty() && Set.begin()->v < w[i].l){
			it = Set.begin();
			Add(1, 1, 524288, w[it->k].v, w[it->k].r, -1);
			Set.erase(it);
		}
		Add(1, 1, 524288, w[i].v, w[i].r, 1);
		tp.v = w[i].v, tp.k = i;
		Set.insert(tp);
		if (r < IT[1].M)r = IT[1].M;
	}
	printf("%d\n", r);
	Set.clear();
	for (i = 1; i <= 1048576; i++)IT[i].M = IT[i].k = IT[i].pv = 0;
	for (i = 0; i < n; i++){
		while (!Set.empty() && Set.begin()->v < w[i].l){
			it = Set.begin();
			Add(1, 1, 524288, w[it->k].v, w[it->k].r, -1);
			Set.erase(it);
		}
		Add(1, 1, 524288, w[i].v, w[i].r, 1);
		tp.v = w[i].v, tp.k = i;
		Set.insert(tp);
		if (r == IT[1].M){
			while (!Set.empty()){
				it = Set.begin();
				if (it->v <= IT[1].pv && w[it->k].r >= IT[1].pv){
					printf("%d ", w[it->k].x);
				}
				Set.erase(it);
			}
			break;
		}
	}
	return 0;
}