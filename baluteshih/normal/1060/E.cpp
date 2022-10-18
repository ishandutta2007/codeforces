#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	ll l,r,lc,rc;
	mode():l(0),r(0),lc(0),rc(1){}
};

vector<ll> child[200001];
ll ans;
mode dp[200001]={mode()};

void dfs(ll x,ll f)
{
	auto &re=dp[x];
	for(ll i:child[x])
		if(i!=f)
		{
			dfs(i,x);
			auto tmp=dp[i];
			re.lc+=tmp.rc,re.rc+=tmp.lc;
			re.l+=tmp.rc+tmp.r,re.r+=tmp.lc+tmp.l;
		}
	ans+=(re.l+re.lc)/2+re.r/2;
}

void dfs2(ll x,ll f,mode tmp)
{
	tmp.lc-=dp[x].rc,tmp.rc-=dp[x].lc;
	tmp.l-=dp[x].rc+dp[x].r,tmp.r-=dp[x].lc+dp[x].l;
	swap(tmp.l,tmp.r),swap(tmp.lc,tmp.rc);
	tmp.l+=tmp.lc,tmp.r+=tmp.rc;
	ans+=(tmp.l+tmp.lc)/2+tmp.r/2;
	tmp.l+=dp[x].l,tmp.r+=dp[x].r;
	tmp.lc+=dp[x].lc,tmp.rc+=dp[x].rc;
	for(ll i:child[x])
		if(i!=f)
			dfs2(i,x,tmp);
}

int main()
{jizz
	ll n,a,b;
	cin >> n;
	for(int i=1;i<n;++i)
		cin >> a >> b,child[a].pb(b),child[b].pb(a);
	dfs(1,0);
	for(ll i:child[1])
		dfs2(i,1,dp[1]);
	cout << ans/2 << "\n";
}