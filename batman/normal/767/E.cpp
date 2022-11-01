#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,m,c[N],w[N],res;
pair <ll,ll> ans[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		ans[i]={c[i]/100,c[i]%100};c[i]%=100;
	}
	set <pair<ll,ll> > s;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
		if(c[i])s.insert({(100-c[i])*w[i],i});
		if(m-c[i]<0)
		{
			pair <ll,ll> x=*s.begin();s.erase(s.begin());
			m+=100;
			res+=x.first;
			ans[x.second].first++;
			ans[x.second].second=0;
		}
		m-=c[i];
	}
	cout<<res<<"\n";
	for(int i=0;i<n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}