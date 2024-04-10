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

pii a[100005];
int pre[100005];
void solve() {
	int n,A,cf,cm,m;
	cin>>n>>A>>cf>>cm>>m;
	fr(i,1,n) {
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	if(A*n-pre[n]<=m) {
		cout<<n*cf+cm*A<<endl;
		fr(i,1,n)
			cout<<A<<" ";
		return;
	}
	fr(i,1,n)
		pre[i]=pre[i-1]+a[i].fi;
	int ans=0,mol=n,molod=0;
	for(int i=n; i>=0&&m>=0; i--) {
		int lo=0,hi=A,mid=(lo+hi+1)/2;
		while(lo<hi) {
			auto it=upper_bound(a+1,a+i+1,pii{mid,0})-a;
			it--;
			if(mid*it-pre[it]>m) {
				hi=mid-1;
			} else
				lo=mid;
			mid=(lo+hi+1)/2;
		}
		if(ans<(n-i)*cf+mid*cm) {
			ans=(n-i)*cf+mid*cm;
			mol=i;
			molod=mid;
		}
		m-=A-a[i].fi;
	}
	fr(i,1,n)
		a[i].fi=max(a[i].fi,molod);
	fr(i,mol+1,n)
		a[i].fi=A;
	sort(a+1,a+n+1,[](pii i, pii j){
		return i.se<j.se;
	});
	cout<<ans<<endl;
	fr(i,1,n)
		cout<<a[i].fi<<" ";
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