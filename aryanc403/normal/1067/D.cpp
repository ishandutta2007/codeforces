/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double ld;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
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
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,t,k,in,cnt,l,r,u,v,x,y;
    lli m;
    ld mmax;
    string s;
    vector<pair<ii,ld>> a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int, int> pii;

template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] += d[i][k]*m.d[k][j];
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		vector<T> ret(N);
		rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j];
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a, b(*this);
		rep(i,0,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

struct Line {
	mutable ld k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ld inf = 1/.0;
	ld div(ld a, ld b) { // floored division
		return a / b; }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ld k, ld m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ld expo(ld ai,ld pi,ld dp,lli cur,lli deltap)
{
    Matrix<ld,3> a;
    a.d={{{{(ld)1-pi,(ld)pi*mmax,(ld)pi*ai}} , {{(ld)0,(ld)1,(ld)1}} , {{(ld)0,(ld)0,(ld)1}}}};
    vector<ld> ans={dp,cur,1};
    ans=(a^deltap)*ans;
    return ans[0];
}

lli run(ld ans,lli curp,Line line)
{
    lli l=curp-1,r=T;
    while(r-l>1)
    {
        lli m=(l+r)/2;
        if(m*mmax-expo(line.m/line.k,line.k,ans,curp,m-curp)<=line.p)
            l=m;
        else
            r=m;
    }
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>T;
    LineContainer sol;
    fo(i,n)
    {
        lli r,b;
        ld p;
        cin>>r>>b>>p;
        mmax=max(mmax,b*p);
        sol.add(p,p*r);
    }

    ld ans=0;
    lli p=0;

    for(auto line:sol)
    {
        // dbg(x.k,x.p,x.m);
        const lli nxt=run(ans,p,line);
        dbg(nxt);
        ans=expo(line.m/line.k,line.k,ans,p,nxt-p);
        p=nxt;
    }
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}