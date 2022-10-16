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
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
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


int a[100005];
int b[100005];
int ans[100005];
void solve() {
	int n,x,y;
	cin>>n>>x>>y;
	set<int> hoo;
	fr(i,1,n+1) {
		a[i]=0;
		ans[i]=0;
		hoo.insert(i);
	}
 	priority_queue<pii> qu;
	fr(i,1,n) {
		cin>>b[i];
		hoo.erase(b[i]);
		a[b[i]]++;
		qu.push({a[b[i]],i});
	}
	rep(j,0,x) {
		ans[qu.top().se]=b[qu.top().se];
		a[b[qu.top().se]]--;
		qu.pop();
	}
	int over=n-y;
	vector<pii> q;
	while(sz(qu)) {
		q.pb({b[qu.top().se],qu.top().se});
		qu.pop();
	}
	sort(all(q));
	trace(q);
	int mcnts=0,mval=0;
	fr(i,1,n+1)
		if(mcnts<a[i]) {
			mcnts=a[i];
			mval=i;
		}
	if(2*mcnts-over>sz(q)) {
		cout<<"NO"<<endl;
		return;
	}
	if(2*mcnts>=sz(q)) {
		if(over>mcnts) {
			rep(i,0,sz(q))
				if(q[i].fi==mval) {
					ans[q[i].se]=*hoo.begin();
					over--;
				}
			rep(i,0,sz(q)) {
				if(q[i].fi!=mval) {
					if(over>0) {
						over--;
						ans[q[i].se]=*hoo.begin();
					}
					else
						ans[q[i].se]=mval;
				}
			}
		} else {
			vi oth;
			rep(i,0,sz(q)) {
				if(q[i].fi!=mval) {
					ans[q[i].se]=mval;
					mcnts--;
					oth.pb(q[i].fi);
				}
			}
			trace(oth,over,mcnts);
			over=max(0LL,over-mcnts);
			oth.resize(sz(oth)-over);
			rep(i,0,sz(q)) {
				if(q[i].fi==mval) {
					if(sz(oth)) {
						ans[q[i].se]=oth.back();
						oth.pop_back();
					} else
						ans[q[i].se]=*hoo.begin();
				}
			}
		}
	} else {
		rep(i,0,sz(q))
			ans[q[(i+mcnts)%sz(q)].se]=q[i].fi;
		rep(i,0,over)
			ans[q[i].se]=*hoo.begin();
	}
	cout<<"YES"<<endl;
	fr(i,1,n)
		cout<<ans[i]<<" ";
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}