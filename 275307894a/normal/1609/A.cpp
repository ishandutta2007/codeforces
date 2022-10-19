#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define U unsigned int
#define db double
#define lb long db
#define N (100000+5)
#define M ((1<<11)+5)
#define mod 1000000001
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
int T,n,Mx;ll A[N],Ans,Cnt;
I void Solve(){
	int i;scanf("%d",&n);Cnt=Ans=0;for(i=1;i<=n;i++){scanf("%lld",&A[i]);while(A[i]%2==0) Cnt++,A[i]/=2;}
	Mx=1;for(i=2;i<=n;i++) if(A[Mx]<A[i]) Mx=i;for(i=1;i<=n;i++) {if(i==Mx) Ans+=(A[i]<<Cnt);else Ans+=A[i];}
	printf("%lld\n",Ans);
}
int main(){
////	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}