#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pll seg[200005];
ll nxt[20][200005],mx[200005];

bool yee(pll a,pll b)
{
	return a.F<b.F;
}

int main()
{jizz
	ll n,m,l,r,L,ans;
	cin >> n >> m,L=__lg(n);
	for(int i=0;i<n;++i)
		cin >> seg[i].F >> seg[i].S;
	sort(seg,seg+n),nxt[0][n]=n;
	for(ll i=1;i<n;++i)
	{
		if(seg[i].S>seg[mx[i-1]].S) mx[i]=i;
		else mx[i]=mx[i-1];
	}
	for(ll i=0;i<n;++i)
	{
		ll x=upper_bound(seg,seg+n,MP(seg[i].S,seg[i].S),yee)-seg-1;
		if(seg[mx[x]].S<=seg[i].S) nxt[0][i]=n; 
		else nxt[0][i]=mx[x];
	}
	for(int i=1;i<=L;++i)
		for(int j=0;j<=n;++j)
			nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	while(m--)
	{
		cin >> l >> r,ans=0;
		if(l<seg[0].F||l>seg[mx[n-1]].S)
		{
			cout << "-1\n";
			continue;
		}
		ll x=upper_bound(seg,seg+n,MP(l,r),yee)-seg-1;
		x=mx[x];
		if(seg[x].S>=r)
		{
			cout << "1\n";
			continue;
		}
		for(int i=L;i>=0;--i)
			if(nxt[i][x]!=n&&seg[nxt[i][x]].S<r)
				ans+=1<<i,x=nxt[i][x];
		x=nxt[0][x],ans+=2;
		if(x==n||seg[x].S<r) cout << "-1\n";
		else cout << ans << "\n";
	}
}