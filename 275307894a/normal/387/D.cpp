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
#define N 1000
#define M 30000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,x,S,T,X[N+5],Y[N+5],d[N+5],Ns[N+5],Ans=1e9,ToT,cnt;queue<int> Q;
struct yyy{int to,w,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5<<2];I void add(int x,int y,int z){f[head]=(yyy){y,z,h[x]};h[x]=head++;}}s;
I void con(int x,int y,int z){s.add(x,y,z);s.add(y,x,0);}I int bfs(){
	RI i;while(!Q.empty()) Q.pop();Q.push(S);Me(d,0x3f);d[S]=0;Ns[S]=s.h[S];while(!Q.empty())for(x=Q.front(),Q.pop(),i=s.h[x];~i;i=tmp.z){
		tmp=s.f[i];if(!tmp.w||d[tmp.to]<1e9) continue;d[tmp.to]=d[x]+1;Q.push(tmp.to);Ns[tmp.to]=s.h[tmp.to];if(tmp.to==T) return 1;
	}return 0;
}
I int dfs(int x,int sum){
	if(x==T) return sum;yyy tmp;RI i,pus=0,k;for(i=Ns[x];~i;i=tmp.z){
		tmp=s.f[i];if(!tmp.w||d[tmp.to]!=d[x]+1) continue;Ns[x]=i;k=dfs(tmp.to,min(sum,tmp.w));if(!k) d[tmp.to]=1e9;s.f[i].w-=k;s.f[i^1].w+=k;sum-=k;pus+=k;if(!sum) break;
	}return pus;
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);S=0;T=2*n+1;for(i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]);for(i=1;i<=n;i++){
		ToT=3*n-2;s.head=0;Me(s.h,-1);for(j=1;j<=m;j++) (X[j]==i||Y[j]==i)?(ToT--):(con(X[j],Y[j]+n,1e9),ToT++);
		for(j=1;j<=n;j++) con(S,j,1),con(j+n,T,1);while(bfs()) ToT-=2*dfs(S,1e9);Ans=min(Ans,ToT);
	}printf("%d\n",Ans);
}