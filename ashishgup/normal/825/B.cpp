#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=20;

int n=10;
int f[N], a[N][N];
int dx[4]={1, 0, 1, 1};
int dy[4]={0, 1, 1, -1};

void check(int x, int y, int k)
{
	memset(f, 0, sizeof(f));
	for(int i=0;i<5;i++)
	{
		if(a[x][y]<0)
			return;
		f[a[x][y]]++;
		x+=dx[k];
		y+=dy[k];
	}
	if(f[0]==4 && f[2]==1)
	{
		cout<<"YES";
		exit(0);
	}
}

int32_t main()
{
	IOS;
	memset(a, -1, sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='X')
				a[i][j]=0;
			else if(ch=='O')
				a[i][j]=1;
			else
				a[i][j]=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			check(i, j, 0);
			check(i, j, 1);
			check(i, j, 2);
			check(i, j, 3);
		}
	}
	cout<<"NO";
	return 0;
}