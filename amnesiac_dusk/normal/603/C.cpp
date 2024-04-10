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

int grundy[105];
void solve() {
	fr(i,1,100) {
	set<int> lol;
	lol.insert(grundy[i-1]);
	if(!(i&1))
		lol.insert(grundy[i/2]);
	fr(j,0,2)
		if(lol.find(j)==lol.end()) {
			grundy[i]=j;
			break;
		}
		trace(i,grundy[i]);
	}
	int n,k;
	cin>>n>>k;
	k%=2;
	if(k==0) {
		int su=0;
		fr(i,1,n) {
			int te;
			cin>>te;
			if(te==1) {
				su^=1;
			} else if(te==2) {
				su^=2;
			} else
				su^=(te&1)^1;
		}
		if(su) {
			cout<<"Kevin"<<endl;
		} else {
			cout<<"Nicky"<<endl;
		}
	} else {
		int grun=0;
		fr(i,1,n) {
			int te;
			cin>>te;
			int gu=0;
			if(te==1||te==3) {
				grun^=1;
				continue;
			}
			if(te==2)
				continue;
			if(!(te&1)) {
				grun^=1;
				te>>=1;
			}
			while(te%2==0) {
				grun^=3;
				te>>=1;
			}
			if(te==3) {
				grun^=3;
			}
		}
		if(grun) {
			cout<<"Kevin"<<endl;
		} else {
			cout<<"Nicky"<<endl;
		}
	}
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