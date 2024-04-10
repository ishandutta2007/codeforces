/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
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
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int N=2e5+5;
map<int,pii> segs;
int rip[N],eaten[N];
multiset<pii> pending;
void expand(int i, int j, int k) {
	auto lul=pending.lower_bound({i,0});
	vector<pii> remov;
	while(lul!=pending.end()&&(*lul).fi<=j) {
		j+=(*lul).se;
		rip[k]+=(*lul).se;
		eaten[k]++;
		remov.pb((*lul));
		lul++;
	}
	for(auto i:remov) {
		pending.erase(i);
	}
	trace(sz(pending));
	auto tol=segs.upper_bound(i);
	vi remove;
	while(tol!=segs.end()&&(*tol).se.fi<=j) {
		remove.pb((*tol).fi);
		tol++;
	}
	if(tol!=segs.end()&&(*tol).fi<=j) {
		auto hu=(*tol);
		segs.erase(hu.fi);
		segs[j+1]=hu.se;
	}
	for(int i:remove)
		segs.erase(i);
	segs[i]={j,k};
}

void solve() {
	int n,m,x,t;
	cin>>n>>m;
	vector<pair<int,pii>> please;
	fr(i,1,n) {
		cin>>x>>t;
		rip[i]=t;
		please.pb({x,{x+t,i}});
	}
	sort(all(please));
	reverse(all(please));
	for(auto i:please) {
		segs[i.fi]=i.se;
		expand(i.fi,i.se.fi,i.se.se);
	}
	while(m--) {
		int mos,si;
		cin>>mos>>si;
		pending.insert({mos,si});
		auto lol=segs.upper_bound(mos);
		if(lol==segs.begin()) {
			continue;
		}
		lol--;
		expand((*lol).fi,(*lol).se.fi,(*lol).se.se);
	}
	fr(i,1,n) {
		cout<<eaten[i]<<" "<<rip[i]<<endl;
	}
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
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}