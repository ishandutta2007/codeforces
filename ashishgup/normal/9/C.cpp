#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
vector<int> v;

void dfs(int k)
{
	if(k>n)
		return;
	v.push_back(k);
	dfs(k*10);
	dfs(k*10 + 1);
}

int32_t main()
{
	IOS;
	cin>>n;
	dfs(1);	
	cout<<v.size();
	return 0;
}