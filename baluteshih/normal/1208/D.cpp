#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ll;
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
#define int long long

int seg[800005],lazy[800005],arr[200005],ans[200005];
const int INF=1e18;

void down(int rt)
{
	if(!lazy[rt]) return;
	seg[rt<<1]+=lazy[rt],seg[rt<<1|1]+=lazy[rt];
	lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}

void build(int l,int r,int rt)
{
	if(l==r)
		return seg[rt]=arr[l],void();
	int m=l+r>>1;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}

void modify(int L,int R,int l,int r,int rt,int v)
{
	if(l!=r) down(rt);
	if(L<=l&&R>=r)
		return seg[rt]+=v,lazy[rt]+=v,void();
	int m=l+r>>1;
	if(L<=m) modify(L,R,l,m,rt<<1,v);
	if(R>m) modify(L,R,m+1,r,rt<<1|1,v);
	seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}

int query(int l,int r,int rt)
{
	if(l!=r) down(rt);
	if(l==r) return l;
	int m=l+r>>1;
	if(seg[rt<<1|1]==0) return query(m+1,r,rt<<1|1);
	return query(l,m,rt<<1);
}

int32_t main()
{
	IOS()
	int n;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	build(1,n,1);
	for(int i=1;i<=n;++i)
	{
		int t=query(1,n,1);
		modify(t,t,1,n,1,INF),ans[t]=i;
		if(t<n) modify(t+1,n,1,n,1,-i);
	}
	for(int i=1;i<=n;++i)
		cout << ans[i] << " \n"[i==n];
}