#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int a[N], pref[N], suf[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
		s.insert(suf[i]);
	}
	for(int i=1;i<=n;i++)
	{
		s.erase(s.find(suf[i]));
		if(s.find(pref[i])!=s.end())
			ans=max(ans, pref[i]);
	}	
	cout<<ans;
	return 0;
}