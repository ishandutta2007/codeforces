#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define K 50
#define mod 1000000007
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,k,T,x,y,z;ll B[N+5][2],Ans,now;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll calc(int x,int y){now=mpow(2,x-1)-(n%2==0)*2+mod;return mpow(now+1,y);}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		Ans=0;scanf("%d%d",&n,&k);if(n%2==0){
			for(i=k-1;~i;i--) Ans+=calc(n,k-i-1)*mpow(mpow(2,n),i)%mod;
		}Ans+=calc(n,k);printf("%lld\n",Ans%mod);
	}
}