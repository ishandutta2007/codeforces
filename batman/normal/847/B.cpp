#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,x,now=1;
vector <ll> v[N];
set <pair<ll,ll> > s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x;
	s.insert({x,0});
	v[0].push_back(x);
	for(int i=1;i<n;i++)
	{
		cin>>x;
		auto it=s.lower_bound({x,-N});
		if(it==s.begin())
		{
			v[now].push_back(x);
			s.insert({x,-now});
			now++;
			continue;
		}
		it--;
		ll id=it->second;
		v[-id].push_back(x);
		s.erase(it);
		s.insert({x,id});
	}
	for(int i=0;i<now;i++)
	{
		for(auto u:v[i])cout<<u<<" ";
		cout<<"\n";
	}
	return 0;
}