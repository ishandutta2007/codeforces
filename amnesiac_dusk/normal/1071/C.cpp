/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
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
int a[N];
int dist[1<<12],from[1<<12];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	vector<vi> ans;
	for(int i=1; i+12<=n; i++) {
		if(a[i]==0)
			continue;
		if(a[i]==1&&a[i+1]==1&&a[i+2]==1) {
			ans.pb({i,i+1,i+2});
			for(int j:ans.back())
				a[j]^=1;
			i+=2;
		} else if(a[i]==1&&a[i+1]==1) {
			int temp=a[i+3]*4+a[i+4]*2+a[i+5];
			if(temp==0) {
				ans.pb({i,i+1,i+2});
				for(int j:ans.back())
					a[j]^=1;
				ans.pb({i+2,i+6,i+10});
				for(int j:ans.back())
					a[j]^=1;
			} else if(__builtin_popcount(temp)==1) {
				ans.pb({i+1,i+6,i+11});
				for(int j:ans.back())
					a[j]^=1;
				int lol=0;
				while(temp) {
					lol++;
					temp>>=1;
				}
				ans.pb({i,i+6-lol,i+2*(6-lol)});
				for(int j:ans.back())
					a[j]^=1;
			} else if(temp==6) {
				ans.pb({i,i+3,i+6});
				for(int j:ans.back())
					a[j]^=1;
				ans.pb({i+1,i+4,i+7});
				for(int j:ans.back())
					a[j]^=1;
			} else if(temp==5) {
				ans.pb({i,i+3,i+6});
				for(int j:ans.back())
					a[j]^=1;
				ans.pb({i+1,i+5,i+9});
				for(int j:ans.back())
					a[j]^=1;
			} else if(temp==3) {
				ans.pb({i,i+4,i+8});
				for(int j:ans.back())
					a[j]^=1;
				ans.pb({i+1,i+5,i+9});
				for(int j:ans.back())
					a[j]^=1;
			} else {
				ans.pb({i,i+4,i+8});
				for(int j:ans.back())
					a[j]^=1;
				ans.pb({i+1,i+3,i+5});
				for(int j:ans.back())
					a[j]^=1;
			}
			i+=5;
		} else if(a[i]==1&&a[i+2]==1){
			ans.pb({i,i+2,i+4});
			for(int j:ans.back())
				a[j]^=1;
			i+=2;
		} else {
			ans.pb({i,i+3,i+6});
			for(int j:ans.back())
				a[j]^=1;
			i+=2;
		}
	}
	int number=0;
	for(int i=max(1,n-11); i<=n; i++) {
		number<<=1;
		if(a[i])
			number^=1;
	}
	memset(dist,-1,sizeof(dist));
	queue<int> bfs;
	int bits=min(12,n);
	bfs.push(0);
	dist[0]=0;
	vi ops;
	for(int j=0; j<bits; j++)
		for(int k=1; j+2*k<bits; k++)
			ops.pb((1<<j)|(1<<(j+k)|(1<<(j+2*k))));
	while(!bfs.empty()) {
		int tol=bfs.front();
		bfs.pop();
		for(int j:ops) {
			if(dist[tol^j]==-1) {
				dist[tol^j]=dist[tol]+1;
				from[tol^j]=tol;
				bfs.push(tol^j);
			}
		}
	}
	if(dist[number]==-1) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		while(number!=0) {
			ans.pb({});
			int tul=from[number]^number;
			for(int j=bits-1; j>=0; j--)
				if(tul&(1<<j))
					ans.back().pb(n-j);
			number=from[number];
		}
		cout<<sz(ans)<<endl;
		for(auto i:ans)
			cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}