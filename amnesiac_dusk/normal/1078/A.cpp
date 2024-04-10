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

pair<double,double> go(int a, int b, int c, int x) {
	return {x,-(a*x+c+0.0L)/b};
}
void solve() {
	int a,b,c;
	int x1,x2,y1,y2;
	cin>>a>>b>>c;
	cin>>x1>>y1>>x2>>y2;
	double ans=abs(x1-x2)+abs(y1-y2);
	if(a==0||b==0) {
		cout<<ans<<endl;
		return;
	}
	vector<pair<double,double>> a1(2);
	vector<pair<double,double>> a2(2);
	a1[0]=go(a,b,c,x1);
	a1[1]=go(b,a,c,y1);
	swap(a1[1].fi,a1[1].se);
	a2[0]=go(a,b,c,x2);
	a2[1]=go(b,a,c,y2);
	swap(a2[1].fi,a2[1].se);
	for(auto i:a1) {
		for(auto j:a2) {
			double dist=abs(i.fi-x1)+abs(i.se-y1);
			dist+=abs(j.fi-x2)+abs(j.se-y2);
			dist+=sqrtl((i.fi-j.fi)*(i.fi-j.fi)+(i.se-j.se)*(i.se-j.se));
			trace(i,j,dist);
			ans=min(ans,dist);
		}
	}
	cout<<ans<<endl;
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