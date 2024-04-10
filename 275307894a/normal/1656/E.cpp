#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (480000+5)
#define M (50000+5)
#define K (200000+5)
#define mod 998244353
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
int n,m,k,T,x,y,col[N];vector<int> S[N];
I void dfs(int x,int w,int La){col[x]=w;for(int i:S[x]) i^La&&(dfs(i,-w,x),0);}
I void Solve(){int i;scanf("%d",&n);for(i=1;i<=n;i++) S[i].clear();for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);dfs(1,1,0);for(i=1;i<=n;i++) printf("%d ",col[i]*S[i].size());Pc('\n');}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}