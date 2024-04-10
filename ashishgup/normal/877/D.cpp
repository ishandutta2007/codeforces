#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, m, k, x1, y1, x2, y2;
char a[N][N];
int level[N][N];
set<int> row[N], col[N];
vector<pair<int, int> > v;

void remove()
{
	for(auto it:v)
	{
		row[it.first].erase(it.second);
		col[it.second].erase(it.first);
	}
	v.clear();
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			row[i].insert(j);
			col[j].insert(i);
			cin>>a[i][j];
		}
	}
	cin>>x1>>y1>>x2>>y2;
	queue<pair<int, int> > q;
	memset(level, -1, sizeof(level));
	level[x1][y1]=0;
	q.push({x1, y1});
	row[x1].erase(y1);
	col[y1].erase(x1);
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		auto it=row[x].lower_bound(y);
		while(it!=row[x].end())
		{
			int nxty=*it;
			if(nxty-y>k)
				break;
			if(a[x][nxty]=='#')
				break;
			level[x][nxty]=level[x][y]+1;
			q.push({x, nxty});
			v.push_back({x, nxty});
			it++;
		}
		remove();
		it=row[x].lower_bound(y);
		if(it!=row[x].begin())
			it--;
		while(it!=row[x].end())
		{
			int nxty=*it;
			if(nxty>=y)
				break;
			if(y-nxty>k)
				break;
			if(a[x][nxty]=='#')
				break;
			level[x][nxty]=level[x][y]+1;
			q.push({x, nxty});
			v.push_back({x, nxty});
			if(it==row[x].begin())
				break;
			it--;
		}
		remove();
		auto it2=col[y].lower_bound(x);
		while(it2!=col[y].end())
		{
			int nxtx=*it2;
			if(nxtx-x>k)
				break;
			if(a[nxtx][y]=='#')
				break;
			level[nxtx][y]=level[x][y]+1;
			q.push({nxtx, y});
			v.push_back({nxtx, y});
			it2++;
		}
		remove();
		it2=col[y].lower_bound(x);
		if(it2!=col[y].begin())
			it2--;
		while(it2!=col[y].end())
		{
			int nxtx=*it2;
			if(nxtx>=x)
				break;
			if(x-nxtx>k)
				break;
			if(a[nxtx][y]=='#')
				break;
			level[nxtx][y]=level[x][y]+1;
			q.push({nxtx, y});
			v.push_back({nxtx, y});
			if(it2==col[y].begin())
				break;
			it2--;
		}
		remove();
	}
	cout<<level[x2][y2];
}