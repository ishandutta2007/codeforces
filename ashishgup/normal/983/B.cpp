#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int a[N], f[N][N];
int vis[N][N], ans[N][N];

inline int dp(int i, int j)
{
	if(vis[i][j])
		return ans[i][j];
	if(i==j)
		return ans[i][j];
	vis[i][j]=1;
	ans[i][j]=max(ans[i][j], max(dp(i+1, j), dp(i, j-1)));
	return ans[i][j];
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		f[0][i]=a[i];
		ans[i][i]=a[i];
	}
	int len=1;
	int cursz=n;
	for(int i=1;i<=n-1;i++)
	{
		cursz--;
		for(int j=1;j<=cursz;j++)
		{
			int curnum=0;
			f[i][j]=f[i-1][j]^f[i-1][j+1];
			ans[j][j+len]=f[i][j];
		}
		len++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		cout<<dp(l, r)<<endl;
	}
	return 0;
}