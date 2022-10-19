#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int B = 316;
int n, q, anc[N], cnt[B + 10];
ll a[N], tag[B + 10];
int getid(int x) {
	return (x + B - 1) / B;
}
int fa(int x) {
	return x == 1 ? 0 : max(1ll, a[x] + tag[getid(x)]);
}
void recalc(int id, int typ) {
	cnt[id] += typ;
	if(cnt[id] > B) return;
	int l = (id - 1) * B + 1, r = min(n, l + B - 1);
	rep(i, l, r) {
		if(fa(i) < l) anc[i] = i;
		else anc[i] = anc[fa(i)];
	}
}
int lca(int u, int v) {
	// printf("lca %d %d\n", u, v);
	while(anc[u] != anc[v]) {
		if(fa(anc[u]) < fa(anc[v])) swap(u, v);
		u = fa(anc[u]);
	}
	// printf("!%d %d\n", u, v);
	while(u != v) {
		// printf("jump\n");
		if(fa(u) < fa(v)) swap(u, v);
		u = fa(u);
		// printf("%d %d\n", u, v);
	}
	return u;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	rep(i, 2, n) scanf("%lld", &a[i]);
	rep(i, 1, getid(n)) recalc(i, 0);
	while(q--) {
		// rep(i, 1, n) printf("%d ", anc[i]);
		// printf("\n");
		// rep(i, 1, n) printf("%d ", fa(i));
		// printf("\n");
		int opt, x, y, v;
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 2) printf("%d\n", lca(x, y));
		else {
			scanf("%d", &v);
			int l = getid(x), r = getid(y);
			rep(i, (l - 1) * B + 1, x - 1) a[i] += v;
			rep(i, y + 1, min(n, r * B)) a[i] += v;
			rep(i, l, r) {
				tag[i] -= v;
				recalc(i, l < i && i < r);
			}
		}
	}
	return 0;
}