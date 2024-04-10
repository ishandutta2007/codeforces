#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N];
set<int> s;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
		s.insert(a[i]);
	}
	int ans=1;
	for(auto i:s)
	{
		for(auto j:s)
		{
			int cur=1;
			int idx=g[i][0];
			while(true)
			{
				auto it=upper_bound(g[j].begin(), g[j].end(), idx);
				if(it==g[j].end())
					break;
				cur++;
				idx=*it;
				auto it2=upper_bound(g[i].begin(), g[i].end(), idx);
				if(it2==g[i].end())
					break;
				idx=*it2;
				cur++;
			}
			ans=max(ans, cur);
		}
	}
	cout<<ans;
	return 0;
}