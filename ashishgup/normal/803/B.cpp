#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])
			s.insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		auto it=s.lower_bound(i);
		int ans=n;
		if(it!=s.end())
			ans=min(ans, *it - i);
		if(it!=s.begin())
		{
			it--;
			ans=min(ans, i - *it);
		}
		cout<<ans<<" ";
	}
	return 0;
}