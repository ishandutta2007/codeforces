#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k, m, curcost=0, have=0, ans=0;
int l[N], r[N], c[N], p[N], use[N];
vector<pair<int, int> > add[N], rem[N];
set<pair<int, int> > s, extra;

int32_t main()
{
	IOS;
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i]>>c[i]>>p[i];
		add[l[i]].push_back({p[i], i});
		rem[r[i]+1].push_back({p[i], i});
	}
	for(int i=1;i<=n;i++)
	{
		for(auto &it:add[i])
			extra.insert(it);
		for(auto &it:rem[i])
		{
			if(s.find(it)!=s.end())
			{
				int idx=it.second;
				curcost-=use[idx]*it.first;
				have-=use[idx];
				use[idx]=0;
				s.erase(it);
			}
			if(extra.find(it)!=extra.end())
			{
				int idx=it.second;
				curcost-=use[idx]*it.first;
				have-=use[idx];
				use[idx]=0;
				extra.erase(it);
			}
		}
		while(extra.size() && s.size() && (extra.begin()->first) < (s.rbegin()->first))
		{
			auto it=*(--s.end());
			int idx=it.second;
			curcost-=use[idx]*it.first;
			have-=use[idx];
			use[idx]=0;
			s.erase(it);
			extra.insert(it);
			{
				int reqd=k-have;
				auto it=*extra.begin();
				int idx=it.second;
				int current=c[idx]-use[idx];
				if(current<=reqd)
				{
					s.insert(it);
					extra.erase(it);
					have+=current;
					use[idx]+=current;
					curcost+=current*it.first;
					reqd-=current;
				}
				else
				{
					use[idx]+=reqd;
					have+=reqd;
					curcost+=reqd*it.first;
					reqd-=reqd;
					s.insert(it);
				}
			}
		}
		while(have<k && extra.size())
		{
			vector<pair<int, int> > temp, temp2;
			int reqd=k-have;
			for(auto &it:extra)
			{
				int idx=it.second;
				int current=c[idx]-use[idx];
				if(current<=reqd)
				{
					temp.push_back(it);
					have+=current;
					use[idx]+=current;
					curcost+=current*it.first;
					reqd-=current;
				}
				else
				{
					use[idx]+=reqd;
					have+=reqd;
					curcost+=reqd*it.first;
					reqd-=reqd;
					temp2.push_back(it);
				}
				if(reqd==0)
					break;
			}
			for(auto &it:temp)
			{
				s.insert(it);
				extra.erase(it);
			}
			for(auto &it:temp2)
				s.insert(it);
		}
		ans+=curcost;
	}	
	cout<<ans;
	return 0;
}