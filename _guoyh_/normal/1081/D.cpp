# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
struct Edge{
	int u, v, w;
	bool operator < (const Edge &o) const{
		return w < o.w;
	}
} e[MAXN];
int n, m, k;
int a[MAXN], p[MAXN];
int findroot(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = findroot(p[nw]);
}
void merge(int x, int y){
	int rx = findroot(x), ry = findroot(y);
	if (rx == ry) return;
	p[rx] = ry;
}
bool check(int mid){
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= mid; i++) merge(e[i].u, e[i].v);
	for (int i = 2; i <= k; i++) if (findroot(a[i]) != findroot(a[1])) return false;
	return true;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e + 1, e + m + 1);
	int lft = 1, rgt = m, ans = 0;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		if (check(mid)){
			ans = mid;
			rgt = mid - 1;
		} else lft = mid + 1;
	}
	for (int i = 1; i <= k; i++) printf("%d ", e[ans].w);
	putchar('\n');
	return 0;
}