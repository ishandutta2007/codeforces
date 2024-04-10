#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=2e5+5;

int n;
double T;
pair<double, double> a[N];

int32_t main()
{
	IOS;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].second;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
	}
	sort(a+1, a+n+1);
	double neg=0, pos=0, negvals=0, posvals=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].first<T)
		{
			neg+=(T-a[i].first)*a[i].second;
			negvals+=a[i].second;
		}
		if(a[i].first>T)
		{
			pos+=(a[i].first-T)*a[i].second;
			posvals+=a[i].second;
		}
	}
	if(pos>neg)
	{
		double adjust=neg;
		double ans=negvals;
		for(int i=1;i<=n;i++)
		{
			if(a[i].first<T)
				continue;
			double curadj=(a[i].first-T)*a[i].second;
			if(curadj>adjust)
			{
				ans+=(double)adjust/(a[i].first-T);
				adjust=0;
				break;
			}
			ans+=a[i].second;
			adjust-=curadj;
		}
		cout<<fixed<<setprecision(12)<<ans;
	}
	else
	{
		double adjust=pos;
		double ans=posvals;
		for(int i=n;i>=1;i--)
		{
			if(a[i].first>T)
				continue;
			double curadj=(T-a[i].first)*a[i].second;
			if(curadj>adjust)
			{
				ans+=adjust/(T-a[i].first);
				adjust=0;
				break;
			}
			ans+=a[i].second;
			adjust-=curadj;
		}
		cout<<fixed<<setprecision(12)<<ans;
	}
	return 0;
}