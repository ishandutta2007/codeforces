#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, x=0, y=0, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x+=(a[i]==1);
		y+=(a[i]==-1);
	}
	for(int i=1;i<=k;i++)
	{
		int curx=x, cury=y;
		for(int j=i;j<=n;j+=k)
		{
			curx-=(a[j]==1);
			cury-=(a[j]==-1);
		}
		ans=max(ans, abs(curx-cury));
	}
	cout<<ans;
	return 0;
}