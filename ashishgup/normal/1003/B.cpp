#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int a, b, x;
string ans="";

int32_t main()
{
	IOS;
	cin>>a>>b>>x;
	ans="01";
	x--;
	a--;
	b--;
	for(int i=2;i<=x;i+=2)
	{
		a--;
		b--;
		ans+="01";
	}
	if(x%2)
	{
		if(a>0)
		{
			a--;
			ans+='0';
		}
		else
		{
			b--;
			ans='1'+ans;
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(ans[i]=='0')
		{
			while(a>0)
			{
				cout<<'0';
				a--;
			}
		}
		else
		{
			while(b>0)
			{
				cout<<'1';
				b--;
			}
		}
	}
	return 0;
}