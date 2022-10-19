#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 5000
#define M 500000
#define mod 1000000007
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int T,n,x;ll ToT;
int main(){
	re int i;scanf("%d",&T);while(T--){
		ToT=0;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&x),ToT+=x;ToT%=n;printf("%lld\n",ToT*(n-ToT)); 
	}
}