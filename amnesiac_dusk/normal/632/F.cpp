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
const int infi=2e9;
const int mod=490019;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int a[2501][2501];
int dsu[2501];
int siz[2501];
int fpar(int i) {
	return dsu[i]<0?i:dsu[i]=fpar(dsu[i]);
}
bool merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		siz[i]+=siz[j];
		dsu[j]=i;
		return 1;
	}
	return 0;
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		fr(j,1,n)
			cin>>a[i][j];
	fill(dsu+1,dsu+2501,-1);
	fill(siz+1,siz+2501,1);
	vector<pair<int,pii>> lol;
	fr(i,1,n)
		fr(j,i,n) {
			if(a[i][j]!=a[j][i]) {
				cout<<"NOT MAGIC"<<endl;
				return;
			}
			if(i!=j)
				lol.push_back({a[i][j],{i,j}});
			else if(a[i][i]) {
				cout<<"NOT MAGIC"<<endl;
				return;
			}
		}
	lol.pb({infl,{infl,infl}});
	sort(all(lol));
	int sumc=0;
	for(int i=0; i+1<sz(lol); i++) {
		int su=siz[fpar(lol[i].se.fi)],su2=siz[fpar(lol[i].se.se)];
		if(merge(lol[i].se.fi,lol[i].se.se))
			sumc+=((su+su2)*(su+su2-1))/2-(su*(su-1))/2-(su2*(su2-1))/2;
		trace(sumc,lol[i].se.fi,lol[i].se.se);
		if(lol[i].fi!=lol[i+1].fi) {
			if(sumc!=i+1) {
				cout<<"NOT MAGIC"<<endl;
				return;
			}
		}
	}
	cout<<"MAGIC"<<endl;
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