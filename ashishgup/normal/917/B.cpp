#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=105;

int n;
char win;
vector<pair<int, char> > g[N];
int cache[105][105][2][30];

int canWin(int u, int v, int turn, char prev)
{
	if(turn==0)
		if(!g[u].size())
			return 0;
	if(turn==1)
		if(!g[v].size())
			return 0;
	int &ans=cache[u][v][turn][prev-'a'+1];
	if(ans!=-1)
		return ans;
	if(turn==0)
	{
		ans=0;
		for(auto it:g[u])
		{
			if(it.second<prev)
				continue;
			if(!canWin(it.first, v, 1, it.second))
				ans=1;
		}
	}
	else
	{
		ans=0;
		for(auto it:g[v])
		{
			if(it.second<prev)
				continue;
			if(!canWin(u, it.first, 0, it.second))
				ans=1;
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		char ch;
		cin>>u>>v>>ch;
		g[u].push_back(make_pair(v, ch));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(canWin(i, j, 0, 'a'-1))
				cout<<"A";
			else
				cout<<"B";
		}
		cout<<endl;
	}
	return 0;
}