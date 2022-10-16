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
 const int mod=998244353;
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

const int N=3e5+5;
int tr[4*N],lazy[4*N];
void update(int seg, int ll, int rr,int l, int r, int val) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		tr[seg]+=val;
		lazy[seg]+=val;
		return;
	}
	if(lazy[seg]) {
		tr[seg<<1]+=lazy[seg];
		tr[seg<<1|1]+=lazy[seg];
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		lazy[seg]=0;
	}
	update(seg<<1,ll,(ll+rr)/2,l,r,val);
	update(seg<<1|1,(ll+rr)/2+1,rr,l,r,val);
	tr[seg]=min(tr[seg<<1],tr[seg<<1|1]);
}
int p[300005],q[300005];
int anti[300005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>p[i];
		anti[p[i]]=i;
	}
	int ans=n;
	update(1,1,n,1,anti[n],-1);
	fr(i,1,n) {
		while(tr[1]>=0) {
			ans--;
			update(1,1,n,1,anti[ans],-1);
		}
		cout<<ans<<" ";
		cin>>q[i];
		update(1,1,n,1,q[i],1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}