#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, ans=0;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=min(n, m);i++)
	{
		for(int j=1;j<=min(n, m);j++)
		{
			if((i*i + j*j)%m)
				continue;
			int timesi=1 + (n-i)/m;
			int timesj=1 + (n-j)/m;
			ans+=timesi*timesj;
		}
	}
	cout<<ans;
	return 0;
}