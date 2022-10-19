#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 200000
#define K 1000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,x;ll dp[N+5][2];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I void dfs(int x,int La){
	dp[x][0]=1;yyy tmp;RI i;ll ToT=1,S=0;for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(S++,dfs(tmp.to,x),ToT=ToT*dp[tmp.to][0]%mod,dp[x][0]=dp[x][0]*(dp[tmp.to][0]+dp[tmp.to][1])%mod);
	if(!S){dp[x][0]=dp[x][1]=1;return;}dp[x][1]=(dp[x][0]-ToT+mod)%mod;for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(dp[x][0]-=dp[tmp.to][1]*ToT%mod*mpow(dp[tmp.to][0])%mod);dp[x][0]=(dp[x][0]%mod+mod)%mod; 
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=2;i<=n;i++) scanf("%d",&x),s.add(x,i);dfs(1,0);printf("%lld\n",dp[1][0]);
}