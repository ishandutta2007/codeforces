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
#define N 400000
#define M N*N+5
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
using namespace std;
int n,Q,m,k,K,cnt,op,x,y;vector<int> S[N+5];char c[10];
namespace BT{int F[N+5];I void Ins(int x,int y){while(x<=K) F[x]+=y,x+=x&-x;}I int Qry(int x){int Ans=0;while(x)Ans+=F[x],x-=x&-x;return Ans;}}
namespace LCT{
	int fa[N+5],l[N+5],r[N+5],Si[N+5],Fl[N+5],Co[N+5],F[N+5],st[N+5],H;I void Up(int x){Si[x]=Si[l[x]]+Si[r[x]]+1;}I int RS(int x){return r[fa[x]]==x;}I int CD(int x){return r[fa[x]]==x||l[fa[x]]==x;}
	I void PC(int x,int c){x&&(F[x]=c,Co[x]=c);}I void PF(int x){x&&(swap(l[x],r[x]),Fl[x]^=1);}I void P(int x){Fl[x]&&(PF(l[x]),PF(r[x]),Fl[x]=0);F[x]&&(PC(l[x],F[x]),PC(r[x],F[x]),F[x]=0);}
	I void RO(int x){int y=fa[x],z=fa[y],b=(x^l[y]?l[x]:r[x]);CD(y)&&((RS(y)?r[z]:l[z])=x);x^l[y]?(l[x]=y,r[y]=b):(r[x]=y,l[y]=b);fa[x]=z;fa[y]=x;b&&(fa[b]=y);Up(y);Up(x);}
	I void SP(int x){int y=x;st[H=1]=y;while(CD(y)) st[++H]=y=fa[y];while(H)P(st[H--]);while(CD(x)) CD(fa[x])&&(RO(RS(x)^RS(fa[x])?x:fa[x]),0),RO(x);}
	I void AC(int x){RI y;for(y=0;x;x=fa[y=x]) SP(x),r[x]=0,Up(x),Co[x]&&(BT::Ins(Co[x],-Si[x]),0),r[x]=y,Up(x);PC(y,++cnt);BT::Ins(cnt,Si[y]);}I void MR(int x){AC(x);SP(x);PF(x);}
	I int Qry(int x){SP(x);return BT::Qry(Co[x])-Si[l[x]];}
}I void dfs(int x,int La){LCT::fa[x]=La;LCT::Si[x]=1;for(RI i:S[x]) i^La&&(dfs(i,x),0);}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&Q);K=n+Q;for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].push_back(y),S[y].push_back(x);dfs(n,0);for(i=1;i<=n;i++) LCT::AC(i);
	while(Q--) scanf("%s",c+1),scanf("%d",&x),c[1]=='c'&&(scanf("%d",&y)),c[1]=='u'?(LCT::MR(x),0):(printf("%d\n",c[1]^'c'?LCT::Qry(x):(LCT::Qry(x)<LCT::Qry(y)?x:y)));
}