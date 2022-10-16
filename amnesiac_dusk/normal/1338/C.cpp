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

bool gone[10000005];
vi pol={0,0,0,1,2,3,2,3,1,3,1,2};
int disp[60];
int per[60];
void solve() {
	disp[0]=0;
	per[0]=1;
	for(int i=1; i<=30; i++) {
		per[i]=per[i-1]*4;
		disp[i]=disp[i-1]+per[i-1];
	}
	int n;
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0;
		for(int i=29; i>0; i--) {
			ans<<=2;
			int tol=n;
			if(tol<=disp[i-1]*3)
				continue;
			else if(tol<=disp[i]*3) {
				ans|=pol[3+(tol+2)%3];
			} else {
				tol-=disp[i]*3;
//				trace(1,tol,((tol-1)/(3*per[i-1])+4)%4+(tol-1)%3);
				ans|=pol[((tol-1)/(3*per[i-1]))%4*3+(tol-1)%3];
			}
//			trace(i,ans);
		}
//		cout<<bitset<10>(ans)<<endl;
		cout<<ans<<endl;
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