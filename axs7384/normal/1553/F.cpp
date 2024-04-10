#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=350005;
const int mx=300000;
int a[N],si[N],qsi[N],m,n;
ll sum[N],qsum[N];
vector<int> v;
inline ll work(int l,int r,int p,int j)
{
	r=min(r,mx);
	int _si=si[r]-si[l-1]+qsi[r/m]-qsi[(l-1)/m];
	if (!_si)
		return 0;
	ll _sum=sum[r]-sum[l-1]+qsum[r/m]-qsum[(l-1)/m];
	return _sum-(ll)(j-1)*p*_si;
}
inline ll work2(int l,int r,int p,int j)
{
	r=min(r,mx);
	int _si=si[r]-si[l-1]+qsi[r/m]-qsi[(l-1)/m];
	if (!_si)
		return 0;
	ll _sum=sum[r]-sum[l-1]+qsum[r/m]-qsum[(l-1)/m];
	return (ll)_si*p-(ll)(j-1)*_sum;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
		// a[i]=i;
	m=500;
	ll ans=0;
	for (int i=1;i<=n;++i)
	{
		if (a[i]<=m)
		{
			for (int j=1;j<i;++j)
				ans+=a[i]%a[j]+a[j]%a[i];
			v.push_back(a[i]);
		}
		else
		{
			for (int j=0;j<(int)v.size();++j)
				ans+=a[i]%v[j]+v[j];
			for (int j=1;j<=mx/a[i];++j)
			{
				ans+=work(j*a[i],j*a[i]+a[i]-1,a[i],j);
			}
			for (int j=1;a[i]/j>=m;++j)
			{
				ans+=work2(a[i]/(j+1)+1,a[i]/j,a[i],j);
			}
			for (int j=a[i]/m+1;j<=mx/m;++j)
			{
				++qsi[j];
				qsum[j]+=a[i];
			}
			for (int j=a[i];j<(a[i]/m+1)*m;++j)
			{
				++si[j];
				sum[j]+=a[i];
			}
			// cout<<i<<endl;
			// for (int i=1;i<=10;++i)
			// 	cout<<i<<' '<<si[i]<<' '<<sum[i]<<endl;
			// puts("kuai");
			// for (int i=1;i<=5;++i)
			// 	cout<<i<<' '<<qsi[i]<<' '<<qsum[i]<<endl;
			// puts("");
		}
		printf("%lld ",ans);
	}
	// printf("%lld ",ans);
	return 0;
}