//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


int grid[27];
int gra[27][27];
int ans[14][2];
bool unsed[27];
int cop[27][27];
bool check(int at) {
	int cop[27];
	memcpy(cop,grid,sizeof(cop));
	for(int i=0; i<min(13LL,at); i++) {
		if(i<12)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				if(gra[ans[i][j]][ans[i+1][k]]) {
					cop[ans[i][j]]--;
					cop[ans[i+1][k]]--;
				}
		if(gra[ans[i][0]][ans[i][1]]) {
			cop[ans[i][0]]--;
			cop[ans[i][1]]--;
		}
	}
	for(int i=1; i<=26; i++) {
		if(unsed[i]==0&&cop[i]>0)
			return 0;
	}
//	for(int i=1; i<=26; i++)
//		cout<<cop[i]<<" ";
//	cout<<endl;
	return 1;
}
bool brute(int at) {
	if(check(at)==0)
		return 0;
	if(at==13)
		return 1;
	vi touse;
	for(int i=1; i<=26; i++)
		if(unsed[i])
			touse.pb(i);
	for(int i=0; i<sz(touse); i++)
		for(int j=i+1; j<sz(touse); j++) {
			ans[at][0]=touse[i];
			ans[at][1]=touse[j];
			unsed[touse[i]]=0;
			unsed[touse[j]]=0;
			if(brute(at+1))
				return 1;
			unsed[touse[i]]=1;
			unsed[touse[j]]=1;
			ans[at][0]=0;
			ans[at][1]=0;
		}
	return 0;
}
void solve() {
	memset(unsed,1,sizeof(unsed));
	string s;
	cin>>s;
	for(char &i:s)
		i-='A'-1;
	for(int i=0; i<27; i++)
		gra[0][i]=gra[i][0]=1;
	for(int i=1; i<s.length(); i++) {
		gra[s[i]][s[i-1]]=1;
		gra[s[i-1]][s[i]]=1;
	}
	for(int i=1; i<=26; i++) {
		grid[i]=accumulate(gra[i]+1, gra[i]+27, 0LL);
		if(grid[i]>5) {
			cout<<"Impossible"<<endl;
			return;
		}
	}
	if(brute(0)) {
		for(int i=0; i<13; i++) {
			cout<<((char)(ans[i][0]+'A'-1));
		}
		cout<<endl;
		for(int i=0; i<13; i++) {
			cout<<((char)(ans[i][1]+'A'-1));
		}
	} else {
		cout<<"Impossible"<<endl;
	}

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
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}