/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
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
vi sizor[100005];
int lol[100005];
void solve() {
	int n,m,a,b;
	cin>>n>>m;
	fr(i,1,m) {
		cin>>a>>b;
		if(a<b)
			swap(a,b);
		if(a-b>=n/2) {
			sizor[n+b-a].pb(b);
		}
		if(a-b<=n/2)
			sizor[a-b].pb(a);
	}
	int lc=1;
//	vi pfs;
//	int nn=n;
//	for(int i=2; i<=n; i++) {
//		if(nn%i==0) {
//			pfs.pb(i);
//			nn/=i;
//		}
//		while(nn%i==0)
//			nn/=i;
//	}
	fr(i,1,n) {
		sort(all(sizor[i]));
		trace(sz(sizor[i]));
	}
	for(int i=1; i<n; i++) {
		if(n%i==0) {
			bool po=1;
			for(int j=1; j<=n/2&&po; j++) {
				trace(i,j);
				for(int k:sizor[j]) {
					lol[k]++;
				}
				trace(i,j);
				for(int k:sizor[j]) {
					trace(k);
					if(k<=i) {
						int te=lol[k];
						trace(te);
						while(k<=n) {
							if(lol[k]!=te) {
								po=0;
								break;
							} else
								lol[k]=0;
							trace(k);
							k+=i;
						}
						if(po==0)
							break;
					} else if(lol[k]) {
						po=0;
						break;
					}
				}
				trace(i,j);
				for(int k:sizor[j])
					lol[k]=0;
				trace(i,j);
			}
			if(po) {
				cout<<"Yes"<<endl;
				return;
			}
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
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}