#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
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

int a[5005],pa[5005];
bool prime[5005];
int cnt[5005];
int maxi[1000005];
void solve() {
	memset(prime,1,sizeof(prime));
	vi ps;
	for(int i=2; i<=5000; i++)
		if(prime[i]) {
			ps.pb(i);
			for(int j=i*i; j<=5000; j+=i)
				prime[j]=0;
		}
	int n;
	cin>>n;
	fr(i,1,n) {
		int te=5000;
		cin>>te;
		a[te]++;
	}
	fr(i,1,5000)
		pa[i]+=pa[i-1];
	int ans=0;
	int l=1,r=5000;
	reverse(all(ps));
	fr(i,2,5000) {
		int lol=5000;
		while(lol>0) {
			lol/=i;
			maxi[i]+=lol;
		}
	}
	fr(i,1,5000) {
		for(int j:ps) {
			int lol=i;
			while(lol>0) {
				lol/=j;
				ans+=lol*a[i];
			}
		}
	}
	trace(ans);
	for(int j:ps) {
		memset(cnt,0,sizeof(int)*(maxi[j]+5));
		fr(i,l,r) {
			int lol=i;
			int temp=0;
			while(lol>0) {
				lol/=j;
				temp+=lol;
			}
			cnt[temp]+=a[i];
		}
		for(int i=maxi[j]; i>=0; i--)
			cnt[i]+=cnt[i+1];
		int howmany=0;
		fr(i,1,maxi[j]) {
			if(2*cnt[i]<n) {
				trace(2*cnt[i],i,n);
				break;
			}
			ans-=(2*cnt[i]-n);
			howmany=i;
		}
		trace(howmany,cnt[maxi[j]],n,maxi[j]);
		int lo=l,hi=r,mid=(1+lo+hi)/2;
		while(lo<hi) {
			int cont=0,tol=mid;
			while(tol>0) {
				tol/=j;
				cont+=tol;
			}
			if(cont>howmany)
				hi=mid-1;
			else
				lo=mid;
			mid=(lo+hi+1)/2;
		}
		r=mid;
		lo=l,hi=r,mid=(lo+hi)/2;
		while(lo<hi) {
			int cont=0,tol=mid;
			while(tol>0) {
				tol/=j;
				cont+=tol;
			}
			if(cont<howmany)
				lo=mid+1;
			else
				hi=mid;
			mid=(lo+hi)/2;
		}
		l=mid;
	}
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}