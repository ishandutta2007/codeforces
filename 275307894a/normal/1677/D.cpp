#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1000000+5)
#define M (220+5)
#define K (12+5)
#define mod 998244353
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
int n,m,k,T,A[N],B[N];ll Ans;
I void Solve(){
	int i,j;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);
	Ans=1;for(i=1;i<=k;i++) B[i]=A[n-k+i];for(i=1;i<=n-k;i++) B[i+k]=A[i];
	for(i=1;i<=n;i++){if(B[i]>0&&B[i]+k>=i) {puts("0");return;}
	if(!B[i]) Ans=Ans*min(i,k+1)%mod;else if(B[i]==-1) Ans=Ans*i%mod;}printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}