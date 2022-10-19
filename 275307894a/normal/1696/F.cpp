#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> G[N];
int Rt,n,m,k,x,y,z,D[N][N],B[N],Bh,C[N],Ch,fa[N];char s[N][N][N];
I void dfs(int x,int La,int Id,int ds){D[Id][x]=ds;for(int i:G[x]) i^La&&(dfs(i,x,Id,ds+1),0);}
I void Solve(){
	int i,j,h,k;scanf("%d",&n);for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) scanf("%s",s[i][j]+1),Mc(s[j][i],s[i][j]);
	Rt=1;for(i=2;i<=n;i++){
		for(j=1;j<=n;j++) G[j].clear(),fa[j]=0;B[Bh=1]=i;fa[i]=Rt;for(j=1;j<=n;j++) s[i][j][Rt]^'0'&&(B[++Bh]=j,fa[j]=Rt);
		while(1){
			Ch=0;for(j=1;j<=n;j++) {if(fa[j]) continue;for(h=1;h<=Bh;h++) if(s[fa[B[h]]][j][B[h]]^'0') {C[++Ch]=j;fa[j]=B[h];break;}}
			if(!Ch) break;Bh=Ch;Mc(B,C);
		}int Ps=0;for(j=2;j<=n;j++) if(!fa[j]) Ps=1;if(Ps) continue;
		for(j=2;j<=n;j++) G[fa[j]].PB(j),G[j].PB(fa[j]);for(j=1;j<=n;j++) dfs(j,j,j,0);
		for(j=1;j<=n;j++) for(h=j+1;h<=n;h++) for(k=1;k<=n;k++) if((s[j][h][k]-'0')^(D[j][k]==D[h][k])) {Ps=1;break;}
		if(Ps) continue;puts("Yes");for(j=2;j<=n;j++) printf("%d %d\n",j,fa[j]);return;
	}puts("No");
}
int main(){
//////	freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}