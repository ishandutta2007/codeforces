#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int ans,n;
ll a[maxn],b[maxn],k,x;
int main(){
	scanf("%d%lld%lld",&n,&k,&x);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ri i=1;i<n;++i)b[i]=max(0ll,(a[i+1]-a[i]-1)/x);
	sort(b+1,b+n);
	ans=n;
	for(ri i=1;i<n;++i)
		if(k>=b[i])
			k-=b[i],--ans;
		else break;
	printf("%d",ans);
	return 0;
}