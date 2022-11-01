#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

int n,strt,fnsh,g[N],c[N];
ll ans;
set <int> s;
set <pair<int,int> > s2;
vector <pair<pair<int,int>,int> > vec;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>strt>>fnsh;
	for(int i=1;i<n;i++)cin>>g[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(strt>fnsh)
	{
		strt=n-strt+1;
		fnsh=n-fnsh+1;
		reverse(g+1,g+n);
		reverse(c+1,c+n+1);
	}
	s.insert(c[strt]);
	int lst=strt-1,now=strt+1;
	for(int i=strt;i<fnsh;i++)
	{
		int max_need=-1;
		auto it=s2.lower_bound({g[i],0});
		if(s.count(g[i]) || (it!=s2.end() && it->first==g[i]))
		{
			s2.insert({c[i+1],i+1});
			continue;
		}
		while(1)
		{
			if(lst==0)return cout<<"-1\n",0;
			if(!s.count(g[lst]))
			{
				auto it=s2.lower_bound({g[lst],0});
				if(it!=s2.end() && it->first==g[lst])max_need=max(max_need,it->second);
				else return cout<<"-1\n",0;
			}
			lst--;
			s.insert(c[lst+1]);
			if(c[lst+1]==g[i])break;
		}
		while(now<=max_need)
		{
			s2.erase({c[now],now});
			s.insert(c[now]);
			now++;
		}
		s2.insert({c[i+1],i+1});
		vec.push_back({{i,now-1},lst+1});
	}
	ans=strt-lst-1;
	ans+=fnsh-lst-1;
	for(int i=(int)vec.size()-1;i>=0;)
	{
		int j=i-1;
		while(j>=0 && vec[j].first.first>=vec[i].first.second)j--;
		ans+=(vec[i].first.second-(j>=0?vec[j].second:strt))*2;
		i=j;
	}
	cout<<ans<<"\n";
	return 0;
}