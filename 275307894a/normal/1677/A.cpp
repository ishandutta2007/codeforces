#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (5000+5)
#define M (220+5)
#define K (12+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int T,n,F1[N][N],F2[N][N],x,y,A[N];ll Ans;
I void Solve(){
	int i,j;Ans=0;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=0;i<=n+1;i++) for(j=1;j<=n;j++) F1[i][j]=F2[i][j]=0;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) F1[i][j]=F1[i-1][j]+(j>=A[i]);for(i=n;i;i--) for(j=1;j<=n;j++) F2[i][j]=F2[i+1][j]+(j>A[i]);
	for(i=n;i;i--){
		for(j=1;j<i;j++) Ans+=F1[j-1][A[i]]*F2[i+1][A[j]];
	}printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}