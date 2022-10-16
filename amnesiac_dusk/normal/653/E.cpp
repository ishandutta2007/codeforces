#pragma GCC optimze("Ofast")
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
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
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

set<int> forb[300005];
bool vis[300005];
int dsu[300005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
int merge(int u, int v) {
	if((u=fpar(u))!=(v=fpar(v))) {
		if(dsu[u]>dsu[v])
			swap(u,v);
		dsu[u]+=dsu[v];
		dsu[v]=u;
		return 1;
	} else
		return 0;
}
void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n,m,k;
	cin>>n>>m>>k;
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		forb[u].insert(v);
		forb[v].insert(u);
	}
	set<int> rem;
	fr(i,2,n)
		rem.insert(i);
	fr(i,2,n) {
		if(!vis[i]) {
			rem.erase(i);
			vi lolh={i};
			for(int j=0; j<sz(lolh); j++) {
				int ii=lolh[j];
				vi remo;
				for(int k:rem)
					if(forb[ii].find(k)==forb[ii].end())
						remo.pb(k);
				for(int k:remo) {
					vis[k]=1;
					rem.erase(k);
					lolh.pb(k);
					merge(i,k);
				}
			}
		}
	}
	int totc=0,poc=0;
	fr(i,2,n)
		if(forb[1].find(i)==forb[1].end()) {
			totc++;
			poc+=merge(1,i);
		}
	if(totc>=k&&poc<=k&&dsu[fpar(1)]==-n) {
		cout<<"possible"<<endl;
	} else {
		cout<<"impossible"<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}