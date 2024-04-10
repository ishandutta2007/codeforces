#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
int n,m;
bool vis[N];
int cnt[N],dp[N];
bool check(int x){
	while(x){
		if((x%10)!=4 && (x%10)!=7) return 0;
		x /= 10;
	}
	return 1;
}
namespace UF{
	int fa[N],siz[N];
	int find(int x){return x == fa[x]?x:fa[x] = find(fa[x]);}
	void uni(int u,int v){
		u = find(u); v = find(v);
		if(u == v) return;
		fa[u] = v; siz[v] += siz[u];
	}
}
using namespace UF;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) siz[i] = 1,fa[i] = i;
	rep(i,1,m){
		int u,v; scanf("%d%d",&u,&v);
		uni(u,v);
	}
	rep(i,1,n){
		if(vis[find(i)]) continue;
		vis[find(i)] = 1;
		cnt[siz[find(i)]]++;
	}
	memset(dp,inf,sizeof dp);
	dp[0] = 0;
	rep(i,1,n){
		int x = 1;
		// if(cnt[i]) printf("%d %d\n",i,cnt[i]);
		while(cnt[i] > x){
			per(j,x*i,n) dp[j] = min(dp[j],dp[j-x*i]+x);
			cnt[i] -= x; x <<= 1;
		}
		if(cnt[i] > 0){
			per(j,cnt[i]*i,n) dp[j] = min(dp[j],dp[j-cnt[i]*i]+cnt[i]);
		}
	}
	int ans = inf;
	rep(i,1,n) if(check(i)){
		// printf("%d\n",i);
		ans = min(ans,dp[i]);
	}
	printf("%d\n",ans==inf?-1:ans-1);
	return 0;
}