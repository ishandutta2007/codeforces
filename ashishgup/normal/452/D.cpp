#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5;

int k;
int n[N], t[N], pref[N], ans=0;
multiset<int> s[N];

int32_t main()
{
	IOS;
	cin>>k;
	for(int i=1;i<=3;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
			s[i].insert(0);
	}
	for(int i=1;i<=3;i++)
	{
		cin>>t[i];
		pref[i]=pref[i-1] + t[i];
	}
	for(int i=1;i<=k;i++)
	{
		int cur=0;
		for(int j=1;j<=3;j++)
		{
			int temp=*s[j].begin();
			s[j].erase(s[j].begin());
			temp-=pref[j-1];
			cur=max(cur, temp);
		}
		ans=max(ans, cur+pref[3]);
		for(int j=1;j<=3;j++)
			s[j].insert(cur+pref[j]);
	}
	cout<<ans;
	return 0;
}