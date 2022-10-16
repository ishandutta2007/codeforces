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
int N=100;
int a[200005],cnt[200005];
int loccur[400010];
int n;
int maxi=0;
auto here=loccur+200005;
int solver() {
	int fans=0;
	fr(i,1,N) {
		if(i!=maxi) {
			memset(loccur,-1,sizeof(loccur));
			int last=0,val=0;
			fr(j,1,n) {
				if(a[j]==maxi||a[j]==i) {
					if(here[val]==-1)
						here[val]=last;
					if(a[j]==maxi)
						val++;
					else
						val--;
					last=j;
				}
				if(here[val]!=-1)
					fans=max(fans,j-here[val]);
			}
		}
	}
	return fans;
}
void solve() {
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	fr(i,1,N)
		if(cnt[i]>cnt[maxi])
			maxi=i;
	int answer=solver();
	cout<<answer<<endl;
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