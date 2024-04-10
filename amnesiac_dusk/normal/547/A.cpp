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


pii holve(int a, int b, int x, int m, int ans) {
	int ff=0;
	while(ff<=m&&ans!=x) {
		x=(x*a+b)%m;
		ff++;
	}
	if(ff>m) {
		cout<<-1<<endl;
		exit(0);
	}
	int ss=1;
	x=(x*a+b)%m;
	while(ss<=m&&x!=ans) {
		x=(x*a+b)%m;
		ss++;
	}
	if(ss>m)
		return {ff,-1};
	return {ff,ss};
}
void solve() {
	int m;
	cin>>m;
	int h1,a1;
	int x1,y1;
	int h2,a2;
	int x2,y2;
	cin>>h1>>a1>>x1>>y1;
	cin>>h2>>a2>>x2>>y2;
	auto fol=holve(x1,y1,h1,m,a1);
	auto fol2=holve(x2,y2,h2,m,a2);
	if(fol.fi==fol2.fi) {
		cout<<fol.fi<<endl;
	} else if(fol.se==-1&&fol2.se==-1) {
		cout<<-1<<endl;
	} else if(fol.se==-1) {
		int tol=fol.fi-fol2.fi;
		if(tol%fol2.se||tol<0) {
			cout<<-1<<endl;
		} else
			cout<<fol.fi<<endl;
	} else if(fol2.se==-1) {
		swap(fol,fol2);
		int tol=fol.fi-fol2.fi;
		if(tol%fol2.se||tol<0) {
			cout<<-1<<endl;
		} else
			cout<<fol.fi<<endl;
	} else {
		for(int i=0; i<3*m; i++)
			if((fol.fi+i*fol.se-fol2.fi)>=0&&(fol.fi+i*fol.se-fol2.fi)%fol2.se==0) {
				cout<<fol.fi+i*fol.se<<endl;
				return;
			}
		cout<<-1<<endl;
	}
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