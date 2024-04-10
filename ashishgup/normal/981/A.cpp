#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int check(int p, int q)
{
	for(int i=p, j=q;i<=j;i++, j--)
	{
		if(s[i]!=s[j])
			return 1;
	}
	return 0;
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(check(i, j))
			{
				ans=max(ans, j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}