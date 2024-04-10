#include <bits/stdc++.h>
using namespace std;
int n,m,vis[1000005],ans[1000005];
queue <int> q;
vector <int> e[1000005];
inline int id(int x,int y)
{
	return (x-1)*m+y;
}
string s[1000005];
inline bool check(int x)
{
	int qwq=0,qaq=0;
	for(auto t:e[x])
		qwq+=!ans[t],qaq+=!!ans[t];
	return qwq<=1&&qaq>=1;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i=1;i<=n*m;i++) e[i].clear(),ans[i]=0,vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			cin >> s[i];
			s[i]=' '+s[i];
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='#') vis[id(i,j)]=1;
				if(s[i][j]=='L') ans[id(i,j)]=2,q.push(id(i,j));
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(!vis[id(i,j)]&&!vis[id(i,j+1)])
					e[id(i,j)].push_back(id(i,j+1)),e[id(i,j+1)].push_back(id(i,j));
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!vis[id(i,j)]&&!vis[id(i+1,j)])
					e[id(i,j)].push_back(id(i+1,j)),e[id(i+1,j)].push_back(id(i,j));
			}
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(auto v:e[x])
			{
				if(!ans[v]&&check(v))
					ans[v]=1,q.push(v);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ans[id(i,j)]==2) cout << "L";
				else if(ans[id(i,j)]) cout << "+";
				else if(vis[id(i,j)]) cout << "#";
				else cout << ".";
			}
			cout << "\n";
		}
	}
	return 0;
}