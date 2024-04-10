#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
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
// const int mod=998244353;
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



int a[500005];
int an1[500005],an2[500005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	stack<pii> lol;
	int con1=0;
	fr(i,1,n) {
		int cur=0;
		while(!lol.empty()&&lol.top().fi>a[i]) {
			cur+=lol.top().se;
			con1-=lol.top().fi*lol.top().se;
			lol.pop();
		}
		lol.push({a[i],cur+1});
		con1+=a[i]*(cur+1);
		an1[i]=con1;
	}
	while(lol.size())
		lol.pop();
	con1=0;
	for(int i=n; i>0; i--) {
		int cur=0;
		while(!lol.empty()&&lol.top().fi>a[i]) {
			cur+=lol.top().se;
			con1-=lol.top().fi*lol.top().se;
			lol.pop();
		}
		lol.push({a[i],cur+1});
		con1+=a[i]*(cur+1);
		an2[i]=con1-a[i];
	}
	int maxa=0;
	fr(i,1,n)
		if(an1[i]+an2[i]>an1[maxa]+an2[maxa])
			maxa=i;
	int mol=a[maxa];
	for(int i=maxa; i>0; i--) {
		mol=min(a[i],mol);
		an1[i]=mol;
	}
	mol=a[maxa];
	fr(i,maxa,n) {
		mol=min(a[i],mol);
		an1[i]=mol;
	}
	fr(i,1,n) {
		cout<<an1[i]<<" ";
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}