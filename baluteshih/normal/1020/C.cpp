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

vector<ll> vote[3001];
priority_queue<ll,vector<ll>,greater<ll>> pq;

bool yee(ll a,ll b)
{
	return a>b;
}

int main()
{jizz
	ll n,m,p,c,tmp,cnt,ans=1e18;
	cin >> n >> m;
	for(ll i=0;i<n;++i)
		cin >> p >> c,vote[p].pb(c);
	for(ll i=1;i<=m;++i)
		sort(ALL(vote[i]),yee);
	for(ll i=vote[1].size();i<=n;++i)
	{
		cnt=vote[1].size(),tmp=0;
		while(!pq.empty()) pq.pop();
		for(ll j=2,k;j<=m;++j)
		{
			for(k=0;k<vote[j].size() && k<i-1;++k)
				pq.push(vote[j][k]);
			for(;k<vote[j].size();++k)
				tmp+=vote[j][k],++cnt;
		}
		while(cnt<i)
			tmp+=pq.top(),pq.pop(),++cnt;
		ans=min(ans,tmp);
	}
	cout << ans << "\n";
}