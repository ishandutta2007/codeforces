#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3e5+5;

int n, m;
int ans[N];
set<int> active;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		active.insert(i);
	for(int i=1;i<=m;i++)
	{
		int l, r, x;
		cin>>l>>r>>x;
		auto it=active.lower_bound(l);
		vector<int> del;
		while(it!=active.end() && *it<=r)
		{
			if(*it==x)
			{
				it++;
				continue;
			}
			del.push_back(*it);
			ans[*it]=x;
			it++;
		}
		for(auto it:del)
			active.erase(it);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}