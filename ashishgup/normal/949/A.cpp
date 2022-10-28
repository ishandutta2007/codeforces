#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
set<int> z[2];
vector<int> g[N];

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		z[s[i]-'0'].insert(i);
	int idx=0;
	while(!z[0].empty())
	{
		++idx;
		int cur=*(z[0].begin());
		g[idx].push_back(cur);
		while(z[1].lower_bound(cur)!=z[1].end())
		{
			int temp=*(z[1].lower_bound(cur));
			if(z[0].lower_bound(temp)!=z[0].end())
			{
				int nxt=*(z[0].lower_bound(temp));
				g[idx].push_back(temp);
				g[idx].push_back(nxt);
				cur=nxt;
			}
			else
				break;
		}
		for(auto &it:g[idx])
			z[0].erase(it), z[1].erase(it);
	}
	if(!z[1].empty())
	{
		cout<<"-1";
		return 0;
	}
	cout<<idx<<endl;
	for(int i=1;i<=idx;i++)
	{
		cout<<g[i].size()<<" ";
		for(auto &it:g[i])
			cout<<it+1<<" ";
		cout<<endl;
	}
	return 0;
}