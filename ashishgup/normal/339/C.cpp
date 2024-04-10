#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;
const int offset=10;

int m;
string s;
int cache[N][25][15];

int dp(int i, int diff, int last)
{
	if(i==m+1)
		return 1;
	int &ans=cache[i][diff+offset][last];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int j=1;j<=10;j++)
	{
		if(s[j]=='1'&&j!=last&&j-diff>0)
			ans=max(ans, dp(i+1, j-diff, j));
	}
	return ans;
}

void path(int i, int diff, int last)
{
	cout<<last<<" ";
	if(i==m+1)
		return;
	for(int j=1;j<=10;j++)
	{
		if(s[j]=='1'&&j!=last&&j-diff>0)
			if(dp(i+1, j-diff, j))
				return path(i+1, j-diff, j);
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s>>m;
	s="*"+s;
	int ans=0;
	for(int i=1;i<=10;i++)
	{
		if(s[i]=='1')
		{
			ans=max(ans, dp(2, i, i));
		}
	}
	if(!ans)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=10;i++)
	{
		if(s[i]=='1')
		{
			if(dp(2, i, i))
			{
				path(2, i, i);
				return 0;
			}
		}
	}
	return 0;
}