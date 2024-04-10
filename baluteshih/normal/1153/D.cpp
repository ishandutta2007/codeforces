#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int mxmi[300005];
const int INF=1e9;
vector<int> G[300005];

pii dfs(int u)
{
	if(G[u].empty()) return MP(1,1);
	pii re=MP(0,0);
	int mi=INF;
	for(int i:G[u])
	{
		auto tmp=dfs(i);
		re.S+=tmp.S;
		if(!mxmi[u]) re.F+=tmp.F-1;
		else re.F+=tmp.S,mi=min(mi,tmp.S-tmp.F);
	}
	if(!mxmi[u]) return MP(re.F+1,re.S);
	return MP(re.F-mi,re.S);
}

int main()
{jizz
	int n,x;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> mxmi[i];
	for(int i=2;i<=n;++i)
		cin >> x,G[x].pb(i);
	cout << dfs(1).F << "\n";
}