#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
#define P 998244353
typedef long long ll;
#define rll register ll
#define cll const ll
int a[N],n,m;
int main(){ 
	scanf("%d%d",&n,&m);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n),n=std::unique(a+1,a+1+n)-a-1;
	for(i=n;i;--i) a[i]-=a[i-1];
	n=(n<m?n:m);
	for(i=1;i<=n;++i) printf("%d\n",a[i]);
	m-=n;
	while(m--) puts("0");
	return 0;
}