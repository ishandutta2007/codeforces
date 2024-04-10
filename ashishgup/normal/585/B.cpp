#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n, k;
int cache[5][N];
char a[5][N];

int dfs(int row, int col)
{
	if(col==n)
		return 1;
	if(a[row][col + 2 * (col - 1)]>='A'&&a[row][col + 2 * (col - 1)]<='Z')
		return 0;
	int &ans=cache[row][col];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int j=row-1;j<=row+1;j++)
	{
		if(j<1||j>3)
			continue;
		if(a[row][col + 1 +  2 * (col - 1)]>='A'&&a[row][col + 1 + 2 * (col - 1)]<='Z')
			continue;
		if(a[j][col + 1 +  2 * (col - 1)]>='A'&&a[j][col + 1 + 2 * (col - 1)]<='Z')
			continue;
		ans|=dfs(j, col+1);
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		memset(cache, -1, sizeof(cache));
		int start=0;
		cin>>n>>k;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='s')
					start=i;
			}
		}
		int ans=dfs(start, 1);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}