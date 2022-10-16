#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
//#define endl '\n'
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


int a[100005],fs[100005],co[100005];
int ct[100005];
void solve() {
	for(int i=2; i<=100000; i++)
		if(fs[i]==0)
			for(int j=i; j<=100000; j+=i)
				fs[j]=i;
	int n,k;
	cin>>n>>k;
	fr(i,1,n) {
		cin>>a[i];
		map<int,int> fa;
		while(a[i]!=1) {
			fa[fs[a[i]]]++;
			a[i]/=fs[a[i]];
		}
		co[i]=1;
		for(auto fo:fa) {
			fo.se%=k;
			if(fo.se==0)
				continue;
			rep(j,0,fo.se)
				a[i]*=fo.fi;
			rep(j,fo.se,k) {
				co[i]*=fo.fi;
				if(co[i]>=1e5+1)
					co[i]=1e5+1;
			}
		}
	}
	int ans=0;
	fr(i,1,n) {
		ans+=ct[co[i]];
		ct[a[i]]++;
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}