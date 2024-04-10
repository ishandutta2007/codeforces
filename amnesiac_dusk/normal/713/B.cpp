#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


pii x,y;
bool found;
int query(int x1,int x2, int y1, int y2) {
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int te;
	cin>>te;
	if(found&&x1<=x.fi&&x2>=x.se&&y1<=y.fi&&y2>=y.se)
		te--;
	return te;
}
void solve() {
	int n;
	cin>>n;
	int lo=1,hi=n,mid=(lo+hi)/2;
	while(lo<hi) {
		if(query(1,mid,1,n)) {
			hi=mid;
		} else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	int x2=mid;
	lo=1,hi=x2,mid=(lo+hi+1)/2;
	while(lo<hi) {
		if(query(mid,x2,1,n)) {
			lo=mid;
		} else
			hi=mid-1;
		mid=(lo+hi+1)/2;
	}
	int x1=mid;
	lo=1,hi=n,mid=(lo+hi)/2;
	while(lo<hi) {
		if(query(x1,x2,1,mid)) {
			hi=mid;
		} else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	int y2=mid;
	lo=1,hi=y2,mid=(lo+hi+1)/2;
	while(lo<hi) {
		if(query(x1,x2,mid,y2)) {
			lo=mid;
		} else
			hi=mid-1;
		mid=(lo+hi+1)/2;
	}
	int y1=mid;
	found=1;
	x={x1,x2};
	y={y1,y2};
	{
		int lo=1,hi=n,mid=(lo+hi)/2;
		while(lo<hi) {
			if(query(1,mid,1,n)) {
				hi=mid;
			} else
				lo=mid+1;
			mid=(lo+hi)/2;
		}
		int x2=mid;
		lo=1,hi=x2,mid=(lo+hi+1)/2;
		while(lo<hi) {
			if(query(mid,x2,1,n)) {
				lo=mid;
			} else
				hi=mid-1;
			mid=(lo+hi+1)/2;
		}
		int x1=mid;
		lo=1,hi=n,mid=(lo+hi)/2;
		while(lo<hi) {
			if(query(x1,x2,1,mid)) {
				hi=mid;
			} else
				lo=mid+1;
			mid=(lo+hi)/2;
		}
		int y2=mid;
		lo=1,hi=y2,mid=(lo+hi+1)/2;
		while(lo<hi) {
			if(query(x1,x2,mid,y2)) {
				lo=mid;
			} else
				hi=mid-1;
			mid=(lo+hi+1)/2;
		}
		int y1=mid;
		cout<<"! "<<x.fi<<" "<<y.fi<<" "<<x.se<<" "<<y.se;
		cout<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	}




}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}