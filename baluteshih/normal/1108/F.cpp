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

struct mode
{
	ll a,b,w;
	bool operator<(const mode&x)const{
		return w<x.w;
	}
}edge[200005];
ll bw[200005],boss[200005],ranks[200005];

ll finds(ll x)
{
	if(x==boss[x]) return x;
	return finds(boss[x]);
}

bool Union(ll a,ll b,ll w)
{
	a=finds(a),b=finds(b);
	if(a==b) return 0;
	if(ranks[a]<ranks[b]) boss[a]=b,bw[a]=w;
	else if(ranks[a]>ranks[b]) boss[b]=a,bw[b]=w;
	else boss[b]=a,bw[b]=w,++ranks[a];
	return 1;
}

ll fmx(ll a,ll b)
{
	ll mx=0;
	while(a!=b)
	{
		if(ranks[a]>ranks[b]) swap(a,b);
		mx=max(mx,bw[a]),a=boss[a];
	}
	return mx;
}

int main()
{jizz
	ll n,m,ans=0;
	cin >> n >> m;
	for(int i=0;i<m;++i)
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	sort(edge,edge+m);
	for(int i=1;i<=n;++i)
		boss[i]=i;
	for(int i=0;i<m;++i)
		if(!Union(edge[i].a,edge[i].b,edge[i].w))
			if(fmx(edge[i].a,edge[i].b)==edge[i].w)
				++ans;
	cout << ans << "\n";
}