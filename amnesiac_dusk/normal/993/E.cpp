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
#define int long long
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

const f80 PI=acos(-1);
struct cpx {
	f80 x,y;
	cpx &operator+=(const cpx &rhs) {
		x+=rhs.x,y+=rhs.y;
		return *this;
	}
	cpx &operator-=(const cpx &rhs) {
		x-=rhs.x,y-=rhs.y;
		return *this;
	}
	cpx &operator*=(const cpx &rhs) {
		f80 _x=x*rhs.x-y*rhs.y;
		f80 _y=x*rhs.y+y*rhs.x;
		x=_x,y=_y;
		return *this;
	}
};
const int N=1<<20;
cpx roots[N];
cpx nthroot(int n) {
	if(roots[n].x==0&&roots[n].y==0)
		return roots[n]=cpx{cos(2*PI/n),sin(2*PI/n)};
	return roots[n];
}
cpx operator+(cpx lhs, const cpx &rhs) {
	return lhs+=rhs;
}
cpx operator-(cpx lhs, const cpx &rhs) {
	return lhs-=rhs;
}
cpx operator*(cpx lhs, const cpx &rhs) {
	return lhs*=rhs;
}
void DFT(vector<cpx> &v, bool b=0) {
	int n=v.size();
	for(int i=2;i<=n;i<<=1) {
		int l=0,r=i-1;
		cpx wn=nthroot(i);
		if(b)
			wn.y*=(-1);
		fr(j, 0, n / i - 1)
		{
			cpx w={1,0};
			int m=l+i/2;
			fr(k, l, m - 1)
			{
				cpx t=w*v[k+i/2];
				v[k+i/2]=v[k]-t;
				v[k]+=t;
				w*=wn;
			}
			l+=i,r+=i;
		}
	}
}
int bitrev(int r, int b) {
	int c=0;
	while(b--) {
		c<<=1;
		if(r&1)
			c++;
		r>>=1;
	}
	return c;
}
void reorder(vector<cpx> &v, int b) {
	int n=v.size();
	vector<cpx> temp(n);
	fr(i, 0, n - 1)
		temp[i]=v[bitrev(i,b)];
	v=temp;
}
vector<f80> polymul(vector<f80> v1, vector<f80> v2) {
	int n=max(v1.size(),v2.size());
	v1.resize(n),v2.resize(n);
	int c=1,b=0;
	while(c<2*n)
		b++,c<<=1;
	vector<cpx> t1(c),t2(c),t3(c);
	fr(i, 0, n - 1)
		t1[i] = {v1[i], v2[i]};
	t1.resize(c);
	reorder(t1,b);
	DFT(t1);
	t2[0].x=t1[0].x;
	t3[0].x=t1[0].y;
	fr(i, 1, c - 1) {
		t2[i].x=(t1[i].x+t1[c-i].x)/2;
		t2[i].y=(t1[i].y-t1[c-i].y)/2;
		t3[i].x=(t1[i].y+t1[c-i].y)/2;
		t3[i].y=(t1[c-i].x-t1[i].x)/2;
	}
	fr(i, 0, c - 1)
		t1[i]=t2[i]*t3[i];
	reorder(t1,b);
	DFT(t1,1);
	vector<f80> ans;
	fr(i, 0, t1.size() - 1)
		ans.pb(t1[i].x/c);
	return ans;
}
int a[200005],pre[200005];
void solve() {
	int n,x;
	cin>>n>>x;
	fr(i,1,n) {
		cin>>a[i];
		if(a[i]<x)
			pre[i]++;
		pre[i]+=pre[i-1];
	}
	vector<f80> lo1(n+1,0),lo2(n+1,0);
	fr(i,1,n) {
		lo1[pre[i]]+=1;
	}
	fr(i,0,n-1)
		lo2[n-pre[i]]+=1;
	vector<f80> res=polymul(lo1,lo2);
	res[n]=(n*(n+1LL))/2;
	for(int i=n+1; i<=2*n; i++)
		res[n]-=(int)(res[i]+0.5);
	for(int i=n; i<=2*n; i++) {
		cout<<(int)(res[i]+0.5)<<" ";
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