//#pragma GCC optimize("Ofast,unroll-loops")
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int a[300005];
int lob[300005],rib[300005],last[300005];
int ans=0;
int sparse[20][500005];
int query(int l, int r) {
	int lol=r-l+1;
	int lo=8*sizeof(unsigned long long)-__builtin_clzll(lol)-1;
	trace(lol,lo,l,r);
	return max(sparse[lo][l],sparse[lo][r+1-(1<<lo)]);
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		lob[i]=max(lob[i-1],last[a[i]]);
		last[a[i]]=i;
	}
	fr(i,1,n+1)
		last[i]=n+1;
	rib[n+1]=n+1;
	for(int i=n; i>0; i--) {
		rib[i]=min(rib[i+1],last[a[i]]);
		last[a[i]]=i;
	}
	fr(i,1,n) {
		lob[i]++;
		rib[i]--;
	}
	fr(i,1,n)
		sparse[0][i]=a[i];
	for(int j=1; j<20; j++)
		for(int i=1; i+(1<<(j-1))<=n; i++)
			sparse[j][i]=max(sparse[j-1][i],sparse[j-1][i+(1<<(j-1))]);
	int ans=0;
	fr(i,1,n) {
		if(a[i]==1) {
			int te=a[i];
			for(int j=i; j>=lob[i]; j--) {
				te=max(te,a[j]);
				int qq=query(j,j+te-1);
				trace(qq,te,j,rib[j],j+te-1);
				if(query(j,j+te-1)==te&&rib[j]>=j+te-1) {
					ans++;
				}
			}
			te=a[i];
			for(int j=i+1; j<=rib[i]; j++) {
				te=max(te,a[j]);
				int qq=query(j-te+1,j);
				trace(qq,te,j,lob[j],j-te+1);
				if(query(j-te+1,j)==te&&lob[j]<=j-te+1) {
					ans++;
				}
			}
			trace(ans);
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
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}