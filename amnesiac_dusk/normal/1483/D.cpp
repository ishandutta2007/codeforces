#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
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
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


int dis[605][605];
vector<pii> bak[605];
int allowed[605];
vector<pair<pii,int>> gra[605];
int yes[605*605];
int dist[605];
void solve() {
	int n,m;
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	fr(i,1,n)
		dis[i][i]=0;
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({{v,w},i});
		gra[v].pb({{u,w},i});
		dis[u][v]=dis[v][u]=w;
	}
	fr(j,1,n)
		fr(i,1,n)
			fr(k,1,n)
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	int q;
	cin>>q;
	while(q--) {
		int u,v,l;
		cin>>u>>v>>l;
		bak[u].pb({v,l});
		bak[v].pb({u,l});
	}
	fr(i,1,n) {
		fr(j,1,n) {
			allowed[j]=0;
			for(auto k:bak[i])
				allowed[j]=max(allowed[j],k.se-dis[j][k.fi]);
			dist[j]=infi;
		}
		priority_queue<pii,vector<pii>,greater<pii>> go;
		go.push({0,i});
		dist[i]=0;
		fr(j,1,n) {
			for(auto k:gra[j]) {
				if(allowed[k.fi.fi]>=dis[i][j]+k.fi.se) {
					yes[k.se]=1;
				}
			}
		}
//		while(go.size()) {
//			int at=go.top().se;
//			int di=go.top().fi;
//			go.pop();
//			if(dist[at]!=di)
//				continue;
//			for(auto &j:gra[at]) {
//				if(allowed[j.fi.fi]>=di+j.fi.se) {
//					if(dist[j.fi.fi]>di+j.fi.se) {
//						dist[j.fi.fi]=di+j.fi.se;
//						go.push({dist[j.fi.fi],j.fi.fi});
//					}
//					yes[j.se]=1;
//				}
//			}
//		}
	}
	cout<<accumulate(yes+1,yes+m+1,0LL)<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}