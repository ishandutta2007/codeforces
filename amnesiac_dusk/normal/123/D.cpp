/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#else
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


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
int m = max(256, n);
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
Suffix_Array(vector<int>const&s):Suffix_Array(s.data(), s.size()){}
Suffix_Array(char const*s, int _N):n(_N){build_SA(vector<int> (s, s+n).data());}
Suffix_Array(string const&s):Suffix_Array(s.data(),s.size()){}
vector<int> sa, inv, lcp;
const int n;
};
void solve()
{
	string s;
	cin>>s;
	Suffix_Array tola(s);
	int n=s.length();
	ll ans=(n*(n+1LL))/2;
	stack<pii> hola;
	hola.push({0,-1});
//	cout<<tola.lcp.size()<<endl;
	tola.lcp[n-1]=0;
	for(int i=0; i<n; i++)
	{
		int ii=i;
		while(hola.top().fi>tola.lcp[i])
		{
			pii temo=hola.top();
			hola.pop();
			ii=temo.se;
			ans+=((temo.fi-max(hola.top().fi,tola.lcp[i]))*(i-temo.se+0LL)*(i-temo.se+1LL))/2;
		}
		if(hola.top().fi<tola.lcp[i])
			hola.push({tola.lcp[i],ii});
	}
	cout<<ans<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}