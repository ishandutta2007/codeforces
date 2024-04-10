#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b, n;

int32_t main()
{
	IOS;
	cin>>a>>b>>n;
	for(int x=-1000;x<=1000;x++)
	{
		int lhs=a;
		for(int i=1;i<=n;i++)
		{
			lhs*=x;
			if(abs(lhs)>abs(b))
			{
				break;
			}
		}
		if(lhs==b)
		{
			cout<<x;
			return 0;
		}
	}
	cout<<"No solution";
	return 0;
}