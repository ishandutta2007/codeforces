#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, a, b, c, ans=0;
	cin>>n>>a>>b>>c;
	for(int i=0;i<=a;i+=2)
	{
		for(int j=0;j<=c;j++)
		{
			int k=n-i/2-2*j;
			ans+=(k>=0 && k<=b);
		}
	}
	cout<<ans;
	return 0;
}