#pragma GCC optimize("Ofast")
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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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



int val[5005][5005][2];
void solve() {
	int n,m;
	cin>>n>>m;
	map<string,int> ind;
	ind["?"]=0;
	rep(i,0,m)
		val[0][i][1]=1;
	fr(i,1,n) {
		string pe;
		cin>>pe;
		ind[pe]=i;
		string te1;
		cin>>te1>>te1;
		if(ind.find(te1)!=ind.end()) {
			string op,te2;
			cin>>op>>te2;
			int ff=ind[te1],ss=ind[te2];
			if(op=="AND") {
				rep(j,0,m){
					if(val[ff][j][0]&&val[ss][j][0])
						val[i][j][0]=1;
					if(val[ff][j][1]&&val[ss][j][1])
						val[i][j][1]=1;
				}
			} else if(op=="OR") {
				rep(j,0,m){
					if(val[ff][j][0]||val[ss][j][0])
						val[i][j][0]=1;
					if(val[ff][j][1]||val[ss][j][1])
						val[i][j][1]=1;
				}
			} else {
				rep(j,0,m){
					if(val[ff][j][0]^val[ss][j][0])
						val[i][j][0]=1;
					if(val[ff][j][1]^val[ss][j][1])
						val[i][j][1]=1;
				}
			}
		} else {
			rep(j,0,m)
				val[i][j][0]=val[i][j][1]=te1[j]-'0';
		}
	}
	string ans="",ans2="";
	rep(i,0,m) {
		int su=0;
		fr(j,1,n) {
			su+=val[j][i][1]-val[j][i][0];
			trace(i,j,su);
		}
		if(su>0) {
			ans+='0';
			ans2+='1';
		} else if(su<0) {
			ans+='1';
			ans2+='0';
		} else
			ans+='0',ans2+='0';
	}
	cout<<ans<<endl<<ans2<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}