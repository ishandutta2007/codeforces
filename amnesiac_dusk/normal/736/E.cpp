#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=1e9;
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
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a[3005];
char an[3005][3005];
void solve() {
	int n,m;
	cin>>m>>n;
	for(int i=m; i>m-n; i--) {
		cin>>a[i];
	}
	int sum=0,msum=0;;
	for(int i=m; i>0; i--) {
		sum+=a[i];
		msum+=2*(i-1);
		if(sum>msum) {
			cout<<"no"<<endl;
			return;
		}
	}
	int leftp=m*(m-1)-sum;
	int left=m-n;
//	fr(i,1,left) {
//		a[i]+=2*(i-1);
//		leftp-=2*(i-1);
//	}
	if(leftp<0) {
		trace(leftp);
		cout<<"no"<<endl;
		return;
	}
	while(leftp)
		for(int i=left; leftp>0&&i>0; i--) {
				a[i]++;
				leftp--;
		}
	if(a[left+1]<a[left]) {
		cout<<"no"<<endl;
		return;
	}
	sum=0;
	msum=0;
	fr(i,1,m) {
		sum+=a[i];
		msum+=2*(i-1);
		trace(sum,msum);
		if(msum>sum) {
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;
	fr(i,1,m) {
//		trace(i);
//		fr(i,1,m) {
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		an[i][i]='X';
		vector<pii> mota;
		for(int j=m; j>i; j--) {
			mota.pb({a[j]-j,j});
		}
		sort(all(mota));
		reverse(all(mota));
		for(int jjj=0; jjj<sz(mota); jjj++) {
			auto jj=mota[jjj];
			int j=jj.se;
			if(a[i]<sz(mota)-jjj) {
				an[i][j]='L';
				an[j][i]='W';
				a[j]-=2;
			} else {
				an[i][j]='D';
				an[j][i]='D';
				a[j]--;
				a[i]--;
			}
		}
	}
	for(int i=m; i>0; i--) {
		for(int j=m; j>0; j--)
			cout<<an[i][j];
		cout<<endl;
	}
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
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}