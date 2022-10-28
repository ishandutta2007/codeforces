#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, ans=0;
char a[N][N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		int cur=0;
		for(int j=1;j<=n;j++)
			cur+=(a[i][j]=='C');
		ans+=cur*(cur-1)/2;
	}
	for(int j=1;j<=n;j++)
	{
		int cur=0;
		for(int i=1;i<=n;i++)
			cur+=(a[i][j]=='C');
		ans+=cur*(cur-1)/2;
	}
	cout<<ans;
	return 0;
}