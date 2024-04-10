#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, m, d;

int32_t main()
{
	IOS;
	cin>>n>>k>>m>>d;
	int ans=0;
	for(int i=1;i<=d;i++)
	{
		int den1=(i-1)*k + 1;
		int max1=n/den1;
		int den2=(i)*k;
		int min1=n/den2;
		if(min1<=m)
		{
			int cur=min(m, max1);
			ans=max(ans, cur * i);
		}
		if(max1==0)
			break;
	}
	cout<<ans;
}