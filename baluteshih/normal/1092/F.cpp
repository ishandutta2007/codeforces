#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> G[200005];
ll arr[200005],ans[200005],w[200005],wans[200005];

void dfs(ll u,ll f)
{
	w[u]=arr[u];
	for(ll i:G[u])
		if(i!=f)
			dfs(i,u),w[u]+=w[i],wans[u]+=wans[i]+w[i];
}

void dfs2(ll u,ll f,ll sum,ll wei)
{
	ans[u]=wans[u]+sum;
	for(ll i:G[u])
		if(i!=f)
			dfs2(i,u,sum+wans[u]-wans[i]-w[i]+wei+w[u]-w[i],wei+w[u]-w[i]);
}

int main()
{jizz
	ll n,a,b;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<n;++i)
		cin >> a >> b,G[a].pb(b),G[b].pb(a);
	dfs(1,1),dfs2(1,1,0,0);
	cout << *max_element(ans+1,ans+n+1) << "\n";
}