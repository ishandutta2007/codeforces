#include<bits/stdc++.h>
#define ll long long
#define N
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
int n, f[1 << 13], g[1 << 13];
VI num[5005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		num[x].pb(i);
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	rep(i, 1, 5000) {
		memset(g, 0x3f, sizeof g);
		rep(j, 0, (1 << 13) - 1) {
			int u = f[j];
			if(u == inf) continue;
			auto it = lower_bound(all(num[i]), u);
			if(it == num[i].end()) continue;
			g[j ^ i] = min(g[j ^ i], *it);
		}
		rep(j, 0, (1 << 13) - 1) g[j] = min(g[j], f[j]);
		swap(f, g);
	}
	int res = 0;
	rep(j, 0, (1 << 13) - 1) if(f[j] != inf) res++;
	printf("%d\n", res);
	rep(j, 0, (1 << 13) - 1) {
		if(f[j] != inf) printf("%d ", j);
	}
	return 0;
}