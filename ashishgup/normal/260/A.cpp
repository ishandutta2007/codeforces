#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a, b, n;

int32_t main()
{
	IOS;
	cin>>a>>b>>n;
	int rem=a%b;
	string ans="";
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			int newrem=rem*10 + j;
			if(newrem%b==0)
			{
				ans+=(char)(j+'0');
				rem=newrem%b;
				break;
			}
		}
		if(ans.size()!=i)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<a<<ans;
 	return 0;
}