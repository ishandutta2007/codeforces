#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 4000000
#define K 20
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,p;ll dp[N+5],ToT,F[N+5];
int main(){
//	freopen("1.in","r",stdin);
	re int i,j,h;scanf("%d%d",&n,&p);ToT=dp[1]=1;for(i=2;i<=n;i++) F[i]=1;for(i=2;i<=n;i++){
		F[i]=(F[i]+F[i-1])%p;dp[i]=(ToT+F[i])%p;ToT=(dp[i]+ToT)%p;
		for(j=i*2;j<=n;j+=i) F[j]=(F[j]+dp[i]-dp[i-1]+p)%p;
	}printf("%lld\n",dp[n]);
}