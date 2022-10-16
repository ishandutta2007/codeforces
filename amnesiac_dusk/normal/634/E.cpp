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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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


map<pii,pii> dp;
bool active[200005];
vi gra[200005];
pii dfs(int fr, int at) {
	if(active[at]==0)
		return {0,1};
	if(dp.find({fr,at})!=dp.end())
		return dp[{fr,at}];
	int su=0,goo=0;
	int poo=1;
	for(int i:gra[at]) {
		if(i!=fr) {
			pii po=dfs(at,i);
			if(po.se==0) {
				poo+=po.fi;
			} else {
				goo=1;
				su=max(su,po.fi);
			}
		}
	}
	return dp[{fr,at}]={su+poo,goo};
}
int a[200005];
void solve() {
	int n,k;
	cin>>n>>k;
	fr(i,1,n)
		cin>>a[i];
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	int lo=*min_element(a+1, a+n+1),hi=1000000,mid=(lo+hi+1)/2;
	while(lo<hi) {
		dp.clear();
		fr(i,1,n)
			if(a[i]>=mid)
				active[i]=1;
			else
				active[i]=0;
		int poo=0;
		set<int> starter;
		fr(i,1,n)
			if(active[i]==0)
				for(int j:gra[i]) {
					if(active[j]&&starter.find(j)==starter.end()) {
						starter.insert(j);
						poo=max(poo,dfs(i,j).fi);
					}
				}
		if(poo>=k) {
			lo=mid;
		} else
			hi=mid-1;
		mid=(lo+hi+1)/2;
	}
	cout<<mid<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}