#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define MP make_pair
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

vector<int> child[200001],rchild[200001];
bitset<200001> vis;
int in[200001];
queue<int> q;

bool dfs(int x)
{
	int cnt=0;
	vis[x]=1;
	for(int i:child[x])
		if(!vis[i])
			if(dfs(i)) cnt++,rchild[x].pb(i),in[i]++;
			else rchild[i].pb(x),in[x]++;
		else cnt++;
	return cnt&1;
}

int main()
{jizz
	int n,i,x;
	cin >> n;
	for(i=1;i<=n;++i)
		if(cin >> x,x) child[x].pb(i),child[i].pb(x);
	if(dfs(1)) cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(i=1;i<=n;++i)
			if(!in[i]) q.push(i);
		while(!q.empty())
		{
			x=q.front(),q.pop();
			cout << x << "\n";
			for(int i:rchild[x])
			{
				in[i]--;
				if(!in[i]) q.push(i);
			}
		}
	}
}