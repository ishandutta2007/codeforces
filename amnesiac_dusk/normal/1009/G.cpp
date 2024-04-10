/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e12;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

bool allowed[100005][6];
int masks[100005];
int counts[6],places[64],subset[64];
bool check() {
	for(int i=0; i<64; i++) {
		subset[i]=places[i];
	}
	for(int i=0; i<6; i++)
		for(int j=0; j<64; j++)
			if(j&(1<<i))
				subset[j]+=subset[j^(1<<i)];
	for(int i=0; i<64; i++) {
		int chars=0;
		for(int j=0; j<6; j++)
			if(i&(1<<j))
				chars+=counts[j];
		if(subset[63]-subset[i^63]<chars) {
			return 0;
		}
	}
	return 1;
}
void solve() {
	memset(allowed,1,sizeof(allowed));
	string s;
	int n;
	cin>>s>>n;
	s='a'+s;
	fr(i,1,sz(s)-1)
		counts[s[i]-'a']++;
	fr(i,1,n) {
		int p;
		cin>>p;
		string te;
		cin>>te;
		for(int j=0; j<6; j++)
			allowed[p][j]=0;
		for(char j:te)
			allowed[p][j-'a']=1;
	}
	fr(i,1,sz(s)-1) {
		for(int j=0; j<6; j++)
			if(allowed[i][j])
				masks[i]|=1<<j;
		places[masks[i]]++;
	}
	string ans="";
	if(check()==0) {
		cout<<"Impossible"<<endl;
	}
	fr(i,1,sz(s)-1) {
		places[masks[i]]--;
		fr(j,'a','f') {
			if(allowed[i][j-'a']) {
				ans+=(char)j;
				counts[j-'a']--;
				if(check())
					break;
				counts[j-'a']++;
				ans.pop_back();
			}
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
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}