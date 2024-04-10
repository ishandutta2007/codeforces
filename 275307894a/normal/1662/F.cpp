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
using namespace std;deque<int> Q;
struct yyy{int to,z;}tmp;struct ljb{int head,h[N*40];yyy f[N*110];I void add(int x,int y,int z){if(!x||!y) return;f[++head]=(yyy){y,z?h[x]+1:-h[x]-1};h[x]=head;}}s;
int T,n,m,k,x,cnt,dp[N*40],A[N],S,t,Pt;
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	int I1[N<<2],I2[N<<2];I void Cl(){for(int i=1;i<=n*4;i++) I1[i]=I2[i]=0;for(int i=1;i<=Pt;i++) s.h[i]=0;s.head=Pt=0;}
	I void Ins(int x,int id,int l=1,int r=n,int now=1) {s.add(++Pt,I1[now],0);I1[now]=Pt;s.add(I2[now],++Pt,0);I2[now]=Pt;s.add(I1[now],id,1);s.add(id,I2[now],1);if(l==r) return;int m=l+r>>1;x<=m?Ins(x,id,l,m,ls):Ins(x,id,m+1,r,rs);}
	I void Push(int x,int y,int id,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return s.add(id,I1[now],1),s.add(I2[now],id,1);int m=l+r>>1;x<=m&&(Push(x,y,id,l,m,ls),0);y>m&&(Push(x,y,id,m+1,r,rs),0);}
}
struct Ques{int w,id;}P[N];I bool cmp(Ques x,Ques y){return x.w<y.w;}
I void Solve(){
	int i,j;scanf("%d%d%d",&n,&S,&t);for(i=1;i<=n;i++) scanf("%d",&A[i]),P[i]=(Ques){A[i],i};sort(P+1,P+n+1,cmp);
	Tree::Cl();Pt=n;for(i=n;i;i--)Tree::Ins(P[i].id,P[i].id),Tree::Push(max(P[i].id-P[i].w,1),min(n,P[i].id+P[i].w),P[i].id);
	for(i=1;i<=Pt;i++) dp[i]=1e9;dp[S]=0;Q.push_front(S);while(!Q.empty()) {x=Q.front(),Q.pop_front();for(int i=s.h[x];i;i=abs(tmp.z)-1)tmp=s.f[i],dp[tmp.to]>dp[x]+(tmp.z>0?1:0)&&(dp[tmp.to]=dp[x]+(tmp.z>0?1:0),(tmp.z>0?1:0)?Q.push_back(tmp.to):Q.push_front(tmp.to),0);}
	printf("%d\n",dp[t]/2);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}