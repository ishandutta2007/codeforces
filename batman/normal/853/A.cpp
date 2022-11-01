#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,k,a[N],ans[N],res;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	set <pair<ll,ll> > s;
	for(int i=0;i<n+k;i++)
	{
		if(i<n)s.insert({a[i],i});
		if(i<k)continue;
		auto it=s.end();it--;
		ans[it->second]=i+1;
		res+=(it->first)*(i-it->second);
		s.erase(it);
	}
	cout<<res<<"\n";
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}