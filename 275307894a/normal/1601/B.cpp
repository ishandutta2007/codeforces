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
#define N (300000+5)
#define M (N*50+5)
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
int n,x,Fl[N+5],Ans[N+5],A[N+5],B[N+5],La[N+5];vector<int> T[N+5];queue<int> Q;
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	vector<int> Id[N+5<<2];I void add(int x,int y,int z,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return Id[now].PB(z);int m=l+r>>1;x<=m&&(add(x,y,z,l,m,ls),0);y>m&&(add(x,y,z,m+1,r,rs),0);}
	I void Qry(int x,int y,int l=1,int r=n,int now=1){for(RI i:Id[now]) !Ans[i]&&(Ans[i]=Ans[y]+1,La[i]=x,Q.push(i),0);Id[now].clear();if(l==r) return;int m=l+r>>1;x<=m?Qry(x,y,l,m,ls):Qry(x,y,m+1,r,rs);}
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]),T[B[i]+i].PB(i);
	for(i=1;i<=n;i++) A[i]>=i?(Q.push(i),Ans[i]=1,La[i]=0,0):(Tree::add(i-A[i],i,i),0);while(!Q.empty()) {
		x=Q.front();Q.pop();for(RI i:T[x]) Tree::Qry(i,x);
	}
	//for(i=1;i<=n;i++) printf("%d\n",La[i]);
	if(!Ans[n]) {puts("-1");return 0;}printf("%d\n",Ans[n]);x=n;while(La[x]) printf("%d ",La[x]),x=La[x]+B[La[x]];printf("%d\n",La[x]);
}