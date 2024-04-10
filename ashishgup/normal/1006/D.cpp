#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, ans=0;
string a, b;

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=0;i<n/2;i++)
	{
		map<char, int> m;
		if(b[i]==b[n-1-i])
		{
			if(a[i]!=a[n-1-i])
				ans++;
		}
		else
		{
			map<char, int> m;
			m[b[i]]++;
			m[b[n-1-i]]++;
			m[a[i]]--;
			m[a[n-1-i]]--;
			for(auto it:m)
				ans+=(it.second>0)?it.second:0;
		}
	}
	if(n%2)
		if(a[n/2]!=b[n/2])
			ans++;
	cout<<ans;
	return 0;
}