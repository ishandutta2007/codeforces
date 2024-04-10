#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, m, p, remaining=0, nochanges=0;
int s[20], mx[20], ans[20], stmx[20];
int level[N][N];
char a[N][N];
queue<pair<int, int> > q[20];
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};

bool check(int x, int y)
{
	if(x<1 || x>n || y<1 || y>m)
		return 0;
	return (a[x][y]=='.');
}

void work(int idx)
{
	bool checker=1;
	while(q[idx].size() && remaining>0)
	{
		pair<int, int> p=q[idx].front();
		int x=p.first;
		int y=p.second;
		if(level[x][y]==mx[idx])
		{
			nochanges+=checker;
			return;
		}
		q[idx].pop();
		for(int dir=0;dir<4;dir++)
		{
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(check(nx, ny))
			{
				checker=0;
				nochanges=0;
				ans[idx]++;
				remaining--;
				a[nx][ny]=(char)('0'+idx);
				q[idx].push({nx, ny});
				level[nx][ny]=level[x][y]+1;
			}
		}
	}
	nochanges+=checker;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>s[i];
		mx[i]=s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			remaining+=(a[i][j]=='.');
			if(isdigit(a[i][j]))
			{
				q[a[i][j]-'0'].push({i, j});
				level[i][j]=0;
				ans[a[i][j]-'0']++;
			}
		}
	}
	int player=0;
	while(remaining>0 && nochanges<p)
	{
		work(player+1);
		mx[player+1]+=s[player+1];
		player++;
		player%=p;
	}
	for(int i=1;i<=p;i++)
		cout<<ans[i]<<" ";
	return 0;
}