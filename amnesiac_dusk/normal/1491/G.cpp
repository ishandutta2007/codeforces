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

//bool fib[200005];
//int sz[200005];
//bool dis[200005];
int c[200005];
int pos[200005];
bool vis[200005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>c[i];
	set<int> non;
	int mediator=0;
	fr(i,1,n)
		if(c[i]!=i) {
			non.insert(i);
		} else
			mediator=i;
	fr(i,1,n)
		pos[c[i]]=i;
	vector<pii> ans;
	int cntr=0;
	vector<vi> cycles;
	fr(i,1,n) {
		if(vis[i])
			continue;
		cycles.pb({i});
		int te=i;;
		while(c[te]!=i) {
			cycles.back().pb(c[te]);
			te=c[te];
			vis[te]=1;
		}
	}
	if(sz(cycles)%2==1&&sz(cycles)!=1)
		cycles.pb({cycles[0][0]});
	for(int i=0; i<sz(cycles); i+=2) {
		int ulti,plti;
		if(i==sz(cycles)-1) {
//			trace(1);
			int p1=cycles[i][0],p2=pos[cycles[i][0]];
			swap(pos[p1],pos[c[p1]]);
			swap(c[p1],c[p2]);
			ans.pb({p1,p2});
			ulti=p1;
			plti=p2;
			for(int j=0; j<sz(cycles[i]); j++) {
				if(cycles[i][j]!=p2&&cycles[i][j]!=p1) {
					int p3=cycles[i][j];
					swap(pos[c[p1]],pos[c[p3]]);
					swap(c[p1],c[p3]);
					ans.pb({p1,p3});
					break;
				}
			}
//			trace(ulti,plti);
		} else {
			ulti=cycles[i][0],plti=cycles[i+1][0];
			ans.pb({ulti,plti});
			swap(pos[c[ulti]],pos[c[plti]]);
			swap(c[ulti],c[plti]);
		}
//		trace(ulti,plti);
//		fr(i,1,n) {
//			cout<<c[i]<<" \n"[i==n];
//		}
//		fr(i,1,n) {
//			cout<<pos[i]<<" \n"[i==n];
//		}
//		cout<<endl;
//		exit(0);
		int cntr=0;
		while(c[ulti]!=plti||c[plti]!=ulti) {
//			fr(i,1,n) {
//				cout<<c[i]<<" \n"[i==n];
//			}
//			fr(i,1,n) {
//				cout<<pos[i]<<" \n"[i==n];
//			}
//			cout<<endl;
//			cntr++;
//			if(cntr>10)
//				exit(0);
			if(c[ulti]!=plti) {
			} else
				swap(ulti,plti);
//			trace(ulti,plti);
//			cout<<endl;
			int nep=c[ulti];
			swap(pos[c[nep]],pos[c[ulti]]);
			swap(c[ulti],c[nep]);
			ans.pb({ulti,nep});
			if(mediator==0) {
				mediator=nep;
			}
		}
		ans.pb({ulti,plti});
		swap(c[ulti],c[plti]);
		swap(pos[ulti],pos[plti]);
	}
	cout<<sz(ans)<<endl;
	for(auto i : ans) {
		cout<<i.fi<<" "<<i.se<<endl;
	}
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