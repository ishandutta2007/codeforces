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
#define N (1000+5)
#define M (N*200)+5
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
int T,n,A[N+5][N+5],B[N+5][N+5],Ans;vector<int> S[N+5<<1];
I void Solve(){
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&A[i][j]);
	Ans=0;for(i=1;i<=2*n;i++) S[i].clear();for(i=1;i<=n;i++) for(j=1;j<=n;j++) S[i+j].PB(A[i][j]);
	for(i=2;i<=n*2;i+=4) for(j=0;j<S[i].size();j+=2) Ans^=S[i][j];
	for(i=1;i<=n;i++) for(j=1;j<=n/2;j++) swap(A[i][j],A[i][n-j+1]);
	for(i=1;i<=2*n;i++) S[i].clear();for(i=1;i<=n;i++) for(j=1;j<=n;j++) S[i+j].PB(A[i][j]);
	for(i=2;i<=n*2;i+=4) for(j=0;j<S[i].size();j+=2) Ans^=S[i][j];
	printf("%d\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}