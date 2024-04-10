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

int sb(int num) {
	if(num==0)
		return 0;
	return 64-__builtin_clzll(num);
}
int a[200005];
int recur(vector<vi> a, int mbit) {
	if(mbit==0)
		return !a[0].empty();
	int ans=0;
	int pp=0;
	for(int i=0; i<=mbit; i++) {
		if(a[i].size()) {
			int tean=pp;
			if(i) {
				vector<vi> ne(i+1);
				for(int j:a[i])
					ne[sb(j^(1<<(i-1)))].pb(j^(1<<(i-1)));
				tean+=recur(ne,i-1);
			} else
				tean+=!a[0].empty();
			for(int j=i+1; j<=mbit; j++)
				if(a[j].size())
					tean++;
			ans=max(ans,tean);
			pp=1;
		}
	}
	return ans;
}

void solve() {
	int n;
	cin>>n;
	vi a;
	vector<vi> poo(31);
	fr(i,1,n) {
		int te;
		cin>>te;
		a.pb(te);
		poo[sb(te)].pb(te);
	}
//	for(int i=0; i<(1<<n); i++) {
//		vi seq;
//		for(int j=0; j<n; j++) {
//			if((i>>j)&1)
//				seq.pb(j);
//		}
//		if(sz(seq)==5) {
////			trace(seq);
//			vector<vi> gra(7);
//			for(int k=0; k<sz(seq); k++) {
//				int mini=(k+1)%sz(seq);
//				for(int l=0; l<sz(seq); l++) {
//					if(l!=k&&(a[seq[mini]]^a[seq[k]])>(a[seq[k]]^a[seq[l]])) {
////						gra.pb({seq[k],seq[l]});
//						mini=l;
//					}
//				}
//				gra[seq[k]].pb(seq[mini]);
//				gra[seq[mini]].pb(seq[k]);
//			}
////			trace(gra);
//			vector<int> visited(7,0);
//			queue<int> qu;
//			qu.push(seq[0]);
//			visited[seq[0]]=1;
//			while(sz(qu)) {
//				int at=qu.front();
//				qu.pop();
//				for(int j:gra[at]) {
//					if(visited[j]==0) {
//						qu.push(j);
//						visited[j]=1;
//					}
//				}
//			}
//			if(accumulate(all(visited),0LL)==5) {
//				trace(seq,gra);
//				exit(0);
//			}
//		}
//	}
	int ans=n-recur(poo,30);
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}