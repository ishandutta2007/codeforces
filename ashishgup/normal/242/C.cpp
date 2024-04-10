#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
pair<int, int> src, dest;
set<pair<int, int> > s, vis;
map<pair<int, int>, int> lvl;
int dx[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};

int32_t main()
{
	IOS;
	cin>>src.first>>src.second;
	cin>>dest.first>>dest.second;	
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		int r, a, b;
		cin>>r>>a>>b;
		for(int j=a;j<=b;j++)
		{
			s.insert({r, j});
		}
	}
	queue<pair<int, int> > q;
	q.push(src);
	lvl[dest]=-1;
	while(q.size())
	{
		pair<int, int> p = q.front();
		q.pop();
		for(int k=0;k<8;k++)
		{
			pair<int, int> nxt={p.first+dx[k], p.second+dy[k]};
			if(s.find(nxt)!=s.end() && vis.find(nxt)==vis.end())
			{
				vis.insert(nxt);
				lvl[nxt]=lvl[p]+1;
				q.push(nxt);
			}
		}
	}
	cout<<lvl[dest];
}