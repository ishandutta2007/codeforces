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

int a[3][100005];
int n[3];
void solve() {
	trace(infl);
	rep(i,0,3)
		cin>>n[i];
	rep(i,0,3) {
		fr(j,1,n[i])
			cin>>a[i][j];
		sort(a[i]+1,a[i]+n[i]+1);
	}
	int ans=infl;
	vi pol(3);
	rep(i,0,3) {
		fr(j,1,n[i]) {
			vector<vi> ind(3);
			ind[i].pb(j);
			ind[i].pb(j+1);
			rep(k,0,3) {
				if(i!=k) {
					auto it1=lower_bound(a[k]+1,a[k]+n[k]+1,a[i][j])-a[k];
					ind[k].pb(it1);
					ind[k].pb(it1-1);
				}
			}
			rep(k,0,8) {
				int temp=0;
				rep(l,0,3) {
					if(ind[l][(k>>l)&1]>n[l]||ind[l][(k>>l)&1]<1) {
						temp=infl;
						break;
					} else
						pol[l]=(a[l][ind[l][(k>>l)&1]]);
				}
				if(temp!=infl) {
					rep(i,0,3) {
						rep(j,i+1,3) {
							temp+=(pol[i]-pol[j])*(pol[i]-pol[j]);
						}
					}
					ans=min(ans,temp);
				}
			}
		}
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}