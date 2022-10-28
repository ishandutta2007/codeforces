#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=120;

int n, m, x1, y1, x2, y2;
char a[N][N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='B')
			{
				if(x1==0)
					x1=i, y1=j;
				x2=i;
				y2=j;
			}
		}
	}
	int ansx=x1 + (x2-x1)/2;
	int ansy=y1 + (y2-y1)/2;
	cout<<ansx<<" "<<ansy;
	return 0;
}