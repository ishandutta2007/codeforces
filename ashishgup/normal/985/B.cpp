#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, m;
char a[N][N];
int b[N];


int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
				b[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int check=1;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='1')
				if(b[j]-1==0)
					check=0;
		}
		if(check)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}