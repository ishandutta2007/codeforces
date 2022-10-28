#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100000;
int n,c;
int sum[MAXN+10],mn[MAXN+10],f[MAXN+10];
pair<int,int> q[MAXN+10];int h,t;
signed main()
{
	scanf("%lld%lld",&n,&c);
	h=1;
	for(int i=1,a;i<=n;++i)
	{
		scanf("%lld",&a);sum[i]=sum[i-1]+a;
		while(h<=t&&q[t].first>=a)--t;
		q[++t]=make_pair(a,i);
		if(i>c&&q[h].second==i-c)++h;
		mn[i]=q[h].first;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1]+sum[i]-sum[i-1];
		if(i>=c)f[i]=min(f[i],f[i-c]+sum[i]-sum[i-c]-mn[i]);
	}
	printf("%lld",f[n]);
	return 0;
}