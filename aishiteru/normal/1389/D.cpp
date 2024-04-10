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
int T,n,k,l1,r1,l2,r2;
template <class I> 
il I Max(I p,I q){return p>q?p:q;}
template <class I> 
il I Min(I p,I q){return p<q?p:q;}
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&n,&k,&l1,&r1,&l2,&r2);
		rll a=Max(l1,l2)-Min(r1,r2),b=Max(r1,r2)-Min(l1,l2),ans=1e17;
		for(it i=1;i<=n;++i) k<i*b?ans=Min(ans,i*a+k):ans=Min(ans,i*(a+b)+(k-i*b)*2ll);
		printf("%lld\n",(ans>0?ans:0));
	}
	return 0;
}