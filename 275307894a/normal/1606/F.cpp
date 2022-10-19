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
#define N 200000
#define K 450
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
int n,k,m,x,y,Ans[N+5],X[N+5],Y[N+5],Ks;
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
namespace Solve1{
	struct Ques{int w,id;};vector<Ques> S[N+5];int F[N+5]; 
	I void dfs(int x,int La){RI i;yyy tmp;for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(dfs(tmp.to,x),F[x]+=max(F[tmp.to]-Ks,1));} 
	I void Make(){
		RI i,j;for(i=1;i<=m;i++) Y[i]<=k&&(S[Y[i]].push_back((Ques){X[i],i}),0);
		for(i=0;i<=k;i++){
			if(!S[i].size()) continue;Ks=i;Me(F,0);dfs(1,0);for(j=0;j<S[i].size();j++) Ans[S[i][j].id]=F[S[i][j].w];
		}
	}
}
namespace Solve2{
	int F[N+5][K+5],G[K+5],siz[N+5];
	I void dfs(int x,int La){
		yyy tmp;RI i,j,h;F[x][0]=0;siz[x]=1;for(i=s.h[x];i;i=tmp.z){
			tmp=s.f[i];if(tmp.to==La) continue;dfs(tmp.to,x);memcpy(G,F[x],sizeof(G));
			for(j=0;j<=siz[x]/k;j++){
				F[x][j]=max(F[x][j],G[j]+1);for(h=0;h<=siz[tmp.to]/k;h++) F[x][j+h+1]=max(F[x][j+h+1],G[j]+F[tmp.to][h]);
			}siz[x]+=siz[tmp.to];
		}
	}
	I void Make(){
		RI i,j;Me(F,-0x3f);Ks=n/k;dfs(1,0);
		for(i=1;i<=m;i++) if(Y[i]>k){for(j=0;j<=siz[X[i]]/Y[i];j++) Ans[i]=max(Ans[i],F[X[i]][j]-Y[i]*j);}
	} 
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d",&n);k=sqrt(n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);scanf("%d",&m);for(i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]);
	Solve1::Make();Solve2::Make();for(i=1;i<=m;i++) printf("%d\n",Ans[i]);
}