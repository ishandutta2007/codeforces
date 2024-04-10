#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, cur=0;
int a[N], b[N];
int pref[N], pref2[N];
int ans[N][N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		pref[i]=pref[i-1]^b[i];
		ans[i][m]^=b[i];
		cur^=b[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		pref2[i]=pref2[i-1]^a[i];
		ans[n][i]=a[i];
		cur^=a[i];
	}
	ans[n][m]=b[n]^pref2[m-1];
	if(cur!=0)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}