/*
 * 	If you gave me a chance
 * 		I'll take it
 * 			It's a shot in the dark
 * 				But I will make it:D
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#ifndef rd
#define endl '\n'
//#endif
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
//#define int long long
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
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int arr[2][405][405][8];
int t[35];
bool lolol[300];
int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
void solve() {
	int n;
	cin>>n;
	arr[0][200][200][6]=1;
	fr(i,1,n) {
		cin>>t[i];
		t[i]+=t[i-1];
		lolol[t[i]]=1;
	}
	for(int i=1; i<t[n]; i++) {
		if(lolol[i]) {
			fr(x,1,400)
				fr(y,1,400) {
					fr(j,0,7) {
						if(arr[0][x][y][j]==i) {
							arr[1][x+dir[(j+7)&7][0]][y+dir[(j+7)&7][1]][(j+7)&7]=i+1;
							arr[1][x+dir[(j+1)&7][0]][y+dir[(j+1)&7][1]][(j+1)&7]=i+1;
						}
					}
			}
		} else {
			fr(x,1,400)
				fr(y,1,400) {
					fr(j,0,7) {
						if(arr[0][x][y][j]==i) {
							arr[1][x+dir[j][0]][y+dir[j][1]][j]=i+1;
						}
					}
			}
		}
		fr(i,1,400)
			fr(j,1,400)
				fr(k,0,7)
					arr[0][i][j][k]=max(arr[0][i][j][k],arr[1][i][j][k]);
	}
	int ans=0;
	fr(i,1,400) {
		fr(j,1,400) {
			int sum=0;
				fr(k,0,7) {
					sum+=arr[0][i][j][k];
				}
			if(sum)
				ans++;
		}
	}
	cout<<ans<<endl;
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