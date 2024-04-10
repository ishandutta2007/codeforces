#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (2000+5)
#define M ((N<<2)+5)
#define K (350)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> G[N*2];
int n,m,k,x,y,z,vis[N*2],cnt,sum,W[N*2],Ct;char S[N][N],C[N][N];ll Ans,ToT;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll calc(int W){int i,j;ll ToT=1;for(i=1;i<=n;i++){int Ct=0,Ns=W;for(j=1;j<=m;j++) S[i][j]^'?'?(Ns^=S[i][j]-'0'):(Ct++);if(!Ns&&!Ct) return 0;/*cerr<<ToT<<'\n';*/ToT=ToT*(Ct?mpow(2,Ct-1):1)%mod;}return ToT; }
I void dfs(int x){vis[x]=1;cnt++;Ct^=W[x];sum+=G[x].size();for(int i:G[x]) !vis[i]&&(dfs(i),0);}
I ll Solve(int w){
	int i,j;for(i=1;i<=n+m;i++) W[i]=w;Me(vis,0);for(i=1;i<=n+m;i++) G[i].clear();for(i=1;i<=n;i++) for(j=1;j<=m;j++) S[i][j]^'?'?(W[i]^=S[i][j]-'0',W[j+n]^=S[i][j]-'0'):(G[i].PB(j+n),G[j+n].PB(i),0);
	Ans=1;for(i=1;i<=n+m;i++) {if(vis[i]) continue;Ct=cnt=sum=0;dfs(i);sum/=2;/*cerr<<Ct<<' '<<sum<<' '<<cnt<<'\n';*/if(Ct)return 0;Ans=Ans*mpow(2,sum-cnt+1)%mod;}return Ans;
}
int main(){
//////	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%s",S[i]+1);if(n%2==0&&m%2==0){Ans=1;for(i=1;i<=n;i++) for(j=1;j<=m;j++) S[i][j]=='?'&&(Ans=Ans*2%mod);printf("%lld\n",Ans);return 0;}
	if(n%2&&m%2){printf("%lld\n",(Solve(0)+Solve(1))%mod);return 0;}if(n&1) {for(i=1;i<=n;i++) for(j=1;j<=m;j++) C[j][i]=S[i][j];swap(n,m);Mc(S,C);}
	printf("%lld\n",(calc(0)+calc(1))%mod);
}