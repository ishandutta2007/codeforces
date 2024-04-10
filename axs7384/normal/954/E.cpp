#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
ll F,G,K;
const int N=200005;
pair<int,int> f[N],g[N];
double ans;
int a[N],b[N],n,t,cnt1,cnt2;
signed main()
{
	cin>>n>>t;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		ans+=a[i];
	}
	for (int j=1;j<=n;++j)
		cin>>b[j];
	for (int i=1;i<=n;++i)
	{
		if (b[i]<t)
			f[++cnt1]=make_pair(t-b[i],a[i]);
		if (b[i]>t)
			g[++cnt2]=make_pair(b[i]-t,a[i]);
	}
	sort(f+1,f+1+cnt1);
	sort(g+1,g+1+cnt2);
	for (int i=1;i<=cnt1;++i)
		F+=f[i].first*f[i].second;
	for (int i=1;i<=cnt2;++i)
		G+=g[i].first*g[i].second;
	if (F<=G)
	{
		K=G-F;
		for (int i=cnt2;i;--i)
		{
			if (K>=g[i].first*g[i].second)
			{
				K-=g[i].first*g[i].second;
				ans-=g[i].second;
			}
			else
			{
				ans-=(double)K/(double)g[i].first;
				break;
			}
		}
	}
	else
	{
		K=F-G;
		for (int i=cnt1;i;--i)
		{
			if (K>=f[i].first*f[i].second)
			{
				K-=f[i].first*f[i].second;
				ans-=f[i].second;
			}
			else
			{
				ans-=(double)K/(double)f[i].first;
				break;
			}
		}
	}
	printf("%.8lf",ans);
}