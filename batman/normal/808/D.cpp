#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,sum1,sum2,a[N];
multiset <ll> s1,s2;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],sum2+=a[i],s2.insert(a[i]);
	if(sum2%2==0 && s2.count(sum2/2))return cout<<"YES",0;
	for(int i=0;i<n;i++)
	{
		sum1+=a[i];
		sum2-=a[i];
		s2.erase(s2.find(a[i]));
		s1.insert(a[i]);
		if(sum2==sum1)return cout<<"YES",0;
		if(sum2>sum1)
		{
			if((sum2-sum1)%2==0 && s2.count((sum2-sum1)/2))return cout<<"YES",0;
		}
		else
		{
			if((sum1-sum2)%2==0 && s1.count((sum1-sum2)/2))return cout<<"YES",0;
		}
	}
	cout<<"NO";
	return 0;
}