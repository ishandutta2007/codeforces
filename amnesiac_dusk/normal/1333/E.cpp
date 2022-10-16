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

int grid[505][505]= {{},{0,4,3,6,12},
	{0,7 ,5 ,9 ,15},
	{0,14, 1 ,11 ,10},
	{0,13 ,8, 16 ,2}};
bool vis[10];
pii pos[10];
int queen() {
	pii at=pos[1];
	int ans=0;
	int troll=1;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	while(troll<9) {
		fr(i,1,9) {
			pii pol={abs(at.fi-pos[i].fi),abs(at.se-pos[i].se)};
			if(pol.fi>pol.se)
				swap(pol.fi,pol.se);
			if(vis[i]==0&&(!(pol.fi==1&&pol.se==2))) {
				at=pos[i];
				vis[i]=1;
				break;
			}
			if(i==9) {
				ans++;
				fr(i,1,9)
					if(vis[i]==0) {
						at=pos[i];
						break;
					}
			}
		}
		troll++;
	}
	return ans;
}
int rook() {
	pii at=pos[1];
	int ans=0;
	int troll=1;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	while(troll<9) {
		fr(i,1,9) {
			pii pol={abs(at.fi-pos[i].fi),abs(at.se-pos[i].se)};
			if(pol.fi<pol.se)
				swap(pol.fi,pol.se);
			if(vis[i]==0&&pol.se==0) {
				at=pos[i];
				vis[i]=1;
				break;
			}
			if(i==9) {
				ans++;
				fr(i,1,9)
					if(vis[i]==0) {
						at=pos[i];
						break;
					}
			}
		}
		troll++;
	}
	return ans;
}
void solve() {
//	vector<pii> lol;
//	fr(i,1,3)
//		fr(j,1,3)
//			lol.pb({i,j});
//	fr(i,1,9) {
//		pos[i]=lol.back();
//		lol.pop_back();
//	}
//	sort(pos+1,pos+10);
//	do {
//		trace(rook(),queen());
//		if(rook()<queen()) {
//			fr(i,1,9) {
//				trace(pos[i]);
//			}
//			break;
//		}
//	} while(next_permutation(pos+1,pos+10));
//	return;
	int n;
	cin>>n;
	if(n==3) {
		cout<<"1 2 5\n3 4 8\n9 6 7"<<endl;
		return;
	} else
	if(n<4) {
		cout<<-1<<endl;
	} else {
		vi a;
		fr(i,1,n*n-16)
			a.pb(i);
		fr(i,1,4)
			fr(j,1,4)
				grid[i][j]+=n*n-16;
		for(int j=5; j<=n; j++) {
			grid[3][j]=a.back();
			a.pop_back();
		}
		for(int i=1; i<=4; i++) {
			if(i!=3) {
				fr(j,5,n) {
					grid[i][j]=a.back();
					a.pop_back();
				}
			}
		}
		fr(i,5,n)
			for(int j=n; j>0; j--) {
				grid[i][j]=a.back();
				a.pop_back();
			}
		fr(i,1,n) {
			fr(j,1,n) {
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
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