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

int supar[1005];
int par[1005];
int a[505][505];
int salary[1005];
int fpar(int i) {
	return (supar[i]==i)?i:supar[i]=fpar(supar[i]);
}
void solve() {
	int n;
	cin>>n;
	vector<pair<int,pii>> pp;
	fr(i,1,n)
		fr(j,1,n) {
			cin>>a[i][j];
			if(i<j)
				pp.pb({a[i][j],{i,j}});
			else if(i==j)
				salary[i]=a[i][j];
	}
	sort(all(pp));
	int cntr=n;
	fr(i,1,2*n-1)
		supar[i]=i;
	for(auto i:pp) {
		if(salary[fpar(i.se.fi)]==i.fi&&salary[fpar(i.se.se)]==i.fi)
			continue;
		else if(salary[fpar(i.se.fi)]!=i.fi&&salary[fpar(i.se.se)]!=i.fi) {
			par[fpar(i.se.fi)]=++cntr;
			par[fpar(i.se.se)]=cntr;
			supar[fpar(i.se.fi)]=cntr;
			supar[fpar(i.se.se)]=cntr;
			salary[cntr]=i.fi;
		} else if(salary[fpar(i.se.fi)]==i.fi){
			par[fpar(i.se.se)]=fpar(i.se.fi);
			supar[fpar(i.se.se)]=fpar(i.se.fi);
		} else {
			par[fpar(i.se.fi)]=fpar(i.se.se);
			supar[fpar(i.se.fi)]=fpar(i.se.se);
		}
	}
	cout<<cntr<<endl;
	fr(i,1,cntr)
		cout<<salary[i]<<" \n"[i==cntr];
	cout<<cntr<<endl;
	rep(i,1,cntr)
		cout<<i<<" "<<par[i]<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}