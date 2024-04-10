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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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

int a[32];
int dp[35][105][5005];
bool graph[105][105];
void solve() {
	int n;
	cin>>n;
	rep(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	rep(i,0,n) {
		fr(j,i,100) {
			fr(k,0,5000) {
				if(~dp[i][j][k])
					for(int l=1; l+j<=100&&k+l*a[i]<=5000; l++) {
						if(k+l*a[i]>=((l+j)*(l+j-1))/2) {
							dp[i+1][j+l][k+l*a[i]]=l;
						}
					}
			}
		}
	}
	int ans=0;
	fr(i,n,100)
		if(~dp[n][i][(i*(i-1))/2]) {
			ans=i;
			break;
		}
	if(ans==0) {
		cout<<"=("<<endl;
		return;
	}
	vi lol;
	int pol=(ans*(ans-1))/2;
	int nn=ans;
	for(int i=n; i>0; i--) {
		rep(j,0,dp[i][nn][pol])
			lol.pb(a[i-1]);
		int te=dp[i][nn][pol];
		pol-=a[i-1]*te;
		nn-=te;
	}
	lol.pb(-1);
	n=ans;
	rep(i,0,n) {
		int losses=n-i-1-lol[i];
		int upto=i;
		rep(j,i+1,n) {
			graph[i][j]=1;
			graph[j][i]=0;
		}
		while(losses>0) {
			int j=upto+1;
			while(j<n) {
				if(lol[j]!=lol[j+1])
					break;
				j++;
			}
			trace(i,j,losses,lol);
			int upto2=j;
			while(losses>0&&j>upto) {
				losses--;
				graph[i][j]=0;
				graph[j][i]=1;
				lol[j]--;
				j--;
			}
			upto=upto2;
		}
	}
	cout<<n<<endl;
	rep(i,0,n) {
		rep(j,0,n)
			cout<<graph[i][j];
		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}