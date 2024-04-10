#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (250000+5)
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
using namespace std;
int n,m,k,T,x,A[N];ll Ans,Q[N];
I void Solve(){
	int i,j;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]),Q[i]=Q[i-1]+A[i];
	Ans=0;if(k<=n) {
		for(j=k;j<=n;j++) Ans=max(Ans,Q[j]-Q[j-k]+1ll*k*(k-1)/2);printf("%lld\n",Ans);return;
	}
	Ans=Q[n]+1ll*(k-1)*n-1ll*n*(n-1)/2;printf("%lld\n",Ans);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}