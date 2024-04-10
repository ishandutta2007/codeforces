#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m, q;
char a[N][N];
int hori[N][N], vert[N][N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			hori[i][j]=hori[i-1][j] + hori[i][j-1] - hori[i-1][j-1];
			vert[i][j]=vert[i-1][j] + vert[i][j-1] - vert[i-1][j-1];
			if(a[i][j]=='.'&&a[i][j-1]=='.')
				hori[i][j]++;
			if(a[i][j]=='.'&&a[i-1][j]=='.')
				vert[i][j]++;
		}
	}
	cin>>q;
	while(q--)
	{
		int r1, c1, r2, c2;
		cin>>r1>>c1>>r2>>c2;
		int ans1=hori[r2][c2] - hori[r1-1][c2] - hori[r2][c1] + hori[r1-1][c1];
		int ans2=vert[r2][c2] - vert[r1][c2] - vert[r2][c1-1] + vert[r1][c1-1];
		cout<<(ans1+ans2)<<endl;
	}
	return 0;
}