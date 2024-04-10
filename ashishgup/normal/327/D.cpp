#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m;
pair<int, int> root;
char a[N][N];
int dx[4]={0, 0, +1, -1};
int dy[4]={-1, +1, 0, 0};
vector<char> v1;
vector<pair<int, int> > v2;

void dfs(int i, int j)
{
	if(i<1 || i>n)
		return;
	if(j<1 || j>m)
		return;
	if(a[i][j]=='#')
		return;
	a[i][j]='#';
	v1.push_back('B');
	v2.push_back({i, j});
	for(int dir=0;dir<4;dir++)
	{
		int nx=i+dx[dir];
		int ny=j+dy[dir];
		dfs(nx, ny);
	}
	pair<int, int> p={i, j};
	if(p!=root)
	{
		v1.push_back('D');
		v2.push_back({i, j});
		v1.push_back('R');
		v2.push_back({i, j});	
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!='.')
				continue;
			root={i, j};
			dfs(i, j);
		}
	}
	cout<<v1.size()<<endl;
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" "<<v2[i].first<<" "<<v2[i].second<<endl;
	return 0;
}