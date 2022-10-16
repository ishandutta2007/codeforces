#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
//#define int long long
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

bool check(string s) {
	int sum=0;
	for(int i=0; i<sz(s); i++) {
		if(s[i]=='(')
			sum++;
		else
			sum--;
		if(sum<0)
			return 0;
	}
	return 1;
}
void solve() {
	int n;
	string s;
	cin>>n>>s;
	int sum=0;
	for(int i=0; i<sz(s); i++) {
		if(s[i]=='(')
			sum++;
		else
			sum--;
	}
	trace(sum);
	if(sum) {
		cout<<"No"<<endl;
		return;
	}
	if(check(s)) {
		cout<<"Yes"<<endl;
		return;
	}
	for(int i=0; i<sz(s); i++) {
		if(s[i]==')') {
			string t=s.substr(0,i)+s.substr(i+1)+")";
			if(check(t)) {
				cout<<"Yes"<<endl;
				return;
			}
			break;
		}
	}
	for(int i=sz(s)-1; i>=0; i--) {
		if(s[i]=='(') {
			string t="("+s.substr(0,i)+s.substr(i+1);
			if(check(t)) {
				cout<<"Yes"<<endl;
				return;
			}
			break;
		}
	}
	cout<<"No"<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}