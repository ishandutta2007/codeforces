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

char a[105][105];
char ans[105][105];
int alloc[63];
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	int rice=0;
	fr(i,1,n)
		fr(j,1,m) {
			cin>>a[i][j];
			if(a[i][j]=='R')
				rice++;
		}
	string lol="";
	for(char i='A'; i<='Z'; i++)
		lol+=i;
	for(char i='a'; i<='z'; i++)
		lol+=i;
	for(char i='0'; i<='9'; i++)
		lol+=i;
	lol=lol.substr(0, k);
	lol+=lol.back();
	int cntr=0;
	memset(alloc,0,sizeof(alloc));
	rep(i,0,k)
		alloc[i]=rice/k;
	rep(i,0,rice%k)
		alloc[i]++;
	alloc[k]=1000;
	int troll=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(alloc[cntr]==troll) {
				cntr++;
				troll=0;
			}
			ans[i][j]=lol[cntr];
			if(a[i][j]=='R')
				troll++;
		}
		if(i==n)
			break;
		i++;
		for(int j=m; j>0; j--) {
			if(alloc[cntr]==troll) {
				cntr++;
				troll=0;
			}
			ans[i][j]=lol[cntr];
			if(a[i][j]=='R')
				troll++;
		}
	}
	fr(i,1,n) {
		fr(j,1,m)
			cout<<ans[i][j];
		cout<<endl;
	}
//	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(7);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}