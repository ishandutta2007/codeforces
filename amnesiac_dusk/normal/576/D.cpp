#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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
const int mod=998244353;
//const int mod=1000000007;
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

int temp[160][160];
struct Matrix {
	vector<vi> a;
	bool tran;
	Matrix(bool tran):tran(tran) {
		if(tran) {
			a.resize(160,vi(5,0));
		} else {
			a.resize(5,vi(160,0));
		}
	}
	Matrix transpose() {
		Matrix tr(tran^1);
		if(tran==0)
			for(int i=0; i<160; i++)
				for(int j=0; j<160; j++)
					tr.a[i][j/32]|=((a[i/32][j]>>(i&31))&1)<<(j&31);
		else
			for(int i=0; i<160; i++)
				for(int j=0; j<160; j++)
					tr.a[i/32][j]|=((a[i][j/32]>>(j&31))&1)<<(i&31);
		return tr;
	}
	Matrix operator*(Matrix o){
		Matrix res(1);
		memset(temp,0,sizeof(temp));
		if(this->tran&&o.tran==0) {
			for(int i=0; i<160; i++)
				for(int j=0; j<5; j++)
					for(int k=0; k<160; k++) {
						temp[i][k]|=(this->a[i][j])&o.a[j][k];
					}
			for(int i=0; i<160; i++) {
				for(int j=0; j<160; j++) {
					if(temp[i][j]) {
						res.a[i][j/32]|=(1<<(j&31));
					}
				}
			}
		} else {
			assert(0);
		}
		return res;
	}
};
Matrix pow(Matrix b, int e) {
	if(e==1)
		return b;
	if(e&1)
		return pow(b,e-1)*b.transpose();
	Matrix res=pow(b,e>>1);
	return res*res.transpose();
}
Matrix at(1),tran(1);
ll gra[160][160],n;
ll fordsofbellman() {
	memset(gra,0x3f3f3f3f,sizeof(gra));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(tran.a[i][j/32]&(1<<(j&31)))
				gra[i][j]=1;
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				gra[j][k]=min(gra[j][k],gra[j][i]+gra[i][k]);
	ll res=infl;
	for(int i=1; i<=n; i++) {
		if(at.a[1][i/32]&(1<<(i&31))) {
			res=min(res,gra[i][n]);
		}
	}
//	fr(i,1,n) {
//		cout<<at.a[i][0]<<endl;
//	}
	Matrix tul=tran.transpose();
//	trace(res);
//	fr(i,1,n) {
//		cout<<tul.a[0][i]<<endl;
//	}
//	fr(i,1,n) {
//		cout<<tran.a[i][0]<<endl;
//	}
//	fr(i,1,n) {
//		fr(j,1,n) {
//			cout<<gra[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	trace(res);
	return res;
}
void solve() {
	int m;
	cin>>n>>m;
	map<int,vector<pii>> edges;
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		if(edges.find(w)==edges.end())
			edges[w]=vector<pii>();
		edges[w].pb({u,v});
	}
	at.a[1][0]=2;
	int cur=0;
	ll ans=infl;
	for(auto i:edges) {
		if(i.fi!=cur)
			at=at*pow(tran,i.fi-cur).transpose();
		for(auto j:i.se) {
			tran.a[j.fi][j.se/32]|=1<<(j.se&31);
		}
		cur=i.fi;
		ans=min(ans,cur+fordsofbellman());
	}
//	cout<<ans<<endl;
	if(ans<1e15)
		cout<<ans<<endl;
	else
		cout<<"Impossible"<<endl;
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