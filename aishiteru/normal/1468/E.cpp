#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll 
#define P 998244353
#define fir first
#define sec second
const int N=1000005;
int T,a[N],n;
int main(){ 
	scanf("%d",&T);
	while(T--)
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]),std::sort(a+1,a+1+4),printf("%lld\n",(0ll+a[1])*a[3]);
	return 0;
}