#pragma GCC optimize("O3","unroll-loops")
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

vector<ll> v;
pll dots[200005];
ll bit[200005],vis[200005],bitsz;

bool yee(pll a,pll b)
{
	if(a.S==b.S) return a.F<b.F;
	return a.S>b.S;
}

void modify(ll x,ll val)
{
	for(bitsz+=val;x<=v.size();x+=x&-x) bit[x]+=val;
}

ll query(ll x)
{
	ll re=0;
	for(;x;x-=x&-x) re+=bit[x];
	return re;
}

int main()
{jizz
    ll n,ans=0;
    cin >> n;
    for(int i=0;i<n;++i)
    	cin >> dots[i].F >> dots[i].S,v.pb(dots[i].F);
    sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
    sort(dots,dots+n,yee);
    for(ll i=0,j=0;i<n;)
    {
    	while(j<n&&dots[i].S==dots[j].S) 
		{
			ll p=upper_bound(ALL(v),dots[j].F)-v.begin();
			if(!vis[p])
    			vis[p]=1,modify(p,1);
			++j;
		}
    	for(ll ls=0;i<j;++i)
    	{
    		ll p=upper_bound(ALL(v),dots[i].F)-v.begin();
	    	ans+=(query(p)-query(ls))*(bitsz-query(p-1)),ls=p;
		}
	}
	cout << ans << "\n";
}