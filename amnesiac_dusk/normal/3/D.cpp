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

int lint[50005];
int a[50005],b[50005];
void solve() {
	string s;
	cin>>s;
	int n=sz(s);
	rep(i,0,n) {
		if(s[i]=='?')
			cin>>a[i]>>b[i];
	}
	string ori=s;
	int sigma=0;
	for(int i=sz(s)-1; i>=0; i--) {
		lint[i]=sigma;
		if(s[i]==')'||sigma<=0)
			sigma++;
		else
			sigma--;
		trace(lint[i]);
	}
	if(sigma>0) {
		cout<<-1<<endl;
		return;
	}
	trace(s);
	sigma=0;
	int cost=0;
	for(int i=0; i<sz(s); i++) {
		if(s[i]=='?') {
			trace(sigma,lint[i],i);
			if(sigma<lint[i]||sigma<=0) {
				sigma++;
				s[i]='(';
				cost+=a[i];
			} else {
				sigma--;
				s[i]=')';
				cost+=b[i];
			}
		} else if(s[i]=='(') {
			sigma++;
		} else
			sigma--;
		trace(s);
	}
	if(sigma>0) {
		cout<<-1<<endl;
		return;
	}
	trace(s);
	priority_queue<pii,vector<pii>,less<pii>> tol;
	for(int i=0; i<sz(s); i++) {
		if(ori[i]=='?') {
			if(s[i]=='(') {
				if(tol.size()&&tol.top().fi>b[i]-a[i]) {
					swap(s[tol.top().se],s[i]);
					cost-=tol.top().fi;
					cost+=b[i]-a[i];
					tol.pop();
					tol.push({b[i]-a[i],i});
				}
			}
			else {
				tol.push({b[i]-a[i],i});
			}
		}
	}
	cout<<cost<<endl<<s<<endl;
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