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


string a[51];
vector<pii> ans;
void execute(int i, int j) {
	ans.pb({i,j});
	if(a[i][j]=='L') {
		a[i][j]='U';
		a[i][j+1]='U';
		a[i+1][j]='D';
		a[i+1][j+1]='D';
	} else {
		a[i][j]='L';
		a[i][j+1]='R';
		a[i+1][j]='L';
		a[i+1][j+1]='R';
	}
}
void go(int i, int j) {
	if(a[i+1][j]=='L') {
		execute(i,j);
	} else if(a[i+1][j]=='U'&&a[i+1][j+1]=='U') {
		execute(i+1,j);
		execute(i,j);
	} else {
		go(i+1,j+1);
		execute(i+1,j);
		execute(i,j);
	}
}
void reduce(int n, int m) {
	for(int i=1; i+1<=n; i+=2)
		fr(j,1,m) {
			if(a[i][j]=='U')
				continue;
			go(i,j);
		}
}
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
		a[i]='0'+a[i];
	}
	reduce(n,m);
	vector<pii> lol=ans;
	ans.clear();
	fr(i,1,n) {
		cin>>a[i];
		a[i]='0'+a[i];
	}
	reduce(n,m);
	reverse(all(ans));
	cout<<sz(lol)+sz(ans)<<endl;
	for(auto i:lol)
		cout<<i.fi<<" "<<i.se<<endl;
	for(auto i:ans)
		cout<<i.fi<<" "<<i.se<<endl;
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