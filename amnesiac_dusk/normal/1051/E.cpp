/*
 * 	i could never find the right way to tell you
 * 		have you noticed i've been gone?
 * 			cause i left behind the home that you made me
 * 				but i will carry it along
 * 	mm it's a long way forward
 * 		so trust in me
 * 			i'll give them shelter like you've done for me
 * 				and i know i'm not alone
 * 					you'll be watching over us
 * 						until you're gone
 * 	when i'm older i'll be silent beside you
 * 		I know that words are not enough
 * 			and they won't need to know our names or our faces
 * 				but they will carry on for us
 */

#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=2e9;
const int mod=998244353;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
class Suffix_Array{
void make_lcp(int const*s){
for(int i=0, k=0;i<n;++i)
if(inv[i]!=0){
for(int j =
sa[inv[i]-1];k<n&&s[i+k]==s[j+k];++k);
lcp[inv[i]-1]=k;
if(k)--k;
} else k=0;
}
bool cmp(vector<int> const&rank,int i,int j,int l){
return i<n-l && j<n-l && rank[i]==rank[j] &&
rank[i+l]==rank[j+l];
}
void build_SA(int const*s){
int m = max(256LL, n);
sa.resize(n);
vector<int> x(n), y(n), buck(m);
int i,j,p;
for(i=0;i<n;++i) buck[x[i]=s[i]]++;
for(i=1;i<m;++i) buck[i]+=buck[i-1];
for(i=n-1;i>=0;--i) sa[--buck[x[i]]]=i;
for(p=0,j=1;p+1<n;m=p+1,j*=2) {
for(p=0,i=n-j;i<n;++i) y[p++]=i;
for(i=0;i<n;++i) if (sa[i]>=j) y[p++]=sa[i]-j;
memset(buck.data(),0,sizeof(int)*(m));
for(i=0;i<n;++i) ++buck[x[y[i]]];
for(i=1;i<m;++i) buck[i]+=buck[i-1];
for(i=n-1;i>=0;--i) sa[--buck[x[y[i]]]]=y[i];
x.swap(y);
for(p=0,x[sa[0]]=0,i=1;i<n;i++)
x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p : ++p;
}
x.swap(inv); y.swap(lcp);
for(int i=0;i<n;++i) inv[sa[i]]=i;
make_lcp(s);
}
public:
Suffix_Array(int const*s, int _N):n(_N){build_SA(s);}
Suffix_Array(vector<int>
const&s):Suffix_Array(s.data(), s.size()){}
Suffix_Array(char const*s, int
_N):n(_N){build_SA(vector<int> (s, s+n).data());}
Suffix_Array(string const&s):Suffix_Array(s.data(),
s.size()){}

vector<int> sa, inv, lcp;
const int n;
};
const int N=1e6+5;
int dp[N];
int pre[N];
bool gret[N],sml[N];
void solve() {
	string a,l,r;
	cin>>a>>l>>r;
	int n=a.length();
	Suffix_Array lol(a);
	int lo=0,hi=n,mid=(lo+hi)/2;
	while(lo<hi) {
		if(a.substr(lol.sa[mid],n-lol.sa[mid])<l)
			lo=mid+1;
		else
			hi=mid;
		mid=(lo+hi)/2;
	}
	for(int i=mid; i<n; i++)
		if(lol.sa[i]+sz(l)<=n) {
			gret[lol.sa[i]]=1;
		}
	lo=-1;
	hi=n-1;
	mid=(lo+hi+1)/2;
	while(lo<hi) {
		if(a.substr(lol.sa[mid],min(sz(r),n-lol.sa[mid]))>r)
			hi=mid-1;
		else
			lo=mid;
		mid=(lo+hi+1)/2;
	}
	for(int i=0; i<=lo; i++)
		sml[lol.sa[i]]=1;
	dp[0]=1;
	for(int i=0; i<n; i++) {
		dp[i]=(dp[i]+pre[i])%mod;
		int lob,ub;
		if(gret[i])
			lob=i+sz(l);
		else
			lob=i+sz(l)+1;
		lob=min(lob,n+1);
		if(sml[i])
			ub=i+sz(r);
		else
			ub=i+sz(r)-1;
		if(a[i]=='0') {
			ub=min(ub,i+1);
		}
		ub=min(ub,n+1);
		if(lob<=ub) {
			pre[lob]=(pre[lob]+dp[i])%mod;
			pre[ub+1]=(pre[ub+1]-dp[i])%mod;
		}
		pre[i+1]=(pre[i+1]+pre[i])%mod;
	}
	cout<<(pre[n]%mod+mod)%mod<<endl;
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
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/