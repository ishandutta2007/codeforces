#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[105],c[200005];ll b[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll x;scanf("%lld",&x);b[i]=x;int t=0;
		while(x%2==0)x/=2,t++;a[t]++;c[i]=t;
	}
	int ans=0,id=-1;
	for(int i=0;i<=100;i++)if(ans<a[i])ans=a[i],id=i;
	printf("%d\n",n-ans);
	for(int i=1;i<=n;i++)if(c[i]!=id)printf("%lld ",b[i]);
	return 0;
}