#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=201*1000;

ll n,p,a[N],b[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	ld ex=1,s=0;
	for(int i=0;i<n;i++)
		s+=max((ld)0,((ld)ex*a[i]-b[i])/p);
	if(s<=ex)
	{
		ld l=1,r=4e18;
		for(int t=0;t<20;t++)
		{
			ld mid=sqrt(l*r),sum=0;
			for(int i=0;i<n;i++)
				sum+=max((ld)0,((ld)mid*a[i]-b[i])/p);
			if(sum<=mid)l=mid;
			else r=mid;
		}
		if(l>1e10)return cout<<-1,0;
		cout<<fixed<<setprecision(14)<<l<<"\n";	
	}
	else
	{
		ld l=0,r=1;
		for(int t=0;t<20;t++)
		{
			ld mid=l+(r-l)/2,sum=0;
			for(int i=0;i<n;i++)
				sum+=max((ld)0,((ld)mid*a[i]-b[i])/p);
			if(sum<=mid)l=mid;
			else r=mid;
		}
		cout<<fixed<<setprecision(14)<<l<<"\n";
		return 0;
	}
	return 0;
}