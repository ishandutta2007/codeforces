#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], val[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
		auto it=s.upper_bound(a[i]);
		if(it==s.end())
		{
			val[a[i]]--;
			continue;
		}
		if(it==(--s.end()))
			val[*it]++;
	}
	int curmax=-2, ans=0;
	for(int i=1;i<=n;i++)
	{
		if(val[i]>curmax)
		{
			curmax=val[i];
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}