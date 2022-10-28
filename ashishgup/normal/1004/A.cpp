#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, d, ans=0;
int a[N];
set<int> s;

int work()
{
	set<int> have;
	for(auto it:s)
	{
		int dist=2e9;
		for(int i=1;i<=n;i++)
		{
			if(abs(a[i]-it)<dist)
				dist=abs(a[i]-it);
		}
		if(dist==d)
			have.insert(it);
	}
	return have.size();
}

int32_t main()
{
	IOS;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]-d);
		s.insert(a[i]+d);
	}
	int ans=work();
	cout<<ans;
	return 0;
}