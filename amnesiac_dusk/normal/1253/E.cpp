#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int mod=998244353;
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
const int inf=infi;
const int N=100005;
int a[N];
struct node {
	int cnt,val[2];
	ll sum;
	node() {
		cnt=sum=0;
	}
} tr[4*N];
int lazy[4*N];
void update(int nd) {
	int nd1=nd<<1,nd2=nd1|1;
	tr[nd].sum=tr[nd1].sum+tr[nd2].sum;
	tr[nd].cnt=0,tr[nd].val[0]=tr[nd].val[1]=-inf;
	for(int j=0; j<2; j++) {
		for(int i=0; i<2; i++) {
			if(tr[nd1+i].val[j]>tr[nd].val[0]) {
				tr[nd].val[1]=tr[nd].val[0];
				tr[nd].val[0]=tr[nd1+i].val[j];
				tr[nd].cnt=tr[nd1+i].cnt;
			} else if(tr[nd1+i].val[j]==tr[nd].val[0]) {
				tr[nd].cnt+=tr[nd1+i].cnt;
			} else if(tr[nd1+i].val[j]>tr[nd].val[1])
				tr[nd].val[1]=tr[nd1+i].val[j];
		}
	}
}
void tag(int nd, int x) {
	lazy[nd]=min(lazy[nd],x);
}
void pushdown(int nd, int s, int e) {
	if(lazy[nd]>=tr[nd].val[0])
		return;
	int nd1=nd<<1,nd2=nd1|1;
	tr[nd].sum-=ll(tr[nd].val[0]-lazy[nd])*tr[nd].cnt;
	tr[nd].val[0]=lazy[nd];
	if(s!=e) {
		lazy[nd1]=min(lazy[nd1],lazy[nd]);
		lazy[nd2]=min(lazy[nd2],lazy[nd]);
	}
	lazy[nd]=inf;
}
void build(int nd, int s, int e) {
	lazy[nd]=inf;
	if(s==e) {
		tr[nd].val[0]=a[s],tr[nd].val[1]=-inf;
		tr[nd].cnt=1;
		tr[nd].sum=a[s];
		return;
	}
	int m=(s+e)>>1,nd1=nd<<1,nd2=nd1|1;
	build(nd1,s,m);
	build(nd2,m+1,e);
	update(nd);
}
void update(int nd, int s, int e, int l, int r, int x) {
	pushdown(nd,s,e);
	if(s>r||e<l||tr[nd].val[0]<=x) // breakdown condition
		return;
	else if(l<=s&&e<=r&&tr[nd].val[1]<x) // tag condition
			{
		tag(nd,x);
		pushdown(nd,s,e);
		return;
	}
	int m=(s+e)>>1,nd1=nd<<1,nd2=nd1|1;
	update(nd1,s,m,l,r,x);
	update(nd2,m+1,e,l,r,x);
	update(nd);
}
ll sum(int nd, int s, int e, int l, int r) {
	if(s>r||e<l)
		return 0;
	pushdown(nd,s,e);
	if(l<=s&&e<=r)
		return tr[nd].sum;
	int m=(s+e)>>1;
	return sum(nd<<1,s,m,l,r)+sum(nd<<1|1,m+1,e,l,r);
}
int max(int nd, int s, int e, int l, int r) {
	if(s>r||e<l)
		return 0;
	pushdown(nd,s,e);
	if(l<=s&&e<=r)
		return tr[nd].val[0];
	int m=(s+e)>>1;
	return max(max(nd<<1,s,m,l,r),max(nd<<1|1,m+1,e,l,r));
}
void solve() {
	int n,m;
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	a[1]=0;
	build(1,1,m+1);
	vector<pair<pii, int>> hol;
	fr(i,1,n)
	{
		int xi,si;
		cin>>xi>>si;
		xi++;
		for(int j=0; j<=m; j++)
			hol.pb({{min(m+1,xi+j),max(1,xi-j)},max(j-si,0)});
	}
	sort(all(hol));
	for(auto i:hol)
		update(1, 1, m+1, 1, i.fi.fi, sum(1,1,m+1,i.fi.se-1,i.fi.se-1)+i.se);
	cout<<sum(1,1,m+1,m+1,m+1)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}