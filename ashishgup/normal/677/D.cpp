#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first 
#define y second

const int N=305;
const int lim=305;

int n, m, p;
int a[N][N], dist[N][N], vis[N][N], tdist[N][N];;
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};
vector<pair<int, int> > v[N*N];
vector<pair<int, int> > temp;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return tdist[p1.x][p1.y] > tdist[p2.x][p2.y];
}

int getx()
{
	return temp.back().first;
}

int gety()
{
	return temp.back().second;
}

void work()
{
	int idx=p;
	dist[v[p][0].x][v[p][0].y]=0;
	while(idx>0)
	{
		int cur=v[idx].size();
		if(cur<lim)
		{
			for(auto &i:v[idx])
				for(auto &j:v[idx-1])
					dist[j.x][j.y]=min(dist[j.x][j.y], dist[i.x][i.y] + abs(i.x-j.x) + abs(i.y-j.y));
		}
		else
		{
			memset(vis, 0, sizeof(vis));
			memset(tdist, 0, sizeof(tdist));
			int tempmin=1e9;
			for(auto &it:v[idx])
			{
				tempmin=min(tempmin, dist[it.x][it.y]);
				tdist[it.x][it.y]=dist[it.x][it.y];
			}
			queue<pair<int, int> > q;
			temp.clear();
			for(auto &it:v[idx])
			{
				if(tdist[it.x][it.y]==tempmin)
					q.push({it.x, it.y});
				else
					temp.push_back({it.x, it.y});
			}
			sort(temp.begin(), temp.end(), comp);
			while(q.size())
			{
				pair<int, int> p=q.front();
				q.pop();
				int xx=p.first;
				int yy=p.second;
				for(int dir=0;dir<4;dir++)
				{
					int nx=p.first+dx[dir];
					int ny=p.second+dy[dir];
					if(nx<1 || nx>n || ny<1 || ny>m)
						continue;
					if(vis[nx][ny])
						continue;
					vis[nx][ny]=1;
					tdist[nx][ny]=tdist[xx][yy]+1;
					q.push({nx, ny});
					while(temp.size() && (vis[getx()][gety()] || tdist[getx()][gety()] == tdist[nx][ny]) )
					{
						if(!vis[getx()][gety()])
							q.push({getx(), gety()});
						temp.pop_back();
					}
				}
			}
			for(auto &it:v[idx-1])
				dist[it.x][it.y]=tdist[it.x][it.y];
		}
		idx--;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j], v[a[i][j]].push_back({i, j}), dist[i][j]=1e9;
	work();
	int ans=1e9;
	for(auto &it:v[1])
		ans=min(ans, dist[it.first][it.second] + it.first - 1 + it.second - 1);
	cout<<ans;
	return 0;
}