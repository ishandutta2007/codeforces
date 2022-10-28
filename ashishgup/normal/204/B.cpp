#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
map<int, int> up, down, same;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a, b;
		cin>>a>>b;
		up[a]++;
		down[b]++;
		if(a==b)
			same[a]++;	
	}
	int store=(n+1)/2;
	int ans=1e9;
	for(auto &it:up)
	{
		int cur=it.second;
		int reqd=max(0LL, store-it.second);
		if(reqd==0)
			return cout<<"0", 0;
		if(down.find(it.first)!=down.end())
		{
			int have=down[it.first]-same[it.first];
			if(have>=reqd)
				ans=min(ans, reqd);
		}
	}
	for(auto &it:down)
	{
		if(it.second>=store)
			ans=min(ans, store);
	}
	if(ans==1e9)
		ans=-1;
	cout<<ans;
	return 0;
}