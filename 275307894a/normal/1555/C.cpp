#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 250000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,n,A[N+5],Q1[N+5],Q2[N+5],Ans; 
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);Q1[n+1]=0;for(i=n;i;i--)Q1[i]=Q1[i+1]+A[i];for(i=1;i<=n;i++) scanf("%d",&A[i]),Q2[i]=Q2[i-1]+A[i];
		Ans=2e9;for(i=1;i<=n;i++) Ans=min(Ans,max(Q1[i+1],Q2[i-1]));printf("%d\n",Ans);
	}
}