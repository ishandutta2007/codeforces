#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (201*1000)
ll n,q;
set <pair <ll,ll> > l,u;
map <ll,bool> mp;

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>q;
	l.insert({0,0}),l.insert({n+1,0}),u.insert({0,0}),u.insert({n+1,0});
	while(q--)
	{
		ll x,y;
		char c;
		cin>>x>>y>>c;
		if(mp[x])
		{
			cout<<"0\n";
			continue;
		}
		mp[x]=1;
		if(c=='L')
		{
			set <pair <ll,ll> >::iterator it_l=l.lower_bound({x,-1}),it_u=u.lower_bound({x,-1});
			it_l--,it_u--;
			ll ans;
			if(it_u->first<it_l->first) ans=x-it_l->first+it_l->second;
			else ans=x-it_u->first;	
			l.insert({x,ans});
			cout<<ans<<"\n";
		}
		else
		{
			set <pair <ll,ll> >::iterator it_l=l.lower_bound({x,-1}),it_u=u.lower_bound({x,-1});
			ll ans;
			if(it_u->first<it_l->first)ans=it_u->first-x+it_u->second;
			else ans=it_l->first-x;	
			u.insert({x,ans});
			cout<<ans<<"\n";
		}
	}
    return 0;
}