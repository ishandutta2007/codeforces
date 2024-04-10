# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 35051;
struct Tree{
	int s, tag;
	int ls, rs;
} t[MAXN * 105];
int n, k, tsz, ans;
int a[MAXN];
int pre[MAXN], last[MAXN];
int f[MAXN][55];
int rt[55];
void update(int nw){
	t[nw].s = max(t[t[nw].ls].s, t[t[nw].rs].s);
}
void push_down(int nw){
	t[t[nw].ls].s += t[nw].tag;
	t[t[nw].rs].s += t[nw].tag;
	t[t[nw].ls].tag += t[nw].tag;
	t[t[nw].rs].tag += t[nw].tag;
	t[nw].tag = 0;
}
int build(int lft, int rgt){
	int nw = ++tsz;
	if (lft == rgt) return nw;
	int mid = (lft + rgt) >> 1;
	t[nw].ls = build(lft, mid);
	t[nw].rs = build(mid + 1, rgt);
	update(nw);
	return nw;
}
void modify(int nw, int lft, int rgt, int l, int r, int nm){
	if (l > r) return;
	if (lft == l && rgt == r){
		t[nw].s += nm;
		t[nw].tag += nm;
		return;
	}
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	if (l <= mid) modify(t[nw].ls, lft, mid, l, min(mid, r), nm);
	if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, nm);
	update(nw);
}
int getsum(int nw, int lft, int rgt, int l, int r){
	if (lft == l && rgt == r) return t[nw].s;
	push_down(nw);
	int mid = (lft + rgt) >> 1, ans = -1e9;
	if (l <= mid) ans = max(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
	if (r >= mid + 1) ans = max(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
	return ans;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 0; i <= k; i++) rt[i] = build(0, n);
	for (int i = 1; i <= n; i++){
		pre[i] = last[a[i]];
		last[a[i]] = i;
		for (int j = 1; j <= k && j <= i; j++){
			modify(rt[j - 1], 0, n, pre[i], i - 1, 1);
			f[i][j] = getsum(rt[j - 1], 0, n, 0, i);
			modify(rt[j], 0, n, i, i, f[i][j]);
			ans = max(ans, f[i][j]);
			// printf("f %d %d %d\n", i, j, f[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}