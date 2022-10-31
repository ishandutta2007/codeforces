#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
#define P 1000000007
const int N=1000005;
int T,m,d,w,lim,x;
il int gcd(ct a,ct b){return !b?a:gcd(b,a%b);}
int main(){
	scanf("%d",&T);
	while(T--) scanf("%d%d%d",&m,&d,&w),w/=gcd(w,d-1),lim=(m<d?m:d)-1,x=lim-lim%w-1,printf("%lld\n",1ll*(lim-x)*(lim/w)+1ll*(x/w+1)*(x/w)/2*w);
	return 0;
}