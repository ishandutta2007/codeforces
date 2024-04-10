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
static const H M = 1e9+7;
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
map<int,vi> occur;
int last[100005];
void solve() {
	int n,te;
	vi a;
	cin>>n;
	rep(i,0,n) {
		cin>>te;
		a.pb(te);
		if(occur.find(a.back())==occur.end())
			occur[a.back()]=vi();
		occur[a.back()].pb(i);
		trace(a.back(),i);
	}
	HashInterval lol(a,5),lol2(a,998244353);
	rep(i,0,n) {
		for(int j:occur[a[i]]) {
			if(j==i)
				break;
			int len=i-j;
			if(j+1<len)
				continue;
			if(lol.hashInterval(i+1-len, i+1)==lol.hashInterval(j+1-len, j+1)) {
				if(lol2.hashInterval(i+1-len, i+1)==lol2.hashInterval(j+1-len, j+1)) {
					last[i]=len;
				}
			}
		}
	}
	vector<pii> pq;
	rep(i,0,n)
		if(last[i])
			pq.pb({last[i],i});
	sort(all(pq));
	int at=0;
	for(auto i:pq) {
		int last=i.se-2*i.fi;
		if(last+1<at)
			continue;
		at=i.se-i.fi+1;
	}
	cout<<n-at<<endl;
	rep(i,at,n)
		cout<<a[i]<<" ";
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