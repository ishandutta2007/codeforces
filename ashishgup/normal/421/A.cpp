#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, a, b;
	cin>>n>>a>>b;
	set<int> s;
	for(int i=1;i<=a;i++)
	{
		int k;
		cin>>k;
		s.insert(k);
	}
	for(int i=1;i<=n;i++)
	{
		if(s.find(i)!=s.end())
			cout<<1<<" ";
		else
			cout<<2<<" ";
	}
	return 0;
}