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

const int N=1e5+5;
vector<pii> tr[4*N];
int mi[4*N];
int countandremove(int seg, int ll, int rr, int l, int r, int height) {
	if(ll>r||l>rr||mi[seg]>height)
		return 0;
	int res=0;
	if(ll==rr) {
		while(tr[seg].size()&&tr[seg].back().fi<=height) {
			res+=tr[seg].back().se;
			tr[seg].pop_back();
		}
		if(tr[seg].empty())
			mi[seg]=infl;
		else
			mi[seg]=tr[seg].back().fi;
	} else {
		res+=countandremove(seg<<1,ll,(ll+rr)/2,l,r,height)+countandremove(seg<<1|1,(ll+rr)/2+1,rr,l,r,height);
		mi[seg]=min(mi[seg<<1],mi[seg<<1|1]);
	}
	res%=mod;
	return res;
}
void add(int seg, int ll, int rr, int p, int height, int val) {
	if(ll>p||rr<p)
		return;
	if(ll==rr) {
		tr[seg].pb({height,val});
		mi[seg]=tr[seg].back().fi;
		return;
	}
	add(seg<<1,ll,(ll+rr)/2,p,height,val);
	add(seg<<1|1,(ll+rr)/2+1,rr,p,height,val);
	mi[seg]=min(mi[seg<<1],mi[seg<<1|1]);
}

void solve() {
	int h,w,n;
	cin>>h>>w>>n;
	fr(i,1,w)
		add(1,1,w,i,h+1,1);
	vector<vi> lol;
	fr(i,1,n) {
		int u,l,r,s;
		cin>>u>>l>>r>>s;
		lol.pb({u,l,r,s});
	}
	sort(all(lol));
	reverse(all(lol));
	for(auto &i:lol) {
		int pol=i[3]+i[0];
		int go=countandremove(1,1,w,i[1],i[2],pol);
		if(i[1]==1)
			i[1]=i[2]+2;
		else if(i[2]==w)
			i[2]=i[1]-2;
		add(1,1,w,i[1]-1,i[0],go);
		add(1,1,w,i[2]+1,i[0],go);
	}
	cout<<countandremove(1,1,w,1,w,h+2)<<endl;
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