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

int a[(1<<21)+5];
int rem[(1<<21)+5];
int n;
int lh=0;
bool remove(int at) {
	int left=at<<1;
	int right=at<<1|1;
	if(a[at]==0)
		return 1;
	if(rem[at]==0)
		return 0;
	if(a[left]>a[right]) {
		int tol=a[left];
		if(remove(left)) {
			a[at]=tol;
			rem[at]--;
			return 1;
		}
	} else {
		int tol=a[right];
		if(remove(right)) {
			a[at]=tol;
			rem[at]--;
			return 1;
		}
	}
	return 0;
}
void solve() {
	int h,g;
	cin>>h>>g;
	int trem=(1<<h)-(1<<g);
	n=(1<<h)-1;
	memset(a,0,sizeof(int)*(2*n+5));
	memset(rem,0,sizeof(int)*(2*n+5));
	fr(i,1,n)
		cin>>a[i];
	int tol=0;
	fr(i,1,n) {
		rem[i]=trem>>tol;
		if((i&(i+1))==0)
			tol++;
	}
	vi ans;
	fr(i,1,n)
		while(a[i]&&remove(i))
			ans.pb(i);
	int anser=0;
	fr(i,1,n)
		anser+=a[i];
	cout<<anser<<endl;
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}