#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
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
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
 
const int mod=998244353;
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
 
//#define vi vector<int>
const int MAXN=19;
const int maxn=1<<MAXN;
const int root=3;
int A[maxn],B[maxn];
int W[maxn],iW[maxn],I[maxn];
int nn;
const int threshold=150;
 
namespace modulo {
	const int MOD=998244353;
	int add(const int &a, const int &b) {
		int val=a+b;
		if(val>=MOD)
			val-=MOD;
		return val;
	}
	int sub(const int &a, const int &b) {
		int val=a-b;
		if(val<0)
			val+=MOD;
		return val;
	}
	int mul(const int &a, const int &b) {
		return 1ll*a*b%MOD;
	}
}
using namespace modulo;
 
void ensureINV(int n) {
	if(n<=nn)
		return;
	if(!nn) {
		I[1]=1;
		nn=1;
	}
	fr(i, nn + 1, n)
		I[i]=(mod-mul((mod/i),I[mod%i]));
	nn=n;
}
int pwr(int a, int b) {
	int ans=1;
	while(b) {
		if(b&1)
			ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void precompute() {
	W[0]=iW[0]=1;
	int g=pwr(root,(mod-1)/maxn),ig=pwr(g,mod-2);
	fr(i, 1, maxn / 2 - 1)
	{
		W[i]=mul(W[i-1],g);
		iW[i]=mul(iW[i-1],ig);
	}
}
int rev(int i, int n) {
	int irev=0;
	n>>=1;
	while(n) {
		n>>=1;
		irev=(irev<<1)|(i&1);
		i>>=1;
	}
	return irev;
}
void go(int a[], int n) {
	fr(i, 0, n - 1)
	{
		int r=rev(i,n);
		if(i<r)
			swap(a[i],a[r]);
	}
}
void fft(int a[], int n, bool inv=0) {
	go(a,n);
	int len,i,j, *p, *q,u,v,ind,add;
	for(len=2; len<=n; len<<=1) {
		for(i=0; i<n; i+=len) {
			ind=0,add=maxn/len;
			p=&a[i],q=&a[i+len/2];
			fr(j, 0, len / 2 - 1)
			{
				v=mul((*q),(inv?iW[ind]:W[ind]));
				(*q)=sub((*p),v);
				(*p)=::add((*p),v);
				ind+=add;
				p++,q++;
			}
		}
	}
	if(inv) {
		int p=pwr(n,mod-2);
		fr(i, 0, n - 1)
			a[i]=mul(a[i],p);
	}
}
vi brute(const vi &a, const vi &b) { // brute multiplication
	vi c(a.size()+b.size()-1,0);
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<b.size(); j++) {
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
		}
	}
	return c;
}
vi mul(vi a, vi b) { // n = total size (power of 2)
	if(min(a.size(),b.size())<=threshold)
		return brute(a,b);
	int nn=sz(a)+sz(b)+1;
	int n=1;
	while(n<nn)
		n<<=1;
	assert((n&(n-1))==0);
	a.resize(n,0);
	b.resize(n,0);
	copy(all(a),A);
	fft(A,n);
	if(a==b)
		copy(A,A+n,B);
	else {
		copy(all(b),B);
		fft(B,n);
	}
	fr(i, 0, n - 1)
		A[i]=mul(A[i],B[i]);
	fft(A,n,1);
	vi c(A,A+n);
	c.resize(nn);
	return c;
}
vi inv(vi a, int m) { // get m terms
	assert(a[0]!=0);
	int tot=1;
	while(tot<m)
		tot<<=1;
	swap(tot,m);
	a.resize(m,0);
	vi ia(m,0);
	ia[0]=pwr(a[0],mod-2);
	for(int sz=2; sz<=m; sz<<=1) {
		copy(ia.begin(),ia.begin()+sz/2,A);
		copy(a.begin(),a.begin()+sz,B);
		fill(A+sz/2,A+(sz<<1),0);
		fill(B+sz,B+(sz<<1),0);
		fft(A,sz<<1);
		fft(B,sz<<1);
		fr(j, 0, (sz << 1) - 1)
			A[j]=add(A[j],sub(A[j],mul(mul(A[j],A[j]),B[j])));
		fft(A,sz<<1,1);
		copy(A,A+sz,ia.begin());
	}
	ia.resize(tot);
	return ia;
}
 
map<int, int> ol;
vi tr[400005];
void solve() {
	precompute();
	int n;
	cin>>n;
	fr(i,1,n)
	{
		int te;
		cin>>te;
		ol[te]++;
	}
	n=sz(ol);
	int troll=0;
	int cntr=0;
	set<pii> smol;
	for(auto i : ol) {
		troll+=i.se;
		for(int j=0; j<=i.se; j++)
			tr[cntr].pb(1);
		smol.insert({sz(tr[cntr]),cntr});
		cntr++;
	}
	while(sz(smol)>1) {
		pii fof=*smol.begin();
		smol.erase(smol.begin());
		pii sos=*smol.begin();
		smol.erase(smol.begin());
		tr[cntr]=mul(tr[fof.se],tr[sos.se]);
		smol.insert({sz(tr[cntr]),cntr});
		cntr++;
	}
	int indcntr=troll/2;
	pii fola=*smol.begin();
	tr[fola.se][indcntr]%=mod;
	tr[fola.se][indcntr]+=mod;
	tr[fola.se][indcntr]%=mod;
	cout<<tr[fola.se][indcntr]<<endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}