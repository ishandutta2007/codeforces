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
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
typedef float f80;
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
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
const int NN=101;
class matrix {
public:
	ll mat[NN][NN];
	int r,c;
	matrix() {
		fr(i, 0, NN - 1)
			fr(j, 0, NN - 1)
				mat[i][j]=0;
	}
	void setsize(int _r, int _c) {
		r=_r,c=_c;
	}
	inline matrix operator *(const matrix &a) {
		assert(c==a.r);
		matrix temp;
		temp.setsize(r,a.c);
		fr(i, 0, r - 1)
			fr(j, 0, a.c - 1)
			{
				fr(k, 0, a.r - 1)
				{
					temp.mat[i][j]+=(mat[i][k]*a.mat[k][j])%mod;
					if(temp.mat[i][j]>=mod)
						temp.mat[i][j]-=mod;
				}
			}
		return temp;
	}
	inline matrix operator +(const matrix &a) {
		assert(r==a.r&&c==a.c);
		matrix temp;
		temp.setsize(r,c);
		fr(i, 0, r - 1)
			fr(j, 0, c - 1)
			{
				temp.mat[i][j]=mat[i][j]+a.mat[i][j];
				if(temp.mat[i][j]>=mod)
					temp.mat[i][j]-=mod;
			}
		return temp;
	}
	inline matrix operator -(const matrix &a) {
		assert(r==a.r&&c==a.c);
		matrix temp;
		temp.setsize(r,c);
		fr(i, 0, r - 1)
			fr(j, 0, c - 1)
			{
				temp.mat[i][j]=mat[i][j]-a.mat[i][j];
				if(temp.mat[i][j]<0)
					temp.mat[i][j]+=mod;
			}
		return temp;
	}
	inline void operator =(const matrix &a) {
		fr(i, 0, r - 1)
			fr(j, 0, c - 1)
				mat[i][j]=a.mat[i][j];
		r=a.r,c=a.c;
	}
	inline void print() {
		fr(i, 0, r - 1)
		{
			fr(j, 0, c - 1)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
};
matrix pow(matrix a, ll k) {
	assert(a.r==a.c);
	matrix ans;
	fr(i, 0, a.r - 1)
		ans.mat[i][i]=1;
	ans.r=a.r;
	ans.c=a.r;
	while(k) {
		if(k&1)
			ans=ans*a;
		a=a*a;
		k>>=1;
	}
	return ans;
}


void solve() {
	matrix a;
	int n,k;
	cin>>n>>k;
	int cntr=0;
	vi b(n);
	for(int i=0; i<n; i++) {
		cin>>b[i];
		cntr+=1-b[i];
	}
	a.setsize(n+1,n+1);
	for(int i=0; i<=n; i++) {
		a.mat[i][i]=(cntr*(cntr-1))/2+((n-cntr)*(n-cntr-1))/2+i*(cntr-i)+(cntr-i)*(n-2*cntr+i);
		if(i<n)
			a.mat[i][i+1]=(cntr-i)*(cntr-i);
		if(i)
			a.mat[i][i-1]=i*(n-2*cntr+i);
	}
	matrix ans;
	ans.setsize(1, n+1);
	int cnt=0;
	for(int i=0; i<cntr; i++)
		if(b[i]==0)
			cnt++;
	ans.mat[0][cnt]=1;
	ans=ans*pow(a,k);
	int sum=0;
	for(int i=0; i<=n; i++)
		sum=(sum+ans.mat[0][i])%mod;
	cout<<(ans.mat[0][cntr]*powm(sum,mod-2))%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}