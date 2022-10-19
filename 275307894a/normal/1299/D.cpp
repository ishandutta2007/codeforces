#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (500+5)
#define K (700+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;struct Edge{int to,w;};vector<Edge> S[N]; 
int n,m,W[M][M],H,x,y,z,Pf[N],vis[N],d[N];ui A[M],Q[N];ll ToT,f[M],g[M],T1,T2;map<ui,int> Is,Fl[50];
I ui Merge(ui x,ui y){if((x&y)>1||!x||!y) return 0;ui z=0;for(int i=0;i<=31;i++)if(x>>i&1) for(int j=0;j<=31;j++)y>>j&1&&(z|=1u<<(i^j));return z;}
I void dfs(int x,ui w){if(Fl[x].count(w)) return;Fl[x][w]=1;if(x==32){A[Is[w]=++H]=w;return;}dfs(x+1,w);!(w>>x&1)&&(dfs(x+1,Merge(w,1u<<x|1)),0);}
I void FC(int x,int La){vis[x]=1;for(Edge i:S[x]){if(vis[i.to])i.to^La&&i.to^1&&d[i.to]<d[x]&&(T1=(i.w^Q[x]^Q[i.to]?Merge(1u<<(i.w^Q[x]^Q[i.to])|1,T1):0));else Q[i.to]=Q[x]^i.w,d[i.to]=d[x]+1,FC(i.to,x);}}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;dfs(1,1);scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),S[x].PB((Edge){y,z}),S[y].PB((Edge){x,z});
	Me(W,-1);for(i=1;i<=H;i++) for(j=1;j<=H;j++) W[i][j]=((A[i]&A[j])>1?-1:Is[Merge(A[i],A[j])]);
	f[Is[1]]=1;vis[1]=1;for(Edge i:S[1]) Pf[i.to]=1,Q[i.to]=i.w;for(i=2;i<=n;i++){
		if(!Pf[i]) continue;Mc(g,f);for(Edge j:S[i]){if(!Pf[j.to]) continue;
			T1=1;T2=j.w^Q[i]^Q[j.to];FC(i,1);Pf[i]=Pf[j.to]=0;if(!T1) break;x=Is[T1];for(h=1;h<=H;h++) ~W[h][x]&&(f[W[h][x]]=(f[W[h][x]]+f[h]*2)%mod);
			T1=(T2?Merge(T1,1u<<T2|1):0);x=Is[T1];for(h=1;h<=H;h++) ~W[h][x]&&(f[W[h][x]]=(f[W[h][x]]+g[h])%mod);
		}if(Pf[i]){Pf[i]=0;T1=1;FC(i,1);if(T1) for(x=Is[T1],j=1;j<=H;j++) f[W[j][x]]=(f[W[j][x]]+g[j])%mod;} 
	}for(i=1;i<=H;i++) ToT+=f[i];printf("%lld\n",ToT%mod);
}