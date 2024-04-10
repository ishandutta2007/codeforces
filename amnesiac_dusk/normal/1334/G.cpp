#pragma GCC optimize("unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
//#define int long long
typedef long long ll;
typedef long double f80;
//#define double long double
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
const double PI=acosl(-1);
//FFT code from cactl
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C> &a) {
	int n=sz(a),L=31-__builtin_clz(n);
	static vector<complex<double>> R(2,1);
	static vector<C> rt(2,1); // (^ 10% faster if double)
	for (static int k = 2; k<n; k*=2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0, PI / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x :
		R[i/2];
	}
	vi rev(n);
	rep(i,0,n)
		rev[i]=(rev[i/2]|(i&1)<<L)/2;
	rep(i,0,n)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
	for(int k=1; k<n; k*=2)

		for(int i=0; i<n; i+=2*k)
			rep(j,0,k)
			{
				C z=rt[j+k]*a[i+j+k];
				a[i+j+k]=a[i+j]-z;
				a[i+j]+=z;
			}
}
vector<C> out;
int nn;
void conv(const vd &a, const vd &b) {
	vd res(sz(a)+sz(b)-1);
	int L=32-__builtin_clz(sz(res)),n=1<<L;
	nn=n;
	vector<C> in(n);
	out.resize(n);
	copy(all(a),begin(in));
	rep(i,0,sz(b))
		in[i].imag(b[i]);
	fft(in);
	trav(x, in) x *= x;
	rep(i,0,n)
		out[i]+=in[-i&(n-1)]-conj(in[i]);
//	fft(out);
//	rep(i,0,sz(res))
//		res[i]=imag(out[i])/(4*n);
//	return res;
}


int p[26];
void solve() {
	for(int i=0; i<26; i++) {
		cin>>p[i];
		p[i]--;
	}
	string s,t;
	cin>>s>>t;
	vd ans;
	for(char &i:s)
		i-='a';
	for(char &i:t)
		i-='a';
	rep(j,0,26) {
		vd a,b;
		for(int i=0; i<sz(t); i++)
			if(t[i]==j)
				a.pb(1);
			else
				a.pb(0);
		for(int i=0; i<sz(s); i++) {
			if(s[i]==j||p[s[i]]==j)
				b.pb(1);
			else
				b.pb(0);
		}
		reverse(all(b));
		conv(a,b);
	}
	fft(out);
	vi pol(sz(s)+sz(t)-1,0);
	for(int i=sz(s)-1; i<sz(t); i++) {
		pol[i]=(imag(out[i])/(4*nn)+0.5);
		if(pol[i]==sz(s)) {
			cout<<'1';
		} else
			cout<<'0';
	}

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}