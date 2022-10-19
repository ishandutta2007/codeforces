#include<bits/stdc++.h>
#define ll long long
#define N 505
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
int n,k,x;
char s[N];
namespace Trie{
	int ch[N][15],tot,val[N],dep[N];
	void insert(char *s,int v){
		int u = 0;
		for(int i = 0;s[i];++i){
			if(!ch[u][s[i]-'0']) ch[u][s[i]-'0'] = ++tot;
			u = ch[u][s[i]-'0'];
		}
		val[u] += v;
	}
}
using namespace Trie;
int dp[N][N][15];
void dfs(int u,int dep){
	rep(i,0,9){
		if(!ch[u][i]) continue;
		dfs(ch[u][i],dep+1);
	}
	rep(p,0,k) rep(i,0,dep) dp[u][i][p] = i*val[u];
	rep(i,0,9){
		rep(j,0,dep){
			if(!ch[u][i]) continue;
			per(p,0,k){rep(q,1,k-p)
				dp[u][j][p+q] = min(dp[u][j][p+q],dp[u][j][p]+dp[ch[u][i]][j+1][q]);
			dp[u][j][p] += dp[ch[u][i]][j+1][0];
			}
		}
	}
	rep(p,1,k) rep(j,0,dep) dp[u][j][p] = min(dp[u][j][p],dp[u][0][p-1]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%s%d",s+1,&x);
		insert(s+1,x);
	}
	dfs(0,0);
	printf("%d\n",dp[0][0][k]);
	return 0;
}