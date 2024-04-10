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
#define N (100000+5)
#define M 5000000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
using namespace std;
int n,m,k,x,y,Bh,H,d[N+5],L,W,C[N+5],cnt,Si[N+5],dp[N+5],Mx,vis[N+5];ll Ans;
struct Edge{int to,w;};vector<Edge> S[N+5];
struct Node{int w,d;}A[N+5],B[N+5];I bool cmp(Node x,Node y){return x.w<y.w;}
I void GS(int x,int La){cnt++;for(Edge i:S[x]) i.to^La&&!vis[i.to]&&(GS(i.to,x),0);}
I void DP(int x,int La){Si[x]=1;dp[x]=0;for(Edge i:S[x]) i.to^La&&!vis[i.to]&&(DP(i.to,x),Si[x]+=Si[i.to],dp[x]=max(dp[x],Si[i.to]));dp[x]=max(dp[x],cnt-Si[x]);dp[x]<dp[Mx]&&(Mx=x);} 
namespace Tree{
	int F[N+5];I void Ins(int x){while(x<=L+1) F[x]++,x+=x&-x;}I int Qry(int x){int Ans=0;while(x) Ans+=F[x],x-=x&-x;return Ans;}I void Cl(int x){while(F[x]) F[x]=0,x+=x&-x;}
}
I void dfs(int x,int La){d[x]=d[La]+1;if(d[x]>L||C[x]>W) return;B[++Bh]=(Node){C[x],d[x]};for(Edge i:S[x]) i.to^La&&!vis[i.to]&&(C[i.to]=C[x]+i.w,dfs(i.to,x),0);}
I void calc(int H,Node *B,int Fl){sort(B+1,B+H+1,cmp);RI i,R=1;for(i=H;i;i--) {while(R<=H&&B[i].w+B[R].w<=W) Tree::Ins(B[R++].d+1);Ans+=Fl*Tree::Qry(L-B[i].d+1);}while(R) Tree::Cl(B[R--].d+1);}
I void Solve(int x,int La){
	cnt=0;GS(x,La);Mx=0;DP(x,La);vis[x=Mx]=1;d[x]=C[x]=0;A[H=1]=(Node){0,0};Ans--;for(Edge i:S[x]){if(vis[i.to]) continue;C[i.to]=i.w;Bh=0;dfs(i.to,x);calc(Bh,B,-1);while(Bh)A[++H]=B[Bh--];}
	calc(H,A,1);for(Edge i:S[x]) !vis[i.to]&&(Solve(i.to,x),0);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d%d",&n,&L,&W);L=min(L,n-1);dp[0]=1e9;for(i=2;i<=n;i++) scanf("%d%d",&x,&y),S[x].PB((Edge){i,y}),S[i].PB((Edge){x,y});Solve(1,0);printf("%lld\n",Ans>>1);
}