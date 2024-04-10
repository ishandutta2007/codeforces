#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
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
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int mod;
const int N=1e5+5;
int tr[4*N],lazy[4*N];
vi gc[4*N],lazygc[4*N];
int mul[9][18*N];
vi facs;
int a[N];
int gcdExtended(int a, int b, int *x, int *y) {
	if(a==0) {
		*x=0,*y=1;
		return b;
	}
	int x1,y1;
	int gcd=gcdExtended(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}
int modInverse(int a, int m) {
	int x,y;
	int g=gcdExtended(a,m,&x,&y);
	return (x%m+m)%m;
}
void apply(int seg, int x, const vi &hol) {
	tr[seg]=(tr[seg]*x)%mod;
	lazy[seg]=(lazy[seg]*x)%mod;
	for(int i=0; i<sz(hol); i++) {
		gc[seg][i]+=hol[i];
		lazygc[seg][i]+=hol[i];
	}
}
void pushdown(int seg) {
	apply(seg<<1,lazy[seg],lazygc[seg]);
	apply(seg<<1|1,lazy[seg],lazygc[seg]);
	lazy[seg]=1;
	for(int &i:lazygc[seg])
		i=0;
}
void update(int seg, int ll, int rr, int l, int r, int x, const vi &hol) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		apply(seg,x,hol);
		return;
	}
	pushdown(seg);
	update(seg<<1,ll,(ll+rr)/2,l,r,x,hol);
	update(seg<<1|1,(ll+rr)/2+1,rr,l,r,x,hol);
	for(int i=0; i<sz(facs); i++)
		gc[seg][i]=min(gc[seg<<1][i],gc[seg<<1|1][i]);
	int m1=tr[seg<<1],m2=tr[seg<<1|1];
	for(int i=0; i<sz(facs); i++) {
		m1=(m1*mul[i][gc[seg<<1][i]-gc[seg][i]])%mod;
		m2=(m2*mul[i][gc[seg<<1|1][i]-gc[seg][i]])%mod;
	}
	tr[seg]=(m1+m2)%mod;
	trace(seg,ll,rr);
}
int query(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return 0;
	if(l<=ll&&rr<=r) {
		int poo=tr[seg];
		rep(i,0,sz(facs))
			poo=(poo*mul[i][gc[seg][i]])%mod;
		return poo;
	}
	pushdown(seg);
	return (query(seg<<1,ll,(ll+rr)/2,l,r)+query(seg<<1|1,(ll+rr)/2+1,rr,l,r))%mod;
}
vi convert(int &x) {
	vi a(sz(facs));
	for(int i=0; i<sz(facs); i++)
		while(x%facs[i]==0) {
			a[i]++;
			x/=facs[i];
		}
	return a;
}
void build(int seg, int l, int r) {
	if(l==r) {
		tr[seg]=a[l];
		gc[seg]=convert(tr[seg]);
		lazygc[seg].resize(sz(facs),0LL);
		lazy[seg]=1;
	} else {
		build(seg<<1,l,(l+r)/2);
		build(seg<<1|1,(l+r)/2+1,r);
		gc[seg].resize(sz(facs));
		lazygc[seg].resize(sz(facs),0LL);
		lazy[seg]=1;
		for(int i=0; i<sz(facs); i++)
			gc[seg][i]=min(gc[seg<<1][i],gc[seg<<1|1][i]);
		int m1=tr[seg<<1],m2=tr[seg<<1|1];
		for(int i=0; i<sz(facs); i++) {
			m1=(m1*mul[i][gc[seg<<1][i]-gc[seg][i]])%mod;
			m2=(m2*mul[i][gc[seg<<1|1][i]-gc[seg][i]])%mod;
		}
		tr[seg]=(m1+m2)%mod;
	}
}
void solve() {
	int n;
	cin>>n>>mod;
	int m=mod;
	for(int i=2; i*i<=m; i++)
		if(m%i==0) {
			facs.pb(i);
			m/=i;
			while(m%i==0)
				m/=i;
		}
	if(m!=1)
		facs.pb(m);
	rep(i,0,sz(facs)) {
		mul[i][0]=1;
		rep(j,1,18*N)
			mul[i][j]=(mul[i][j-1]*facs[i])%mod;
	}
	fr(i,1,n)
		cin>>a[i];
	build(1,1,n);
	int q;
	cin>>q;
	while(q--) {
		int ty;
		cin>>ty;
		trace(ty);
		if(ty==1) {
			int l,r,x;
			cin>>l>>r>>x;
			vi pol=convert(x);
			update(1,1,n,l,r,x,pol);
		} else if(ty==2) {
			int l,r,x;
			cin>>l>>x;
			vi pol=convert(x);
			x=modInverse(x,mod);
			for(int &i:pol)
				i=-i;
			update(1,1,n,l,l,x,pol);
		} else {
			int l,r;
			cin>>l>>r;
			trace(l,r);
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}