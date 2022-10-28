#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
map<string, int> indegree;
map<string, string> m, ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a, b;
		cin>>a>>b;
		m[a]=b;
		indegree[b]++;
	}
	for(auto it:m)
	{
		string cur=it.first;
		if(indegree[cur])
			continue;
		string original=cur;
		while(m[cur].size())
			cur=m[cur];
		ans[original]=cur;
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}