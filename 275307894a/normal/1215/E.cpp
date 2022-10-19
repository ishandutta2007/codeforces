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
#define N 400000
#define K 20
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,x,A[N+5],Maxn,F[N+5];ll ToT,W[K+5][K+5],dp[(1<<K)+5];vector<int> Id[K+5];
int main(){
///////	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Id[A[i]].push_back(i),Maxn=max(Maxn,A[i]);
	for(i=1;i<=Maxn;i++){
		Me(F,0);for(j=0;j<Id[i].size();j++) F[Id[i][j]]++;for(j=1;j<=n;j++) F[j]+=F[j-1];
		for(j=1;j<=n;j++) W[i][A[j]]+=F[j];
	}Me(dp,0x3f);dp[0]=0;
	for(i=1;i<(1<<Maxn);i++){
		for(j=1;j<=Maxn;j++){if(!(i>>(j-1)&1)) continue; 
			x=i^(1<<j-1);ToT=dp[x];for(h=1;h<=Maxn;h++) (x>>(h-1)&1)&&(ToT+=W[j][h]);dp[i]=min(dp[i],ToT);
		}
	}printf("%lld\n",dp[(1<<Maxn)-1]);
}