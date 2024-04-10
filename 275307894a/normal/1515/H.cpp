#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
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
using namespace std;const int INF=(1<<20)-1;
int n,m,op,x,y,z,cnt,Ro,R1,R2;
namespace Trie{
	int L[N*100],R[N*100],S[N*100],G[N*100],F1[N*100],F2[N*100];I void Up(int now){S[now]=S[L[now]]+S[R[now]];F1[now]=F1[L[now]]|F1[R[now]];F2[now]=F2[L[now]]|F2[R[now]];}
	I void Ins(int x,int &now,int d,int l=0,int r=INF){!now&&(now=++cnt);if(l==r){S[now]=1;F1[now]=x;F2[now]=INF^x;return;}int m=l+r>>1;x<=m?Ins(x,L[now],d-1,l,m):Ins(x,R[now],d-1,m+1,r);Up(now);}
	I void PF(int now,int w,int d){if(!now) return;G[now]^=w;w>>d&1&&(swap(L[now],R[now]),0);int P1=F1[now],P2=F2[now];F1[now]=(P1&(~w))|(P2&w);F2[now]=(P2&(~w))|(P1&w);}I void P(int now,int d){G[now]&&(PF(L[now],G[now],d-1),PF(R[now],G[now],d-1),G[now]=0);}
	I int ME(int x,int y,int d){if(!x||!y) return x|y;P(x,d);P(y,d);if(d==-1){S[x]=S[x]|S[y];F1[x]=F1[x]|F1[y];F2[x]=F2[x]|F2[y];/*cerr<<S[x]<<' '<<z<<'\n';*/return x;}L[x]=ME(L[x],L[y],d-1);R[x]=ME(R[x],R[y],d-1);Up(x);return x;}
	I void SP(int x,int y,int &a,int &now,int d,int l=0,int r=INF){if(!now) return;if(x<=l&&r<=y){a=now;now=0;return;}a=++cnt;int m=l+r>>1;P(now,d);x<=m&&(SP(x,y,L[a],L[now],d-1,l,m),0);y>m&&(SP(x,y,R[a],R[now],d-1,m+1,r),0);Up(a);Up(now);}
	I void OR(int x,int d,int now,int l=0,int r=INF){if(!now||d==-1) return;P(now,d);if(!(F1[now]&x&F2[now])) return PF(now,x&F2[now],d);if(x>>d&1) PF(L[now],(1<<d),d-1),R[now]=ME(R[now],L[now],d-1),L[now]=0;int m=l+r>>1;OR(x&(~(1<<d)),d-1,L[now],l,m);OR(x&(~(1<<d)),d-1,R[now],m+1,r);Up(now);}
	I void dfs(int now,int d,int w=0){if(!now) return;if(d==-1){printf("%d ",w);return;}P(now,d);dfs(L[now],d-1,w);dfs(R[now],d-1,w|(1<<d));}
}
int main(){
//	freopen("1.in","r",stdin);freopen("2.out","w",stdout);
	int i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&x),Trie::Ins(x,Ro,19);while(m--){
		scanf("%d%d%d",&op,&x,&y);Trie::SP(x,y,R1,Ro,19);
		if(op==1) scanf("%d",&z),Trie::PF(R1,INF,19),Trie::OR(INF^z,19,R1),Trie::PF(R1,INF,19);
		else if(op==2) scanf("%d",&z),Trie::OR(z,19,R1);
		else if(op==3) scanf("%d",&z),Trie::PF(R1,z,19);
		else printf("%d\n",Trie::S[R1]);
		//cerr<<"dfs ";Trie::dfs(R1,19);Pc('\n');
		Ro=Trie::ME(R1,Ro,19);
	}
}