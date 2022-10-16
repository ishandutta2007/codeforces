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
int win[3][3];
pii dp[3][3];
int play(int k, int a, int b, int turn, int points) {
	if(k==0) {
		return 0;
	}
	if(dp[a][b].fi!=0&&k%(turn-dp[a][b].fi)==0) {
		int lol=k/(turn-dp[a][b].fi);
		k-=lol*(turn-dp[a][b].fi);
		return lol*(points-dp[a][b].se);
	}
	dp[a][b].fi=turn;
	dp[a][b].se=points;
	return win[a][b]+play(k-1,bob[a][b],alice[a][b],turn+1,win[a][b]+points);
}
int a[200005];
int b[105];
void solve() {
	int n,q,m;
	cin>>n>>q>>m;
	fr(i,1,n) {
		cin>>a[i];
	}
	int te,l,r;
	vector<pair<int,pii>> queries;
	fr(i,1,q) {
		cin>>te>>l>>r;
		queries.pb({te,{l,r}});
	}
	reverse(all(queries));
	fr(i,1,m)
		cin>>b[i];
	for(auto &query:queries) {
		fr(j,1,m) {
			if(query.se.fi<=b[j]&&b[j]<=query.se.se) {
				if(query.fi==1) {
					if(b[j]==query.se.fi)
						b[j]=query.se.se;
					else
						b[j]--;
				} else {
					int dist=b[j]-query.se.fi;
					b[j]=query.se.se-dist;
				}
			}
		}
	}
	fr(i,1,m)
			cout<<a[b[i]]<<" ";
//	int k,a,b;
//	win[0][0]=0;
//	win[1][1]=0;
//	win[2][2]=0;
//	win[1][0]=1;
//	win[2][0]=-1;
//	win[2][1]=1;
//	win[0][1]=-1;
//	win[0][2]=1;
//	win[1][2]=-1;
//	for(int i=0; i<3; i++)
//		for(int j=0; j<3; j++)
//			cin>>alice[j][i];
//	for(int i=0; i<3; i++)
//		for(int j=0; j<3; j++)
//			cin>>bob[j][i];
//	cout<<play(k,a,b,1,0);
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