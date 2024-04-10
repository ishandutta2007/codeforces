#include<bits/stdc++.h>
#define int long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define mod 998244353
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
namespace DSU{
	int fa[N],siz[N];
	void init(int n){rep(i,0,n+1){ fa[i] = i;siz[i] = 1;}}
	int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
	void uni(int u,int v){
		u = find(u);v = find(v);
		if(u == v) return;
		if(siz[u] > siz[v]) swap(u,v);
		fa[u] = v;
		siz[v] += siz[u];
	}
}
using namespace DSU;
int n,k,t,a[N],b[N],pos[N],pre[N],nxt[N],flag[N],used[N];
void del(int p){
	pre[nxt[p]] = pre[p];
 	nxt[pre[p]] = nxt[p];
}
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (1ll*res*a)%mod;
		a = (1ll*a*a)%mod; b>>=1;
	}
	return res;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t);
 	while(t--){
 		scanf("%lld%lld",&n,&k);
 		rep(i,1,n) flag[i] = used[i] = 0;
 		rep(i,1,n) scanf("%lld",&a[i]),pos[a[i]] = i;
 		rep(i,1,n) pre[i] = i-1,nxt[i] = i+1;
 		rep(i,1,k) scanf("%lld",&b[i]),flag[b[i]] = 1;
 		int ans = 1;
 		rep(i,1,k){
 			flag[b[i]] = 0;
 			int p = pos[b[i]];
 			int r = 0;
 			if((p-1>0)&&(!flag[a[p-1]])) r++;
 			if((p+1<=n)&&(!flag[a[p+1]])) r++;
 			ans = (ans*r)%mod;
 		}
 		printf("%lld\n",ans);
 	}
	return 0;
}