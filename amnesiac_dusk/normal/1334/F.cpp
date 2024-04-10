#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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

int a[500005],p[500005],b[500005];
const int N=5e5+5;
int tr[4*N],lazy[4*N];
void update(int seg, int ll, int rr, int l, int r, int val) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		tr[seg]+=val;
		return;
	}
	if(tr[seg]) {
		tr[seg<<1]+=tr[seg];
		tr[seg<<1|1]+=tr[seg];
		tr[seg]=0;
	}
	update(seg<<1,ll,(ll+rr)/2,l,r,val);
	update(seg<<1|1,(ll+rr)/2+1,rr,l,r,val);
}
void sett(int seg, int ll, int rr, int p, int val) {
	if(ll>p||p>rr)
		return;
	if(p==ll&&p==rr) {
		if(tr[seg]>val)
			tr[seg]=val;
		return;
	}
	if(tr[seg]) {
		tr[seg<<1]+=tr[seg];
		tr[seg<<1|1]+=tr[seg];
		tr[seg]=0;
	}
	sett(seg<<1,ll,(ll+rr)/2,p,val);
	sett(seg<<1|1,(ll+rr)/2+1,rr,p,val);
}
int get(int seg, int ll, int rr, int p) {
	if(ll>p||p>rr)
		return 0;
	if(p==ll&&p==rr)
		return tr[seg];
	if(tr[seg]) {
		tr[seg<<1]+=tr[seg];
		tr[seg<<1|1]+=tr[seg];
		tr[seg]=0;
	}
	return get(seg<<1,ll,(ll+rr)/2,p)+get(seg<<1|1,(ll+rr)/2+1,rr,p);
}

void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	fr(i,1,n)
		cin>>p[i];
	int m;
	cin>>m;
	fr(i,1,m)
		cin>>b[i];
	update(1,0,m,1,m,infl);
	fr(i,1,n) {
		auto it=lower_bound(b+1,b+m+1,a[i])-b;
		int got;
		if(b[it]==a[i])
			got=get(1,0,m,it-1);
		it--;
		if(p[i]>0) {
			update(1,0,m,0,it,p[i]);
		} else {
			update(1,0,m,0,m,p[i]);
		}
		if(b[it+1]==a[i])
			sett(1,0,m,it+1,got);
	}
	int tol=get(1,0,m,m);
	if(tol<1e16) {
		cout<<"YES"<<endl;
		cout<<tol<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}