#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

set<int> s;
int n, x=0, y=0;

void dfs(int num)
{
	if(num>n)
		return;
	s.insert(num);
	if(!(x==0 && num==0))
		dfs(num*10 + x);
	if(!(y==0 && num==0))
		dfs(num*10 + y);
}

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	for(x=0;x<=9;x++)
		for(y=x;y<=9;y++)
			dfs(0);
	cout<<s.size()-1;
	return 0;
}