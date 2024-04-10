//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//#include <self/debug>
//#include <self/factorization>
//using namespace std;
//Factorization d;
//
//int n;
//vector<pair<int,pii> > edges[200005];
//int res[200005];
//int mn[200005];
//int inum[200005];
//int s[200005],now;
//
//inline int fastpow(ll basic,int x)
//{
//	ll res=1;
//	while(x)
//	{
//		if(x&1) (res*=basic)%=mod;
//		(basic*=basic)%=mod;
//		x>>=1;
//	}
//	return res;
//}
//
//void add(int p,int w)
//{
//	// debug(now,p,w);
//	s[p]+=w;
//	for(int i=0;i<w;i++) chmul(now,p);
//	for(int i=0;i<-w;i++) chmul(now,inum[p]);
//	// debug(p,s[p]);
//	chmin(mn[p],s[p]);
//	// debug(now,p,w);
//}
//
//void dfs(int x,int par)
//{
//	for(auto [u,o]:edges[x])
//	{
//		if(u==par) continue;
//		int a=o.first,b=o.second;
//		int g=__gcd(a,b);a/=g;b/=g;
//		vector<pii> v1=d.factorizeFast(a),v2=d.factorizeFast(b);
//		// if(x==0 && u==1) debug(now);
//		for(auto [p,k]:v1) add(p,-k);
//		for(auto [p,k]:v2) add(p,k);
//		res[u]=now;
//		dfs(u,x);
//		for(auto [p,k]:v1) add(p,k);
//		for(auto [p,k]:v2) add(p,-k);
//	}
//}
//
//void solve()
//{
//	cin>>n;
//	for(int i=0;i<n;i++) edges[i].clear();
//	for(int i=1;i<=n;i++) mn[i]=0,s[i]=0;
//	for(int i=0;i<n-1;i++)
//	{
//		int a,b,x,y;
//		scanf("%d%d%d%d",&a,&b,&x,&y);
//		a--;b--;
//		edges[a].emplace_back(b,mp(x,y));
//		edges[b].emplace_back(a,mp(y,x));
//	}
//	now=1;
//	// now=16;
//	// s[2]=4;
//	res[0]=now;
//	dfs(0,-1);
//	int ans=0;
//	for(int i=0;i<n;i++) chadd(ans,res[i]);
//	for(int i=1;i<=n;i++)
//	{
//		if(mn[i]==0) continue;
//		int w=fastpow(i,-mn[i]);
//		ans=1LL*ans*w%mod;
//	}
//	cout<<ans<<endl;
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	d.initPrimeList(200000);
//	inum[1]=1;
//	for(int i=2;i<=200000;i++) inum[i]=1LL*(mod-mod/i)*inum[mod%i]%mod;
//	int T;
//	cin>>T;
//	while(T--) solve();
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_CONST_MOD 998244353
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp(a,b) make_pair(a,b)
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		std::cout<<(x&1);
		x>>=1;
		len--;
		// vec.push_back(x&1);
		// x>>=1;
	}
	while(len--) cout<<0;
	// reverse(vec.begin(),vec.end());
	// for(int i=(int)vec.size();i<len;i++)
	// {
	// 	putchar('0');
	// }
	// for(size_t i=0;i<vec.size();i++)
	// {
	// 	std::cout<<vec[i];
	// }
	// std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
using namespace std;
class Factorization
{
	public:
	vector <int> primes;
	bool *isprime;
	int n;
	void initPrimeList(int _n)
	{
		n=_n;
		isprime=new bool[n+5];
		for(int i=0;i<=n;i++)
		{
			isprime[i]=true;
		}
		isprime[0]=isprime[1]=false;
		for(int i=2;i<=n;i++)
		{
			if(isprime[i]) primes.push_back(i);
			for(auto &j:primes)
			{
				if(i*j>n) break;
				isprime[i*j]=false;
				if(i%j==0) break;
			}
		}
	}
	int getPrimeID(int p)
	{
		return lower_bound(primes.begin(),primes.end(),p)-primes.begin();
	}
	template <typename T>
	inline vector <T> getfactors(T x)
	{
		vector <T> vec;
		for(T i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				vec.push_back(i);
				if(i!=x/i) vec.push_back(x/i);
			}
		}
		sort(vec.begin(),vec.end());
		return vec;
	}
	inline vector <pair<int,int> > factorizeFast(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(auto i:primes)
		{
			if(i*i>x) break;
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
	inline vector <pair<int,int> > factorize(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
	inline vector <int> factorizeflat(int x)
	{
		vector <int> vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
					vec.push_back(i);
				}
			}
		}
		if(nx!=1) vec.push_back(nx);
		return vec;
	}
	template <typename T>
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
};
using namespace std;
Factorization d;

int n;
vector<pair<int,pii> > edges[200005];
int res[200005];
int mn[200005];
int inum[200005];
int s[200005],now;

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

void add(int p,int w)
{
	// debug(now,p,w);
	s[p]+=w;
	for(int i=0;i<w;i++) chmul(now,p);
	for(int i=0;i<-w;i++) chmul(now,inum[p]);
	// debug(p,s[p]);
	chmin(mn[p],s[p]);
	// debug(now,p,w);
}

void dfs(int x,int par)
{
	for(auto [u,o]:edges[x])
	{
		if(u==par) continue;
		int a=o.first,b=o.second;
		int g=__gcd(a,b);a/=g;b/=g;
		vector<pii> v1=d.factorizeFast(a),v2=d.factorizeFast(b);
		// if(x==0 && u==1) debug(now);
		for(auto [p,k]:v1) add(p,-k);
		for(auto [p,k]:v2) add(p,k);
		res[u]=now;
		dfs(u,x);
		for(auto [p,k]:v1) add(p,k);
		for(auto [p,k]:v2) add(p,-k);
	}
}

void solve()
{
	cin>>n;
	for(int i=0;i<n;i++) edges[i].clear();
	for(int i=1;i<=n;i++) mn[i]=0,s[i]=0;
	for(int i=0;i<n-1;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		a--;b--;
		edges[a].emplace_back(b,mp(x,y));
		edges[b].emplace_back(a,mp(y,x));
	}
	now=1;
	// now=16;
	// s[2]=4;
	res[0]=now;
	dfs(0,-1);
	int ans=0;
	for(int i=0;i<n;i++) chadd(ans,res[i]);
	for(int i=1;i<=n;i++)
	{
		if(mn[i]==0) continue;
		int w=fastpow(i,-mn[i]);
		ans=1LL*ans*w%mod;
	}
	cout<<ans<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	d.initPrimeList(200000);
	inum[1]=1;
	for(int i=2;i<=200000;i++) inum[i]=1LL*(mod-mod/i)*inum[mod%i]%mod;
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}