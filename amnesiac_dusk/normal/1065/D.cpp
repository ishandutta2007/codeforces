/*
 * 	If you gave me a chance
 * 		I'll take it
 * 			It's a shot in the dark
 * 				But I will make it:D
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

//int n;s
int dist[500][300];
int dp[300][3];
inline int num(int i, int j, int ty) {
	return 30*i+3*j+ty;
}
int a[10][10];
pii anti[100];
void solve() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
			anti[a[i][j]]={i,j};
		}
	}
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			for(int k=0; k<3; k++)
				dp[i*n+j][k]=infl;
	for(int i=0; i<=(num(n-1,n-1,2)); i++)
		for(int j=0; j<=num(n-1,n-1,2); j++) {
			dist[i][j]=infl;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
					if(k!=l)
						dist[num(i,j,k)][num(i,j,l)]=infi+1;
					else
						dist[num(i,j,k)][num(i,j,l)]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			for(int k=0;i+k<n&&j+k<n;k++) {
				dist[num(i,j,0)][num(i+k,j+k,0)]=infi;
				dist[num(i+k,j+k,0)][num(i,j,0)]=infi;
			}
			for(int k=0;i-k>=0&&j+k<n;k++) {
				dist[num(i,j,0)][num(i-k,j+k,0)]=infi;
				dist[num(i-k,j+k,0)][num(i,j,0)]=infi;
			}
			for(int k=0;i+k<n&&j-k>=0;k++) {
				dist[num(i,j,0)][num(i+k,j-k,0)]=infi;
				dist[num(i+k,j-k,0)][num(i,j,0)]=infi;
			}
			for(int k=0;k<n;k++) {
				dist[num(i,j,1)][num(i,k,1)]=infi;
				dist[num(j,i,1)][num(k,i,1)]=infi;
			}
			if(i+2<n&&j+1<n)
				dist[num(i,j,2)][num(i+2,j+1,2)]=infi;
			if(i-2>=0&&j+1<n)
				dist[num(i,j,2)][num(i-2,j+1,2)]=infi;
			if(i+2<n&&j-1>=0)
				dist[num(i,j,2)][num(i+2,j-1,2)]=infi;
			if(i-2>=0&&j-1>=0)
				dist[num(i,j,2)][num(i-2,j-1,2)]=infi;
			if(i+1<n&&j+2<n)
				dist[num(i,j,2)][num(i+1,j+2,2)]=infi;
			if(i-1>=0&&j+2<n)
				dist[num(i,j,2)][num(i-1,j+2,2)]=infi;
			if(i+1<n&&j-2>=0)
				dist[num(i,j,2)][num(i+1,j-2,2)]=infi;
			if(i-1>=0&&j-2>=0)
				dist[num(i,j,2)][num(i-1,j-2,2)]=infi;
		}
	for(int i=0; i<=num(n-1,n-1,2); i++) {
		for(int j=0; j<=num(n-1,n-1,2); j++) {
			for(int k=0; k<=num(n-1,n-1,2); k++) {
				dist[j][k]=min(dist[j][i]+dist[i][k],dist[j][k]);
			}
		}
	}
	dp[1][0]=0;
	dp[1][1]=0;
	dp[1][2]=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int dpnum=i*n+j+1;
			if(i==n-1&&j==n-1)
				break;
			pii curp=anti[dpnum];
			pii nextp=anti[dpnum+1];
			for(int k=0; k<3; k++) {
				for(int l=0; l<3; l++) {
					dp[dpnum+1][l]=min(dp[dpnum+1][l],dp[dpnum][k]+dist[num(curp.fi,curp.se,k)][num(nextp.fi,nextp.se,l)]);
					if(dist[num(curp.fi,curp.se,k)][num(nextp.fi,nextp.se,l)]<infi) {
						trace(dist[num(curp.fi,curp.se,k)][num(nextp.fi,nextp.se,l)]);
						trace(dpnum,curp.fi,curp.se);
						trace(nextp.fi,nextp.se);
					}
				}
			}
		}
	}
	cout<<min(min(dp[n*n][0],dp[n*n][1]),dp[n*n][2])/infi<<" "<<min(min(dp[n*n][0],dp[n*n][1]),dp[n*n][2])%infi;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}