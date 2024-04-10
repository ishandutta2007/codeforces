#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n=5, ans=0, sum=0;
map<int, int> m;

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		m[x]++;
		sum+=x;
	}
	ans=sum;
	for(auto &it:m)
	{
		int take=0;
		if(it.second>=2)
			take=min(3LL, it.second);
		ans=min(ans, sum-take*it.first);
	}
	cout<<ans;
	return 0;
}