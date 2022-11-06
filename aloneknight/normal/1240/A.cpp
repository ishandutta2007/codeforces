#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,x,a,y,b;ll c,k,p[N];
inline ll chk(int d)
{
	int d3=d/c,d1=d/a-d3,d2=d/b-d3;
	return p[d3]*(x+y)+(p[d3+d1]-p[d3])*x+(p[d3+d1+d2]-p[d3+d1])*y;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&p[i]),p[i]/=100;
		sort(p+1,p+n+1);reverse(p+1,p+n+1);
		for(int i=1;i<=n;i++)p[i]+=p[i-1];
		scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
		c=1ll*a*b/__gcd(a,b);
		if(x<y)swap(a,b),swap(x,y);
		int l=1,r=n,mid,ans=-1;
		while(l<=r)if(chk(mid=l+r>>1)>=k)ans=mid,r=mid-1;else l=mid+1;
		printf("%d\n",ans);
	}
	return 0;
}