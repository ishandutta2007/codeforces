#include<cstdio>
#include<algorithm>
#define N 200000
#define ll long long
using namespace std;
int n,T;ll a[N+5],k,pus;
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);for(i=1;i<=n;i++) scanf("%lld",&a[i]);sort(a+1,a+n+1);
		pus=a[2]-a[1];for(i=3;i<=n;i++) pus=__gcd(pus,a[i]-a[i-1]);printf("%s\n",((k-a[1])%pus)?"NO":"YES");
	}
}