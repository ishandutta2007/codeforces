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

vi dp[1<<14][14];
bool coon[14][14];
int fans[1<<14];
void solve() {
	int n;
	cin>>n;
	rep(i,0,n) {
		string hol;
		cin>>hol;
		rep(j,0,n)
			coon[i][j]=hol[j]-'0';
	}
	rep(i,1,(1<<n))
		rep(j,0,n)
			if(i&(1<<j))
				dp[i][j].resize(1<<(__builtin_popcount(i)-1),0);
	rep(i,0,n)
		dp[1<<i][i][0]=1;
	for(int i=1; i+1<(1<<n); i++) {
		for(int j=0; j<n; j++) {
			if(i&(1<<j)) {
				int lel=1<<(__builtin_popcount(i)-1);
				for(int k=0; k<n; k++) {
					if(!(i&(1<<k))) {
						if(coon[j][k]) {
							for(int l=0; l<lel; l++)
								dp[i^(1<<k)][k][l<<1|1]+=dp[i][j][l];
						} else {
							for(int l=0; l<lel; l++)
								dp[i^(1<<k)][k][l<<1]+=dp[i][j][l];
						}
					}
				}
			}
		}
	}
	rep(j,0,n)
		rep(i,0,(1<<(n-1)))
			fans[i]+=dp[(1<<n)-1][j][i];
	rep(i,0,(1<<(n-1)))
		cout<<fans[i]<<" ";
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}