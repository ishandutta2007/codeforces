#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, x, y;
string s;

int32_t main()
{
	IOS;
	cin>>n>>x>>y>>s;
	char ch='1';
	int len=0, cnt=0;
	for(int i=0;i<n;i++)
	{	
		if(s[i]==ch)
			len++;
		else
		{
			if(ch=='0')
				cnt++;
			ch=s[i];
			len=1;
		}
	}
	if(ch=='0')
		cnt++;
	int ans=cnt*y;
	for(int i=1;i<=cnt-1;i++)
	{
		ans=min(ans, x*i + (cnt-i)*y);
	}
	cout<<ans;
}