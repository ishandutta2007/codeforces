#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N ((1<<19)+5)
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
using namespace std;
int n,v,A[N],T[N],dp[N],Ans,Nh;ll Ns[N];
struct Ques{ll a,b;}S[N];I bool cmp(Ques x,Ques y){return x.a^y.a?x.a>y.a:x.b<y.b;}
namespace Tree{int F[N];
I void Ins(int x,int y){while(x<=Nh) F[x]=max(F[x],y),x+=x&-x;}I int Qry(int x){int Ans=-1e9;while(x) Ans=max(Ans,F[x]),x-=x&-x;return Ans;}
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&v);for(i=1;i<=n;i++) scanf("%d",&T[i]);for(i=1;i<=n;i++) scanf("%d",&A[i]),S[i].a=A[i]-1ll*v*T[i],S[i].b=A[i]+1ll*v*T[i];
	S[++n]=(Ques){0ll,0ll};
	sort(S+1,S+n+1,cmp);for(i=1;i<=n;i++) Ns[i]=S[i].b;Nh=n;sort(Ns+1,Ns+Nh+1);Nh=unique(Ns+1,Ns+Nh+1)-Ns-1;for(i=1;i<=n;i++) S[i].b=LB(Ns+1,Ns+Nh+1,S[i].b)-Ns;
	Me(Tree::F,-0x3f);for(i=1;i<=n;i++) dp[i]=Tree::Qry(S[i].b)+1,!Ns[S[i].b]&&!S[i].a&&(dp[i]=0),Ans=max(Ans,dp[i]),Tree::Ins(S[i].b,dp[i]);printf("%d\n",Ans); 
}