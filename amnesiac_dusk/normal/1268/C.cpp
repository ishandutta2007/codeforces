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



int a[300005],anti[300005],icost[300005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		anti[a[i]]=i;
	}
	oset b;
	for(int i=n; i>0; i--) {
		icost[a[i]]=b.order_of_key(a[i]);
		b.insert(a[i]);
	}
	b.clear();
	int l=anti[1],r=anti[1];
	cout<<0<<" ";
	b.insert(anti[1]);
	int cost=0;
	fr(i,2,n) {
		if(l<=anti[i]&&anti[i]<=r) {
			int te=b.order_of_key(anti[i]);
			cost-=min(te,sz(b)-te);
			if(sz(b)&1) {
				int med=*b.find_by_order(sz(b)/2);
				if(anti[i]<=med) {
					cost+=(med-anti[i]-sz(b)/2+te-1);
				} else if(anti[i]>=med) {
					cost+=(anti[i]-med+(sz(b))/2-te);
				}
			} else {
				int med1=*b.find_by_order(sz(b)/2);
				int med2=*b.find_by_order((sz(b)-1)/2);
				if(anti[i]<=med2) {
					cost+=(med2-anti[i]-sz(b)/2+te);
				} else if(anti[i]>=med1) {
					cost+=(anti[i]-med1+(sz(b)/2)-te);
				}
			}
		} else if(l>anti[i]) {
			cost+=(l-anti[i]-1);
			int medi=*b.find_by_order((sz(b)-1)/2);
			cost+=(medi-(sz(b)-1)/2-l);
			l=anti[i];
		} else if(r<anti[i]) {
			cost+=(anti[i]-r-1);
			int medi=*b.find_by_order((sz(b))/2);
			cost+=(r-medi-(sz(b)-1)/2);
			r=anti[i];
		} else
			assert(0);
		b.insert(anti[i]);
		cost+=icost[i];
		cout<<cost<<" ";
	}
	cout<<endl;
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