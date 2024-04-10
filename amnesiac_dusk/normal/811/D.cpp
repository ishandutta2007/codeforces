/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
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
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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
void precompute() {}

char grid[105][105];
bool vis[105][105];
vector<pii> path,fpath;
char ma[256];
pii move(char dir) {
	cout<<ma[dir]<<endl;
	pii at;
	cin>>at.fi>>at.se;
	if(grid[at.fi][at.se]=='F')
		exit(0);
	return at;
}
void dfs(pii at) {
	path.pb(at);
	vis[at.fi][at.se]=1;
	if(grid[at.fi][at.se]=='F') {
		fpath=path;
		return;
	}
	if(grid[at.fi][at.se+1]!='*'&&vis[at.fi][at.se+1]==0) {
		move('R');
		dfs({at.fi,at.se+1});
		move('L');
	}
	if(grid[at.fi][at.se-1]!='*'&&vis[at.fi][at.se-1]==0) {
		move('L');
		dfs({at.fi,at.se-1});
		move('R');
	}
	if(grid[at.fi+1][at.se]!='*'&&vis[at.fi+1][at.se]==0) {
		move('D');
		dfs({at.fi+1,at.se});
		move('U');
	}
	if(grid[at.fi-1][at.se]!='*'&&vis[at.fi-1][at.se]==0) {
		move('U');
		dfs({at.fi-1,at.se});
		move('D');
	}
	path.pop_back();
}

void solve() {
	int n,m;
	cin>>n>>m;
	bool lrs,uds;
	int posx=1,posy=1;
	fr(i,0,n+1)
		fr(j,0,m+1)
			grid[i][j]='*';
	fr(i,1,n)
		fr(j,1,m)
			cin>>grid[i][j];
	pii ne;
	fr(i,1,255)
		ma[i]=i;
	if(grid[2][1]!='*') {
		ne=move('D');
		if(ne.fi==1&&ne.se==1) {
			swap(ma['U'],ma['D']);
		} else
			move('U');
		for(int i=1; i<=n; i++) {
			if(grid[i][2]!='*') {
				ne=move('R');
				if(ne.se==1) {
					swap(ma['L'],ma['R']);
				} else
					move('L');
				for(int j=i; j>1; j--) {
					move('U');
				}
				break;
			} else
				move('D');
		}
	} else {
		ne=move('R');
		if(ne.fi==1&&ne.se==1) {
			swap(ma['L'],ma['R']);
		} else
			move('L');
		for(int i=1; i<=m; i++) {
			if(grid[2][i]!='*') {
				ne=move('D');
				if(ne.fi==1) {
					swap(ma['U'],ma['D']);
				} else
					move('U');
				for(int j=i; j>1; j--) {
					move('L');
				}
				break;
			} else
				move('R');
		}
	}
	dfs({1,1});
}


signed main() {
	precompute();
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();

#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}