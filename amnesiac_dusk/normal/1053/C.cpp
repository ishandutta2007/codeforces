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
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
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

const int N=2e5+5;
int a[N],tr[4*N];
int w[N];
int tro[4*N];
void update(int seg, int ll, int rr, int p, int val) {
	int m=(ll+rr)/2;
	if(ll==p&&p==rr) {
		tr[seg]=val;
		tro[seg]=((a[p]-p)*val)%mod;
		return;
	}
	else if(p<=m)
		update(seg<<1,ll,m,p,val);
	else
		update(seg<<1|1,m+1,rr,p,val);
	tr[seg]=tr[seg<<1]+tr[seg<<1|1];
	tro[seg]=tro[seg<<1]+tro[seg<<1|1];
}
int sum(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return 0;
	if(l<=ll&&rr<=r)
		return tr[seg];
	return sum(seg<<1,ll,(ll+rr)/2,l,r)+sum(seg<<1|1,(ll+rr)/2+1,rr,l,r);
}
int sum2(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return 0;
	if(l<=ll&&rr<=r)
		return tro[seg];
	return sum2(seg<<1,ll,(ll+rr)/2,l,r)+sum2(seg<<1|1,(ll+rr)/2+1,rr,l,r);
}
int descent(int seg, int ll, int rr, int l, int r, int val) {
	if(ll>r||l>rr)
		return -val;
	if(l<=ll&&rr<=r)
		if(tr[seg]<val)
			return tr[seg]-val;
	if(ll==rr) {
		if(tr[seg]>=val)
			return ll;
		else
			return tr[seg]-val;
	}
	int lol=descent(seg<<1,ll,(ll+rr)/2,l,r,val);
	if(lol>0)
		return lol;
	return descent(seg<<1|1,(ll+rr)/2+1,rr,l,r,-lol);
}

void solve() {
	int n,q;
	cin>>n>>q;
	fr(i,1,n)
		cin>>a[i];
	fr(i,1,n) {
		cin>>w[i];
		update(1,1,n,i,w[i]);
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		if(x<0) {
			x*=-1;
			update(1,1,n,x,y);
		} else {
			int su=sum(1,1,n,x,y);
			int pos=descent(1,1,n,x,y,(su+1)/2);
			int sum1=sum2(1,1,n,pos,y)-(sum(1,1,n,pos,y)%mod)*(a[pos]-pos);
			int sum3=(sum(1,1,n,x,pos)%mod)*(a[pos]-pos)-sum2(1,1,n,x,pos);
			cout<<((sum1+sum3+2*mod)%mod+mod)%mod<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}