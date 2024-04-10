#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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

typedef long long H;
static const H M = 2000000033;
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};
struct HashInterval {
	vector<K> ha, pw;
	H C;
	HashInterval(vi& str,H Co) : ha(sz(str)+1), pw(ha) {
		C=Co;
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	HashInterval(string& str, H C) : ha(sz(str)+1), pw(ha), C(C) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

void solve() {
	int n,w;
	cin>>n>>w;
	vi a,b,c;
	int b1=chrono::high_resolution_clock::now().time_since_epoch().count()%M;
	fr(i,1,n) {
		int te;
		cin>>te;
		a.pb(te);
		c.pb(1);
	}
	fr(i,1,w) {
		int te;
		cin>>te;
		b.pb(te);
	}
	int b2=chrono::high_resolution_clock::now().time_since_epoch().count()%M;
	HashInterval la(a,b1),la2(a,b2);
	HashInterval lb(b,b1),lb2(b,b2);
	HashInterval lc(c,b1),lc2(c,b2);
	int bh1=lb.hashInterval(0, w),bh2=lb2.hashInterval(0, w);
	int sh1=lc.hashInterval(0, w),sh2=lc2.hashInterval(0, w);
	int ans=0;
	for(int i=0; i+w<=n; i++) {
		int shift1=(la.hashInterval(i, i+w)+sh1*(b[0]-a[i]))%M;
		if(shift1<0)
			shift1+=M;
		if(shift1==bh1) {
			shift1=(la2.hashInterval(i, i+w)+sh2*(b[0]-a[i]))%M;
			if(shift1<0)
				shift1+=M;
			if(shift1==bh2)
				ans++;
		}
	}
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
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