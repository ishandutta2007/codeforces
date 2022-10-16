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


void solve() {
	int n,k;
	cin>>n>>k;
	vi ls,rs;
	vector<__int128> pls,prs;
	int mdif=infl;
	fr(i,1,n) {
		int l,r;
		cin>>l>>r;
		ls.pb(l);
		rs.pb(r);
		mdif=min(mdif,r-l+1);
	}
	sort(all(ls));
	sort(all(rs));
	prs.pb(rs[0]);
	pls.resize(n+1,0);
	for(int i=1; i<sz(rs); i++)
		prs.pb(rs[i]+prs[i-1]);
	for(int i=n-1; i>=0; i--)
		pls[i]=pls[i+1]+ls[i];
	int ans=0;
	vi a={4,7};
	for(int i=0; a.back()<=1000000000000000000LL; i++) {
		a.pb(a[i]*10+4);
		a.pb(a[i]*10+7);
	}
	a.pop_back();
	a.pop_back();
	for(int i=0,j=-1; i<sz(a); i++) {
		j=i+ans-1;
		while(j+1<sz(a)&&a[j+1]-a[i]<mdif) {
			j++;
			int r=a[j];
			int l=a[i];
			__int128 moves=0;
			int it1=lower_bound(all(rs),r)-rs.begin();
			if(it1) {
				it1--;
				moves+=(it1+1)*((__int128)r)-prs[it1];
			}
			int it2=lower_bound(all(ls),l)-ls.begin();
			moves+=pls[it2]-(n-it2)*((__int128)l);
			if(moves<=k)
				ans=max(ans,j-i+1);
			else
				break;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}