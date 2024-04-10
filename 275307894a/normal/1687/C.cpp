#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (N-5)
#define K (1500+5)
#define mod 998244353
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
#include <vector>
using namespace std;vector<int> Id[N];
int H,La[N],Fl[N],F[N],n,m,k,x,y,T,A[N],B[N];ll Q[N];
I int GF(int x){return F[x]^x?F[x]=GF(F[x]):x;}
I void dfs(int x,int y){
	while((x=GF(x))<y){
		F[x]=x+1;Fl[La[x]]=1;for(int i:Id[x]) if((!Q[i]||Fl[La[i]])) dfs(min(i,x),max(i,x));
	}
}
I void Solve(){
	int i;scanf("%d%d",&n,&m);for(i=0;i<=n;i++) F[i]=i,Fl[i]=0,Id[i].clear();for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]),Q[i]=Q[i-1]+A[i]-B[i];
	La[0]=0;for(i=1;i<=n;i++) La[i]=(Q[i]?La[i-1]:i);while(m--) scanf("%d%d",&x,&y),Id[x-1].PB(y),Id[y].PB(x-1);
	for(i=0;i<=n;i++) for(int j:Id[i]) if((!Q[j]||Fl[La[j]])&&(!Q[i]||Fl[La[i]])) dfs(min(i,j),max(i,j));for(i=0;i<=n;i++) if(Q[i]&&!Fl[La[i]]) {puts("NO");return;}puts("YES");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}