#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, m, r, c, x, y;
char a[N][N];
int distl[N][N], distr[N][N];
bool visl[N][N], visr[N][N];
int dx[4]={0, 0, +1, -1};
int dy[4]={1, -1, 0, 0};
int costl[4]={0, 1, 0, 0};
int costr[4]={1, 0, 0, 0};

int32_t main()
{
	IOS;
	cin>>n>>m>>r>>c>>x>>y;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			distl[i][j]=1e15;
			distr[i][j]=1e15;
			cin>>a[i][j];
		}
	}
	distl[r][c]=0;
	distr[r][c]=0;
	deque<pair<int, int> > d;
	d.push_back({r, c});
	while(!d.empty())
	{
		pair<int, int> p=d.front();
		d.pop_front();
		int x=p.first;
		int y=p.second;
		if(a[x][y]=='*')
			continue;
		if(visl[x][y])
			continue;
		visl[x][y]=1;
		for(int k=0;k<4;k++)
		{
			int nxtx=p.first + dx[k];
			int nxty=p.second + dy[k];
			if(nxtx>=1 && nxtx<=n && nxty>=1 && nxty<=m && distl[x][y] + costl[k] < distl[nxtx][nxty])
			{
				distl[nxtx][nxty]=distl[x][y] + costl[k];
				if(costl[k])
					d.push_back({nxtx, nxty});
				else
					d.push_front({nxtx, nxty});
			}
		}
	}
	d.push_back({r, c});
	while(!d.empty())
	{
		pair<int, int> p=d.front();
		d.pop_front();
		int x=p.first;
		int y=p.second;
		if(a[x][y]=='*')
			continue;
		if(visr[x][y])
			continue;
		visr[x][y]=1;
		for(int k=0;k<4;k++)
		{
			int nxtx=p.first + dx[k];
			int nxty=p.second + dy[k];
			if(nxtx>=1 && nxtx<=n && nxty>=1 && nxty<=m && distr[x][y] + costr[k] < distr[nxtx][nxty])
			{
				distr[nxtx][nxty]=distr[x][y] + costr[k];
				if(costr[k])
					d.push_back({nxtx, nxty});
				else
					d.push_front({nxtx, nxty});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*')
				continue;
			ans+=(distl[i][j]<=x && distr[i][j]<=y);
		}
	}
	cout<<ans;
	return 0;
}