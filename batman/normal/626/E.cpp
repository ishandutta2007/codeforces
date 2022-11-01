#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)

ll n,a[N],sum[N];
ld ans;
pair <ll,ll> res;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(ll i=0;i<n;i++)sum[i]=((i)?sum[i-1]:0)+a[i];
	for(ll i=0;i<n;i++)
	{
		ll l=-1,r=min(i+1,n-i);
		for(ll j=0;j<50;j++)
		{
			ll m1=l+(r-l)/3,m2=r-(r-l)/3;
			ld p1=sum[n-1]-sum[n-1-m1]+sum[i]-((i-1-m1>=0)?sum[i-1-m1]:0);p1/=(ld)2*m1+1;p1-=a[i];
			ld p2=sum[n-1]-sum[n-1-m2]+sum[i]-((i-1-m2>=0)?sum[i-1-m2]:0);p2/=(ld)m2*2+1;p2-=a[i];
			if(p1<=p2)l=m1;
			else r=m2;
		}
		for(ll j=l;j<=r;j++)
		{
			ld p1=sum[n-1]-sum[n-1-j]+sum[i]-((i-1-j>=0)?sum[i-1-j]:0);p1/=(ld)2*j+1;p1-=a[i];
			if(j>=0 && j<min(i+1,n-i) && ans<p1)ans=p1,res={j,i};
		}
	}
	cout<<res.first*2+1<<"\n";
	for(ll i=n-1,j=0;j<res.first;j++,i--)cout<<a[i]<<" ";
	for(ll i=res.second,j=0;j<=res.first;j++,i--)cout<<a[i]<<" ";
	return 0;
}