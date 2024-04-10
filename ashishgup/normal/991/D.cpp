#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

const int N=105;

int n, ans=0;
int cache[N];
char a[5][N];

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=2;i++)
	{
		string s;
		cin>>s;
		n=s.size();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=s[j-1];
		}
	}
	for(int j=1;j<=n-1;j++)
	{
		if(a[1][j]=='0' && a[2][j]=='0')
		{
			if(a[1][j+1]=='0')
			{
				ans++;
				a[1][j]=a[2][j]=a[1][j+1]='1';
			}
			else if(a[2][j+1]=='0')
			{
				ans++;
				a[1][j]=a[2][j]=a[2][j+1]='1';
			}
		}
		else if(a[1][j]=='0'||a[2][j]=='0')
		{
			if(a[1][j+1]=='0' && a[2][j+1]=='0')
			{
				ans++;
				a[1][j+1]='1';
				a[2][j+1]='1';
			}
		}
	}
	cout<<ans;
}