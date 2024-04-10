#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define INF ((ll)1e9)

ll n,b[3][N],ans=INF;
map <ll,ll> a[3];
set <pair<pair<ll,ll>,ll> > s;
multiset <ll> res;

void update(ll id,ll x)
{
	auto it=s.upper_bound({{id,N},0});it--;
	ll l=it->first.first,r=it->first.second,w=it->second;
	if(w>x)return ;
	s.erase(it);res.erase(res.find(l+w));
	if(id!=r)s.insert({{id+1,r},w}),res.insert(id+1+w);
	while(1)
	{
		it=s.upper_bound({{id,N},0});
		if(it==s.begin())break;
		it--;
		if(it->second>x)break;
		res.erase(res.find(it->first.first+it->second));
		l=it->first.first;
		s.erase(it);
	}
	s.insert({{l,id},x});
	res.insert(l+x);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int p=0;p<3;p++)
		for(int i=1;i<=n;i++)
		{
			cin>>b[p][i];
			if(!a[p][b[p][i]])a[p][b[p][i]]=i;
		}
	s.insert({{0,n},0});res.insert(0);
	for(auto u:a[1])
	{
		ll id0=a[0][u.first],id2=a[2][u.first];
		if(!id0 && !id2)update(u.second-1,INF);
		else if(!id0)update(u.second-1,id2);
	}
	for(auto u:a[2])
	{
		ll id0=a[0][u.first],id1=a[1][u.first];
		if(!id0 && !id1)update(n,u.second);
	}
	for(int i=n;i>=0;i--)
	{
		ans=min(ans,*res.begin()+i);
		if(a[0][b[0][i]]!=i)continue;
		ll id1=a[1][b[0][i]],id2=a[2][b[0][i]];
		if(!id1 && !id2)break;
		if(!id1)update(n,id2);
		else if(!id2)update(id1-1,INF);
		else update(id1-1,id2);
	}
	cout<<ans<<"\n";
	return 0;
}