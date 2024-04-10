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
int T;ll n;
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--){
		scanf("%lld",&n);n+=n&1;if(n<=6) printf("15\n");
		else printf("%lld\n",n*5/2);
	}
}