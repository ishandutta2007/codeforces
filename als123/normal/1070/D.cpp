#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
int n,k;
LL a[maxn];
LL b[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	LL ans=0,t,c;
	for(int i=1;i<=n+1;i++) {
		t=(a[i]+b[i])/k;
		c=min(t*k,b[i]);
		b[i]-=c;
		a[i]-=t*k-c;		
		if(b[i]) {
			++t;
			a[i]=max(0LL,a[i]-k+b[i]);
		}
		b[i+1]=a[i];
		ans+=t;
//		printf("%lld %lld %lld\n",a[i],b[i],t);
	}
	printf("%lld\n",ans);
	return 0;
}