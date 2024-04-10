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

int a[105][105];
void solve() {
	int n,m;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	fr(i,1,n) {
		fr(j,1,m) {
			char te;
			cin>>te;
			a[i][j]=te-'0';
		}
	}
	vector<vector<pii>> anser;
	for(int i=1; i+2<=n; i++) {
		for(int j=1; j<=m; j+=2) {
			if(j==m)
				j=m-1;
			vector<pii> ones,zeros;
			rep(k,0,2) {
				if(a[i][j+k]==0)
					zeros.pb({i,j+k});
				else
					ones.pb({i,j+k});
			}
			if(sz(ones)==0)
				continue;
			else if(sz(ones)==1) {
				anser.pb(ones);
				anser.back().pb({i+1,j});
				anser.back().pb({i+1,j+1});
			} else if(sz(ones)==2) {
				anser.pb(ones);
				anser.back().pb({i+1,j});
			}
			for(auto i:anser.back())
				a[i.fi][i.se]^=1;
		}
//		fr(i,1,n) {
//			fr(j,1,m+1) {
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl<<endl;
	}
	for(int i=n-1; i<=n; i+=2) {
		for(int j=1; j<=m; j+=2) {
			vector<pii> ones,zeros;
			rep(k,0,2)
				rep(l,0,2) {
					if(a[i+k][j+l])
						ones.pb({i+k,j+l});
					else
						zeros.pb({i+k,j+l});
				}
			if(sz(ones)==0)
				continue;
			else if(sz(ones)==3) {
				anser.pb(ones);
			} else if(sz(ones)==2) {
				anser.pb(zeros);
				anser.back().pb(ones[0]);
				anser.pb(zeros);
				anser.back().pb(ones[1]);
			} else if(sz(ones)==1) {
				anser.pb(zeros);
				anser.back()[0]=ones[0];
				anser.pb(zeros);
				anser.back()[1]=ones[0];
				anser.pb(zeros);
				anser.back()[2]=ones[0];
			} else {
				pii last=ones.back();
				ones.pop_back();
				rep(i,0,4) {
					anser.pb(ones);
					if(i!=3)
						anser.back()[i]=last;
				}
			}
			if(zeros.size()==0)
				zeros.resize(4);
			fr(k,1,sz(zeros)) {
				for(auto pp:anser[sz(anser)-k])
					a[pp.fi][pp.se]^=1;
			}
		}
//		fr(i,1,n) {
//			fr(j,1,m+1) {
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl<<endl;
	}
//	fr(i,1,n) {
//		fr(j,1,m+1) {
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//	assert(sz(anser)<=n*m);
	cout<<sz(anser)<<endl;
	for(auto i:anser) {
		rep(j,0,3) {
			if(i[j].fi>n)
				i[j].fi-=2;
			if(i[j].se>m)
				i[j].se-=2;
			cout<<i[j].fi<<" "<<i[j].se<<" ";
		}
		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}