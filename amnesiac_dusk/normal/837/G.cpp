//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int sfx[251][200005];
struct func
{
	int x1,x2,y1,a,b,y2;
	int compute(int x){
		if(x<=x1)
			return y1;
		if(x<=x2)
			return a*x+b;
		return y2;
	}
};
func fs[75005];
int blk[75005];
const int bls=300;
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		blk[i]=(i+bls-1)/bls;
		cin>>fs[i].x1>>fs[i].x2>>fs[i].y1>>fs[i].a>>fs[i].b>>fs[i].y2;
		sfx[blk[i]][fs[i].x1+1]+=fs[i].a;
		sfx[blk[i]][fs[i].x2+1]-=fs[i].a;
	}
	for(int i=blk[1]; i<=blk[n]; i++) {
		for(int j=1; j<=200002; j++)
			sfx[i][j]+=sfx[i][j-1];
	}
	fr(i,1,n) {
		sfx[blk[i]][0]+=fs[i].y1;
		sfx[blk[i]][fs[i].x1+1]-=fs[i].y1;
		sfx[blk[i]][fs[i].x1+1]+=fs[i].x1*fs[i].a;
		sfx[blk[i]][fs[i].x2+1]-=fs[i].x2*fs[i].a;
		sfx[blk[i]][fs[i].x1+1]+=fs[i].b;
		sfx[blk[i]][fs[i].x2+1]-=fs[i].b;
		sfx[blk[i]][fs[i].x2+1]+=fs[i].y2;
	}
	for(int i=blk[1]; i<=blk[n]; i++) {
		for(int j=1; j<=200002; j++)
			sfx[i][j]+=sfx[i][j-1];
	}
	int l,r,m;
	cin>>m;
	int last=0;
	while(m--) {
		int x;
		cin>>l>>r>>x;
		x=(last+x)%1000000000;
		x=min(x,200002LL);
		int ans=0;
		if(blk[l]==blk[r]) {
			for(int j=l; j<=r; j++)
				ans+=fs[j].compute(x);
		} else {
			for(int j=l; blk[j]==blk[l]; j++) {
				ans+=fs[j].compute(x);
			}
			for(int j=r; blk[j]==blk[r]; j--) {
				ans+=fs[j].compute(x);
			}
			for(int j=blk[l]+1; j<blk[r]; j++) {
				ans+=sfx[j][x];
			}
		}
		last=ans;
		cout<<ans<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}