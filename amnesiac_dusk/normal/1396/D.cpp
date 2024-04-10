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

int x[2005],y[2005],c[2005];
multiset<int> occur[2005];
vector<int> occur2[2005];
void solve() {
	int n,k,l;
	cin>>n>>k>>l;
	vi compx,compy;
	compx.pb(-1);
	compx.pb(l);
	compy.pb(-1);
	compy.pb(l);
	fr(i,1,n) {
		cin>>x[i]>>y[i]>>c[i];
		compx.pb(x[i]);
		compy.pb(y[i]);
		c[i]--;
	}
	sort(all(compx));
	compx.resize(unique(all(compx))-compx.begin());
	sort(all(compy));
	compy.resize(unique(all(compy))-compy.begin());
	vector<vi> coox(sz(compx));
	fr(i,1,n)
		coox[lower_bound(all(compx),x[i])-compx.begin()].pb(i);
	int ans=0;
	map<int,int> y_index;
	rep(i,0,sz(compy))
		y_index[compy[i]]=i;
	trace(sz(compx));
	for(int i=1; i+1<sz(compx); i++) {
		trace(i);
//		cout<<1<<endl;
		rep(i,0,k)
			occur[i].clear();
		rep(i,0,sz(compy))
			occur2[i].clear();
		trace(1);
		rep(i,0,k) {
			occur[i].insert(-1);
			occur[i].insert(l);
		}
		for(int j=i; j<sz(compx); j++)
			for(auto k:coox[j]) {
				occur[c[k]].insert(y[k]);
				occur2[y_index[y[k]]].pb(c[k]);
			}
		vi mini(sz(compy)),last(k,l);
		multiset<int> lo;
		for(int i:last)
			lo.insert(i);
		int temp=0;
		trace(1);
		for(int j=sz(compy)-1; j>0; j--) {
			for(int lol:occur2[j]) {
				lo.erase(lo.find(last[lol]));
				trace(lol,last[lol],compy[j]);
				last[lol]=compy[j];
				lo.insert(last[lol]);
			}
			mini[j]=*lo.rbegin();
			temp=(temp+(l-mini[j])*(compy[j]-compy[j-1]))%mod;
			trace(temp,j,mini[j]);
		}
		trace(temp);
		int star=compx[i]-compx[i-1];
		for(int j=sz(compx)-2; j>=i; j--) {
			trace(j);
			ans=(ans+star*(((compx[j+1]-compx[j])*temp)%mod))%mod;
			for(int i:coox[j]) {
				occur[c[i]].erase(occur[c[i]].find(y[i]));
				auto it=occur[c[i]].lower_bound(y[i]);
				int after=y_index[*it];
				int val=(*it);
				it--;
				int before=y_index[*it]+1;
				trace(c[i],before,after,val,before);
				for(int j=before; j<after; j++) {
					if(mini[j]>=val)
						break;
					trace(l,mini[j],val,temp);
					temp=(temp-(l-mini[j])*(compy[j]-compy[j-1]))%mod;
					mini[j]=val;
					temp=(temp+(l-mini[j])*(compy[j]-compy[j-1]))%mod;
					trace(temp);
				}
				trace(temp);
			}
			trace(i,j,compx[i],compx[j],ans);
		}
//		cout<<__LINE__<<endl;
	}
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}