#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

set<int> ans;

void dfs(int num, int left, int ct)
{
	if(ct>=15)
		return;
	if(left==0)
		ans.insert(num);
	for(int i=0;i<=min(left,9LL);i++)
		dfs(num*10+i, left-i, ct+1);
}

int32_t main()
{
	IOS;
	dfs(0, 10, 0);
	int k;
	cin>>k;
	int ct=0;
	for(auto it:ans)
	{
		ct++;
		if(ct==k)
		{
			cout<<it;
			return 0;
		}
	}
	return 0;
}