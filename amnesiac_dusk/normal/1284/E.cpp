#pragma GCC optimize("unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
typedef tree<double, null_type, less<double>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


pair<int, int> A[2505];
int Under[2505][2505];
void solve() {
	int n=2500;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>A[i].first>>A[i].second;
//		A[i].fi=rand();
//		A[i].se=rand();
	}
	sort(A+1,A+n+1);
	for(int i=1; i<=n; i++) {
		oset lol;
		for(int j=i+1; j<=n; j++) {
			double temp=atan2l(A[j].fi-A[i].fi,A[j].se-A[i].se);
			Under[i][j]=lol.order_of_key(temp);
			lol.insert(temp);
		}
	}
	long long rez=0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			for(int k=j+1; k<=n; k++) {
				rez+=max(Under[i][k]-Under[i][j]-Under[j][k]-1,Under[i][j]+Under[j][k]-Under[i][k]);
			}
	cout<<(rez*(n-4))/2<<endl;
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
}