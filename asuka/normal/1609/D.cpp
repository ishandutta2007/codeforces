#include<bits/stdc++.h>
#define ll long long
#define N 10005
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
int n, d, x, fa[N], siz[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	siz[u] += siz[v];
	fa[v] = u;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &d);
	rep(i, 1, n) fa[i] = i, siz[i] = 1;
	rep(_, 1, d) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(find(u) == find(v)) x++;
		else uni(u, v);
		VI vec;
		rep(i, 1, n) if(i == find(i)) vec.pb(siz[i]);
		sort(all(vec));
		reverse(all(vec));
		int ans = 0;
		rep(i, 1, x + 1) ans += vec[i - 1];
		printf("%d\n", ans - 1);
	}
	return 0;
}