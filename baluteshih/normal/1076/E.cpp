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
vector<pll> modi[300001];
ll ans[300001],bit[600001],mx,sum;

ll query(ll x)
{
	ll re=0;
	for(;x>0;x-=x&-x) re+=bit[x];
	return re;
}

void modify(ll x,ll v)
{
	for(sum+=v;x<=mx;x+=x&-x) bit[x]+=v;
}

void dfs(ll x,ll f,ll d)
{
	ans[x]+=sum-query(d-1);
	for(auto i:modi[x])
		modify(d+i.F,i.S);
	for(ll i:child[x])
		if(i!=f)
			dfs(i,x,d+1);
	for(auto i:modi[x])
		modify(d+i.F,-i.S);
}

int main()
{jizz
	ll n,a,b,x,q;
	cin >> n,mx=2*n;
	for(int i=1;i<n;++i)
		cin >> a >> b,child[a].pb(b),child[b].pb(a);
	cin >> q;
	while(q--)
		if(cin >> a >> b >> x,ans[a]+=x,b>0)
			modi[a].pb(MP(min(b,n),x));
	dfs(1,0,0);
	for(int i=1;i<=n;++i)
		cout << ans[i] << " ";
	ET;
}