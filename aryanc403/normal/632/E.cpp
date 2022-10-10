/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 998244353L;

namespace ntt{
#define re(i, n)    for(lli i = 0; i < (n); ++i)
#define reA(i, a, n)  for(lli i = a; i <= (n); ++i)
#define reD(i, a, n)  for(lli i = a; i >= (n); --i)
#define SZZ(x) (lli)(x).size()

const lli MAGIC = 200; // (factor 10 optimization for |a|,|b| = 10)

const lli mod = (119LL << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.
// Credits - https://www.codechef.com/viewsolution/20497234
lli modpow(lli a, lli e) {
		if (e == 0) return 1;
			lli x = modpow(a * a % mod, e >> 1);
				return e & 1 ? x * a % mod : x;
}

typedef vector<lli> vl;
void ntt(lli* x, lli* temp, lli* roots, lli N, lli skip) {
	if (N == 1) return;
	lli n2 = N/2;
	ntt(x     , temp, roots, n2, skip*2);
	ntt(x+skip, temp, roots, n2, skip*2);
	re(i,N) temp[i] = x[i*skip];
	re(i,n2) {
		lli s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
	}
}
void ntt(vl& x, bool inv = false) {
	lli e = modpow(root, (mod-1) / SZZ(x));
	if (inv) e = modpow(e, mod-2);
	vl roots(SZZ(x), 1), temp = roots;
	reA(i,1,SZZ(x)-1) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], SZZ(x), 1);
}

void conv(vl &c,vl a, vl b) {
    lli s = SZZ(a) + SZZ(b) - 1; if (s <= 0) { c.clear(); return ;}
	lli L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;

    if (s <= MAGIC) { // (factor 10 optimization for |a|,|b| = 10)
    	c.clear();c.resize(s,0);
		re(i,SZZ(a)) re(j,SZZ(b))
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
		return;
	}

    a.resize(n,0); ntt(a);
	b.resize(n,0); ntt(b);
	c.clear();c.resize(n,0);
    lli d = modpow(n, mod-2);
	re(i,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s);
    for(auto &x:c)
    {
        if(x<0)
            x+=mod;
    }
}

// a*a
void conv2(vl &c,vl a) {
    lli s = 2*SZZ(a) - 1; if (s <= 0) { c.clear(); return ;}
	lli L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;

    if (s <= MAGIC) { // (factor 10 optimization for |a|,|b| = 10)
        c.clear();c.resize(s,0);
		re(i,SZZ(a)) re(j,SZZ(a))
			c[i + j] = (c[i + j] + a[i] * a[j]) % mod;
		return;
	}

	a.resize(n,0); ntt(a);
    c.clear();c.resize(n,0);
    lli d = modpow(n, mod-2);
	re(i,n) c[i] = a[i] * a[i] % mod * d % mod;
	ntt(c, true); c.resize(s);
    for(auto &x:c)
    {
        if(x<0)
            x+=mod;
    }
}
}

const lli N = 1000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void reduce(vi &a)
{
    for(auto &x:a)
        x=(x>0);

    if((lli)a.size()<=N)
        return;
    a.resize(N+1);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
{

    cin>>n>>k;
    a.clear();a.resize(1024,0);

    fo(i,n)
    {
        cin>>in;
        a[in]=1;
    }

    // dbg(a);
    ans.pb(1);

    while(k)
    {
        if(k&1)
        {
            // dbg(1LL<<i);
            ntt::conv(ans,ans,a);
            reduce(ans);
        }
        k/=2;
        ntt::conv2(a,a);
        reduce(a);
    }

    // dbg(ans);
    n=min(N,(lli)ans.size()-1);
    repA(i,1,n)
    {
        if(ans[i])
            cout<<i<<" ";
    }
    cout<<endl;

}   aryanc403();
    return 0;
}