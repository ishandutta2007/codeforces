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



int a[300005];
int smi[18][600005];
int sma[18][600005];
int n;
void build(int level) {
	for(int i=3*n-1; i>0; i--) {
		smi[level][i]=min(smi[level][i<<1],smi[level][i<<1|1]);
		sma[level][i]=max(sma[level][i<<1],sma[level][i<<1|1]);
	}
}
pii query(int level, int l, int r) {
	l--;
	pii ans={3*n,1};
	for(l+=3*n,r+=3*n; l<r; l>>=1,r>>=1) {
		if(l&1) {
			ans.fi=min(ans.fi,smi[level][l]);
			ans.se=max(ans.se,sma[level][l]);
			l++;
		}
		if(r&1) {
			r--;
			ans.fi=min(ans.fi,smi[level][r]);
			ans.se=max(ans.se,sma[level][r]);
		}
	}
	return ans;
}
void solve() {
	cin>>n;
	if(n==1) {
		cout<<0<<endl;
		return;
	}
	fr(i,1,n) {
		cin>>a[i];
		a[n+i]=a[i];
		a[2*n+i]=a[i];
	}
	fr(i,1,3*n) {
		smi[0][3*n+i-1]=max(1LL,i-a[i]);
		sma[0][3*n+i-1]=min(3*n,i+a[i]);
	}
	build(0);
	rep(j,1,18) {
		fr(i,1,3*n) {
			pii te=query(j-1,i,i);
			te=query(j-1,te.fi,te.se);
			smi[j][3*n+i-1]=te.fi;
			sma[j][3*n+i-1]=te.se;
		}
		build(j);
	}
	fr(i,n+1,2*n) {
		int ans=0;
		pii lol={i,i};
		for(int j=17; j>=0; j--) {
			pii lol2=query(j,lol.fi,lol.se);
			if(lol2.se-lol2.fi<n-1) {
				ans|=(1<<j);
				lol=lol2;
			}
		}
		cout<<ans+1<<" ";
	}




}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}