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
#define N 2000
#define M 1000000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,k,x,A[N+5],C[N+5],S,T,d[N+5],Ans,g[N+5],pre[N+5],La[N+5],F[N+5];
struct yyy{int to,w,g,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<3];I void add(int x,int y,int w,int g){f[head]=(yyy){y,w,g,h[x]};h[x]=head++;}}s;
I void Get(int x,int y,int w,int g){s.add(x,y,w,g);s.add(y,x,-w,0);}queue<int> Q;
I int EK(){
	RI i;Q.push(S);Me(d,0x3f);d[S]=0;g[S]=1e9;while(!Q.empty()){
		for(x=Q.front(),Q.pop(),i=s.h[x];~i;i=tmp.z){
			tmp=s.f[i];if(!tmp.g||d[tmp.to]<=d[x]+tmp.w)continue;d[tmp.to]=d[x]+tmp.w;g[tmp.to]=min(g[x],tmp.g);pre[tmp.to]=i;Q.push(tmp.to);
		}
	}return d[T]<1e9+7;
}
int main(){
	//freopen("1.in","r",stdin);
	RI i;Me(s.h,-1);scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&C[i]);S=0;T=2*n+1;
	for(i=1;i<=n;i++) Get(S,i,C[A[i]],1),Get(i,i+n,0,1),i^n&&(Get(i,i+1,0,k-1),0),Get(i+n,T,0,1),F[A[i]]&&(Get(i-1,F[A[i]]+n,-C[A[i]],1),0),F[A[i]]=i;
	while(EK()){Ans+=g[T]*d[T];x=T;while(x^S) s.f[pre[x]].g-=g[T],s.f[pre[x]^1].g+=g[T],x=s.f[pre[x]^1].to;}printf("%d\n",Ans);
}