#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
string a, b;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>a>>b;
	n=a.size();
	m=b.size();
	for(int i=0;i<n;i++)
		g[a[i]].push_back(i);
	int curind=-1, ans=1;
	for(int i=0;i<m;i++)
	{
		char cur=b[i];
		if(!g[cur].size())
		{
			cout<<"-1";
			return 0;
		}
		auto it=upper_bound(g[cur].begin(), g[cur].end(), curind);
		if(it==g[cur].end())
		{
			curind=-1;
			it=upper_bound(g[cur].begin(), g[cur].end(), curind);
			ans++;
		}
		curind=*it;
	}
	cout<<ans;
	return 0;
}