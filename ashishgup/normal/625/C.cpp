#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, k, ans=0;
int cur=1;
int a[N][N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k-1;j++)
			a[i][j]=cur++;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j<=n;j++)
		{
			if(j==k)
				ans+=cur;
			a[i][j]=cur++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}