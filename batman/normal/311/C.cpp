#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)11*1000)
#define INF ((ll)1e18+10)

ll h,n,m,k,mini[K],a[N],c[N];
bool mark[N];
set <pair<ll,ll> > s;
vector <pair<ll,ll> > e[K];

void update()
{
	set <pair<ll,ll> > st;
	for(int i=0;i<k;i++)st.insert({mini[i],i});
	while(st.size())
	{
		ll x=st.begin()->second;st.erase(st.begin());
		for(auto u:e[x])
			if(mini[u.first]>mini[x]+u.second)
				st.erase({mini[u.first],u.first}),
				mini[u.first]=mini[x]+u.second,
				st.insert({mini[u.first],u.first});
	}
	for(int i=1;i<=n;i++)
		if(!mark[i] && mini[a[i]%k]<=a[i])
			mark[i]=1,s.insert({-c[i],i});
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>h>>n>>m>>k;
	for(int i=0;i<k;i++)mini[i]=INF;mini[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]%k==1)mark[i]=1,s.insert({-c[i],i});
	}
	while(m--)
	{
		ll t,x,y;
		cin>>t;
		if(t==1)
		{
			cin>>x;
			for(int i=0;i<k;i++)e[i].push_back({(i+x)%k,x});
			update();
		}
		if(t==2)
		{
			cin>>x>>y;
			if(s.count({-c[x],x}))
			{
				s.erase({-c[x],x});
				s.insert({-c[x]+y,x});
			}
			c[x]-=y;
		}
		if(t==3)
		{
			if(!s.size())cout<<"0\n";
			else
			{
				cout<<-s.begin()->first<<"\n";
				s.erase(s.begin());
			}
		}
	}
	return 0;
}