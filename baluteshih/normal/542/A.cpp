#pragma GCC optimize("O3")
#include<utility>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif

struct mode
{
	ll l,r,c,i,mx,mxi;
	bool operator<(const mode &a)const{
		return l<a.l;
	}
}arr[200005];

vector<ll> L[200005],R[200005];
vector<ll> vl,vr;
pll seg[200005];
pll bit[200005];

bool cmp(mode a,mode b)
{
	return a.r>b.r;
}

void modify(ll x,pll v)
{
	for(;x<=vr.size();x+=x&-x) bit[x]=max(bit[x],v);
}

pll query(ll x)
{
	pll re=pll(0,0);
	for(;x;x-=x&-x) re=max(re,bit[x]);
	return re;
}

int main()
{
	IOS()
	ll n,m,bx;
	pll ans=pll(0,0);
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> seg[i].X >> seg[i].Y,vl.pb(seg[i].X),vr.pb(seg[i].Y);
	sort(ALL(vl)),vl.resize(unique(ALL(vl))-vl.begin());
	sort(ALL(vr)),vr.resize(unique(ALL(vr))-vr.begin());
	for(int i=1;i<=n;++i)
		L[lower_bound(ALL(vl),seg[i].X)-vl.begin()].pb(i),R[lower_bound(ALL(vr),seg[i].Y)-vr.begin()].pb(i);
	for(int i=1;i<=m;++i)
		cin >> arr[i].l >> arr[i].r >> arr[i].c,arr[i].i=i;
	sort(arr+1,arr+m+1),bx=-1;
	for(int i=1,nw=0;i<=m;++i)
	{
		for(;nw<vl.size()&&vl[nw]<=arr[i].l;++nw)
			for(ll j:L[nw])
				if(!~bx||seg[bx].Y<seg[j].Y)
					bx=j;
		if(~bx&&min(seg[bx].Y,arr[i].r)-arr[i].l>arr[i].mx)
			arr[i].mx=min(seg[bx].Y,arr[i].r)-arr[i].l,arr[i].mxi=bx;
	}
	
	for(int i=m,nw=vl.size()-1;i>0;--i)
	{
		for(;nw>=0&&vl[nw]>=arr[i].l;--nw)
			for(ll j:L[nw])
				modify(upper_bound(ALL(vr),seg[j].Y)-vr.begin(),pll(seg[j].Y-seg[j].X,j));
		pll t=query(upper_bound(ALL(vr),arr[i].r)-vr.begin());
		if(t.X>arr[i].mx)
			arr[i].mx=t.X,arr[i].mxi=t.Y;
	}
	
	sort(arr+1,arr+m+1,cmp),bx=-1;
	for(int i=1,nw=vr.size()-1;i<=m;++i)
	{
		for(;nw>=0&&vr[nw]>=arr[i].r;--nw)
			for(ll j:R[nw])
				if(!~bx||seg[bx].X>seg[j].X)
					bx=j;
		if(~bx&&arr[i].r-max(seg[bx].X,arr[i].l)>arr[i].mx)
			arr[i].mx=arr[i].r-max(seg[bx].X,arr[i].l),arr[i].mxi=bx;
	}
	
	for(int i=1;i<=m;++i)
		ans=max(ans,pll(arr[i].mx*arr[i].c,i));
	
	if(ans.X==0)
		cout << "0\n";
	else
		cout << ans.X << "\n" << arr[ans.Y].mxi << " " << arr[ans.Y].i << "\n";
}