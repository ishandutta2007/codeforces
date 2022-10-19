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
#define N (400000+5)
#define M (400000+5)
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
using namespace std;vector<int> Q[N+5],S[N+5],G[N+5];
int n,m,k,T,x,Bg[N],En[N],H,op[N],Ans[N],Id[N];char C[N],A[N];
namespace AC{
	queue<int> Q;int Ns,cnt,Sn[N][26],FI[N];I void Ins(int x){Ns=0;for(RI i=1;i<=T;i++)!Sn[Ns][A[i]-'a']&&(Sn[Ns][A[i]-'a']=++cnt),Ns=Sn[Ns][A[i]-'a'];Id[x]=Ns;}
	I void BFS(){RI i;for(i=0;i<26;i++) Sn[0][i]&&(Q.push(Sn[0][i]),FI[Sn[0][i]]=0);while(!Q.empty()) for(x=Q.front(),Q.pop(),i=0;i<26;i++)Sn[x][i]?(Q.push(Sn[x][i]),FI[Sn[x][i]]=Sn[FI[x]][i]):(Sn[x][i]=Sn[FI[x]][i]);}
}
namespace Tree{int F[N];I int Ins(int  x,int y){while(x<=H) F[x]+=y,x+=x&-x;}I int Qry(int x){int Ans=0;while(x) Ans+=F[x],x-=x&-x;return Ans;}}
I void dfs(int x){Bg[x]=++H;for(RI i:S[x]) dfs(i);En[x]=H;}
I void calc(int x,int Pa){Pa=AC::Sn[Pa][C[x]-'a'];/*cerr<<x<<' '<<Pa<<' '<<C[x]<<' '<<op[x]<<'\n';*/Tree::Ins(Bg[Pa],1);for(RI i:Q[x]) Ans[i]=Tree::Qry(En[Id[i]])-Tree::Qry(Bg[Id[i]]-1);for(RI i:G[x]) calc(i,Pa);Tree::Ins(Bg[Pa],-1);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&op[i]),op[i]^1&&(scanf("%d",&x),G[x].PB(i),0),scanf("%s",A),C[i]=A[0];scanf("%d",&m);for(i=1;i<=m;i++)scanf("%d%s",&x,A+1),T=strlen(A+1),AC::Ins(i),Q[x].PB(i);
	AC::BFS();for(i=1;i<=AC::cnt;i++) S[AC::FI[i]].PB(i);dfs(0);for(i=1;i<=n;i++) op[i]^2&&(calc(i,0),0);for(i=1;i<=m;i++) printf("%d\n",Ans[i]);
}