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
#define N 50
#define K 1000000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5) 
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int s,Fl[N+5],ToT,Ans=1e9,n,m,k,dp[N+5][N*2+5][N+5],x,y,z;
struct Edge{int to,id,w;}tmp;vector<Edge> S[N+5];
I int dfs(int Id,int y,int w,int k){
	if(~dp[w][Id][k]) return dp[w][Id][k];
	if(S[y].size()==1) return dp[w][Id][k]=(w^k?S[y][0].w+dfs(Id^1,S[y][0].to,w-k,w-k):0);
	RI i,j,h,F[N+5],H[N+5],G[N+5],Fl=0;for(i=0;i<S[y].size();i++){if(!(S[y][i].id^Id^1))continue;
	    H[0]=1e9;for(j=1;j<=k;j++)H[j]=S[y][i].w+dfs(S[y][i].id,S[y][i].to,w,j);
	    if(!Fl) {Fl=1;memcpy(F,H,sizeof(F));continue;}
		memcpy(G,F,sizeof(G));Me(F,0);
		for(j=0;j<=k;j++)for(h=0;h<=k-j;h++) F[j+h]=max(F[j+h],min(G[j],H[h])); 
	}return /*printf("%d %d %d %d %d\n",Id,y,w,k,F[k]),*/dp[w][Id][k]=F[k];
} 
I void GS(int x,int La){ToT+=Fl[x];for(RI i=0;i<S[x].size();i++)S[x][i].to^La&&(GS(S[x][i].to,x),0);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d%d",&x,&y,&z),S[x].push_back((Edge){y,i*2-2,z}),S[y].push_back((Edge){x,i*2-1,z});Me(dp,-1);scanf("%d%d",&s,&m);
	for(i=1;i<=m;i++) scanf("%d",&x),Fl[x]++;for(i=0;i<S[s].size();i++)ToT=0,GS(S[s][i].to,s),ToT&&(Ans=min(Ans,S[s][i].w+dfs(S[s][i].id,S[s][i].to,m,ToT)));printf("%d\n",Ans);
}