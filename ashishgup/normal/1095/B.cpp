#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=1e9;
int a[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		s.insert(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		s.erase(s.find(a[i]));
		ans=min(ans, *s.rbegin() - *s.begin());
		s.insert(a[i]);
	}
	cout<<ans;
	return 0;
}