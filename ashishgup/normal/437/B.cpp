#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int sum, lim;

int lowbit(int x)
{
	for(int i=0;;i++)
	{
		if(x&(1<<i))
			return 1<<i;
	}
}

int32_t main()
{
	IOS;
	cin>>sum>>lim;
	vector<pair<int, int> > v;
	for(int i=1;i<=lim;i++)
	{
		v.push_back({lowbit(i), i});
	}
	sort(v.rbegin(), v.rend());
	vector<int> ans;
	for(auto it:v)
	{
		if(sum>=it.first)
		{
			sum-=it.first;
			ans.push_back(it.second);
		}
	}
	if(sum>0)
	{
		cout<<"-1";
		return 0;
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}