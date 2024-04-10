#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int Maxn = 200010;
const int inf = 0x7fffffff;
int a[Maxn], belong[Maxn];
vector <int> vec[Maxn]; int cnt;
int n;
int seg[Maxn<<2];
void build_tree(int now, int L, int R) {
	seg[now] = inf;
	if(L < R){
		int mid = (L+R)>>1, lc = now<<1, rc = now<<1|1;
		build_tree(lc, L, mid);
		build_tree(rc, mid+1, R);
	}
}
int qry(int now, int L, int R, int x) {
	if(L == R) return L;
	int mid = (L+R)>>1, lc = now<<1, rc = now<<1|1;
	if(seg[lc] < x) return qry(lc, L, mid, x);
	else return qry(rc, mid+1, R, x);
}
int _min(int x, int y) { return x < y ? x : y; }
void chg(int now, int L, int R, int x, int k) {
	if(L == R){ seg[now] = k; return; }
	int mid = (L+R)>>1, lc = now<<1, rc = now<<1|1;
	if(x <= mid) chg(lc, L, mid, x, k);
	else chg(rc, mid+1, R, x, k);
	seg[now] = _min(seg[lc], seg[rc]);
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	build_tree(1, 1, n);
	for(i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int x = qry(1, 1, n, a[i]);
		if(x > cnt){
			cnt++;
			vec[cnt].push_back(i);
			chg(1, 1, n, cnt, a[i]);
		} else {
			vec[x].push_back(i);
			chg(1, 1, n, x, a[i]);
		}
	}
	for(i = 1; i <= cnt; i++){
		int sz = vec[i].size();
		for(j = 0; j < sz; j++) printf("%d%c", a[vec[i][j]], j==sz-1?'\n':' ');
	}
	return 0;
}