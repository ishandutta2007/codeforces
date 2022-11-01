#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)

ll n,a[N],b[N];
set <pair<ll,pair<ll,ll> > > s;
bool flg;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;i++)cin>>b[i],b[i]+=b[i-1];
	if(a[n]>b[n]){flg=1;for(int i=1;i<=n;i++)swap(a[i],b[i]);}
	s.insert({0,{0,0}});
	for(int i=1;i<=n;i++)
	{
		ll j=lower_bound(b+1,b+n+1,a[i])-b;
		auto ex=s.lower_bound({b[j]-a[i],{-1,-1}});
		if(ex!=s.end() && ex->first==b[j]-a[i])
		{
			vector <ll> v1,v2;
			for(int p=ex->second.first+1;p<=i;p++)v1.push_back(p);
			for(int p=ex->second.second+1;p<=j;p++)v2.push_back(p);
			if(flg)v1.swap(v2);
			cout<<v1.size()<<"\n";for(auto u:v1)cout<<u<<" ";cout<<"\n";
			cout<<v2.size()<<"\n";for(auto u:v2)cout<<u<<" ";
			return 0;
		}
		s.insert({b[j]-a[i],{i,j}});
	}
    return 0;
}