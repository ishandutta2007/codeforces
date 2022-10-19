#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (3000+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> S[N];
int T,n,m,k,x,y,z,A[N],Si[N];
struct Pa{
	int a;ll b;Pa operator +(const Pa &B)const{return (Pa){a+B.a,b+B.b};}
	bool operator >(const Pa &B)const{return a^B.a?a>B.a:b>B.b;}
}dp[N][N],Cl=(Pa){0,(ll)-1e18},G[N];
I void dfs(int x,int La){
	int i,j;for(i=0;i<=n;i++) dp[x][i]=Cl;dp[x][0]=(Pa){0,A[x]};Si[x]=1;
	for(int v:S[x]){
		if(v==La) continue;dfs(v,x);for(i=0;i<=Si[x];i++) G[i]=dp[x][i];for(i=0;i<=Si[x]+Si[v];i++) dp[x][i]=Cl;
		for(i=0;i<=Si[x];i++){
			for(j=0;j<=Si[v];j++) dp[x][i+j]=max(dp[x][i+j],G[i]+dp[v][j]);
		}Si[x]+=Si[v];
	}if(i^1)for(i=0;i<Si[x];i++) dp[x][i+1]=max(dp[x][i+1],((Pa){dp[x][i].a+(dp[x][i].b>0),0}));
}
I void Solve(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&x),A[i]=x-A[i],S[i].clear();
	for(i=1;i<n;i++)scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);dfs(1,0);printf("%d\n",dp[1][m-1].a+(dp[1][m-1].b>0));
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}