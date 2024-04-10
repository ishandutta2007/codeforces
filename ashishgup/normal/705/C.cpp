#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, q, cur=0;
vector<int> g[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin>>n>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int x;
			cin>>x;
			cur++;
			g[x].push_back(cur);
			s.insert(cur);
		}
		else if(type==2)
		{
			int x;
			cin>>x;
			for(auto &it:g[x])
			{
				if(s.find(it)!=s.end())
					s.erase(it);
			}
			g[x].clear();
		}
		else
		{
			int t;
			cin>>t;
			while(s.size() && *s.begin()<=t)
				s.erase(s.begin());
		}
		cout<<s.size()<<endl;
	}
	return 0;
}