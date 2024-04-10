#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int cur;
			cin>>cur;
			s.insert(cur);
		}
	}
	if(s.size()==m)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}