#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> child[300001];
ll w[300001],y;

bool dfs(ll x,ll f)
{
	int flag=0;
	w[x]=1;
	for(ll i:child[x])
		if(i!=f)
		{
			flag|=dfs(i,x);
			w[x]+=w[i];
		}
	return flag||(x==y);
}

int main()
{jizz
	ll n,a,b,x,cnt=1;
	cin >> n >> x >> y;
	for(int i=1;i<n;++i)
		cin >> a >> b,child[a].pb(b),child[b].pb(a);
	for(ll i:child[x])
		if(!dfs(i,x)) cnt+=w[i];
	cout << n*(n-1)-cnt*w[y] << "\n";
}