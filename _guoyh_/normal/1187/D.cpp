# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
int T, n;
int a[MAXN], b[MAXN];
int c[MAXN], d[MAXN];
int p[MAXN];
int nm1[MAXN], nm2[MAXN];
struct SegTree{
	struct Node{
		int s;
		int ls, rs;
	} t[MAXN * 4];
	int rt, tsz;
	int newnode(){
		tsz++;
		t[tsz].s = 0;
		t[tsz].ls = t[tsz].rs = 0;
		return tsz;
	}
	void update(int nw){
		t[nw].s = max(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void modify(int &nw, int lft, int rgt, int pos, int nm){
		if (!nw) nw = newnode();
		if (lft == rgt){
			t[nw].s = max(t[nw].s, nm);
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, nm);
		else modify(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
	int getsum(int nw, int lft, int rgt, int l, int r){
		if (l > r) return 0;
		if (!nw) return 0;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		int ans = 0;
		if (l <= mid) ans = max(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = max(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
bool cmpa(int u, int v){
	if (a[u] != a[v]) return a[u] < a[v];
	else return u < v;
}
bool cmpb(int u, int v){
	if (b[u] != b[v]) return b[u] < b[v];
	else return u < v;
}
bool solve(){
	sgt.rt = sgt.tsz = 0;
	for (int i = 1; i <= n; i++) c[i] = i;
	for (int i = 1; i <= n; i++) d[i] = i;
	sort(c + 1, c + n + 1, cmpa);
	sort(d + 1, d + n + 1, cmpb);
	for (int i = 1; i <= n; i++){
		// printf("i %d %d %d %d %d\n", i, c[i], d[i], a[c[i]], b[d[i]]);
		if (a[c[i]] != b[d[i]]) return false;
		p[c[i]] = d[i];
	}
	for (int i = 1; i <= n; i++){
		if (sgt.getsum(sgt.rt, 1, n, 1, a[i] - 1) > p[i]) return false;
		sgt.modify(sgt.rt, 1, n, a[i], p[i]);
	}
	return true;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}