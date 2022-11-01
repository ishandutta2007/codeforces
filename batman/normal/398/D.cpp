#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)51*1000)

ll n,m,q,o,num[N];
bool on[N];
set <ll> s[N];

void add(ll x,ll y)
{
	if((ll)s[x].size()>(ll)s[y].size())swap(x,y);
	s[x].insert(y);
	num[y]+=on[x];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q>>o;
    for(int i=0;i<o;i++)
    {
    	ll x;
    	cin>>x;
    	on[x]=1;
	}
	for(int i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=q;i++)
	{
		char c;
		ll x,y;
		cin>>c>>x;
		if(c=='O'){on[x]=1;for(auto u:s[x])num[u]++;}
		if(c=='F'){on[x]=0;for(auto u:s[x])num[u]--;}
		if(c=='A'){cin>>y;add(x,y);}
		if(c=='D'){cin>>y;if(!s[x].count(y))swap(x,y);s[x].erase(y);num[y]-=on[x];}
		if(c=='C'){ll res=num[x];for(auto u:s[x])res+=on[u];cout<<res<<"\n";}
	}
    return 0;
}