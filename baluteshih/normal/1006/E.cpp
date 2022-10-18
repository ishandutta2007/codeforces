#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll; 

vector<int> child[200001];
int ans[200001],in[200001],out[200001],t;

void dfs(int x)
{
	in[x]=++t,ans[t]=x;
	for(int i:child[x])
		dfs(i);
	out[x]=t; 
}

int main()
{jizz
	int n,q,a,b;
	cin >> n >> q;
	for(int i=2;i<=n;++i)
		cin >> a,child[a].pb(i);
	dfs(1);
	while(q--)
	{
		cin >> a >> b;
		if(in[a]+b-1>out[a]) cout << "-1\n";
		else cout << ans[in[a]+b-1] << "\n";
	}
}