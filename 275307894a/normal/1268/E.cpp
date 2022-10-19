#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M ((1<<14)+5)
#define K (700+5)
#define mod 64123
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
int n,m,Ct[N],B[N],Bh,X[N],Y[N],cnt,Pl[N],Mx[N],Mi[N],dh,dfn[N],st[N],H,low[N],g[N],f[N];map<int,int> F[N];
I void Tarjan(int x,int La){
	f[x]=1;dfn[x]=low[x]=++dh;st[++H]=x;for(Edge i:S[x]){if(i.to==La) continue;
		if(dfn[i.to]) {low[x]=min(low[x],dfn[i.to]);continue;}Tarjan(i.to,x);low[x]=min(low[x],low[i.to]);
		if(low[i.to]>=dfn[x]){Bh=0;++cnt;int Lp=x;while(st[H+1]^i.to) Pl[B[++Bh]=F[Lp][st[H]]]=cnt,Lp=st[H--];Pl[B[++Bh]=F[x][Lp]]=cnt;for(int j=1;j<=Bh;j++) if(B[j]<min(B[j%Bh+1],B[(j-2+Bh)%Bh+1])) Ct[cnt]++;Bh=0;}
	}
}
int main(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]),F[X[i]][Y[i]]=F[Y[i]][X[i]]=i,S[X[i]].PB((Edge){Y[i],i}),S[Y[i]].PB((Edge){X[i],i});
	Me(Mx,-0x3f);Me(Mi,0x3f);Tarjan(1,0);for(i=1;i<=m;i++) Mi[Pl[i]]=min(Mi[Pl[i]],i),Mx[Pl[i]]=max(Mx[Pl[i]],i);for(i=m;i;i--){
		f[X[i]]=f[Y[i]]=f[X[i]]+f[Y[i]];if(i==Mx[Pl[i]]) g[Pl[i]]=f[X[i]];else if(i==Mi[Pl[i]]&&Ct[Pl[i]]==1) f[X[i]]-=g[Pl[i]],f[Y[i]]-=g[Pl[i]];
	}for(i=1;i<=n;i++) printf("%d ",f[i]-1);
}