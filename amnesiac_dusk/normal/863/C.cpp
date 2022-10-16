//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int bob[3][3];
int alice[3][3];
int alices=0,bobs=0;
int state[3][3];
int win[3][3];
pii ptstat[3][3];
void play(int moves,int left, int stb, int sta) {
	if(left==0)
		return;
	if(state[stb][sta]&&left%(moves-state[stb][sta])==0) {
		alices+=(alices-ptstat[stb][sta].se)*(left/(moves-state[stb][sta]));
		bobs+=(bobs-ptstat[stb][sta].fi)*(left/(moves-state[stb][sta]));
		return;
	}
	state[stb][sta]=moves;
	ptstat[stb][sta].se=alices;
	ptstat[stb][sta].fi=bobs;
	alices+=win[sta][stb];
	bobs+=win[stb][sta];
	play(moves+1,left-1,bob[stb][sta],alice[stb][sta]);
}
void solve() {
	int k,a,b;
	win[1][0]=1;
	win[2][1]=1;
	win[0][2]=1;
	cin>>k>>a>>b;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++) {
			cin>>alice[j][i];
			alice[j][i]--;
		}
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			cin>>bob[j][i];
			bob[j][i]--;
		}
	play(1,k,b-1,a-1);
	cout<<alices<<" "<<bobs<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}