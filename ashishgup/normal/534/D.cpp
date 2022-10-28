#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, cur=0;
int a[N];
vector<int> g[N];
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}	
	while(ans.size()<n && cur>=0)
	{
		while(cur>=0 && !g[cur].size())
			cur-=3;
		if(cur<0)
			break;
		ans.push_back(g[cur].back());
		g[cur].pop_back();
		cur++;
	}
	if(ans.size()<n)
		cout<<"Impossible";
	else
	{
		cout<<"Possible"<<endl;
		for(auto &it:ans)
			cout<<it<<" ";
	}
	return 0;
}