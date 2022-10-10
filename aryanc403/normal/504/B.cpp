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
#define sz(x) (int)(x).size()
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
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
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

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    vi ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

template<typename T>
struct bit{
// Ref - https://codeforces.com/contest/1208/submission/59476716
	lli n;
	vector<T> fen;
	bit(): n(0) {}
	bit(lli _n) : n(_n), fen(_n+10) {}
	void add(lli p,T val){
		for(;p <= n;p += p & -p)
			fen[p] += val;
	}
	T sum(lli p){
		T ans = 0;
		for(;p > 0;p -= p & -p)
			ans += fen[p];
		return ans;
	}
};
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    bit<lli> bt(n+5);
    ans.resize(n+10,0);
    for(lli i=n;i;i--)
    {
        cin>>in;
        in++;
        bt.add(in,1);
        in-=bt.sum(in);
        lli f=i-1;
        if(f==0)
            f=1;
        ans[f]+=in;
    }

    bt=bit<lli>(n);
    for(lli i=n;i;i--)
    {
        cin>>in;
        in++;
        bt.add(in,1);
        in-=bt.sum(in);
        lli f=i-1;
        if(f==0)
            f=1;
        ans[f]+=in;
    }

    for(lli i=1;i<n;++i)
    {
        lli &cnt=ans[i];
        lli fw=cnt/(i+1);
        cnt%=i+1;
        ans[i+1]+=fw;
    }
    ans.resize(n);
    dbg(ans);

    ordered_set s;
    fo(i,n)
        s.insert(i);
    for(lli i=n-1;i>=0;i--)
    {
        auto it=s.find_by_order(ans[i]);
        a.pb(*it);
        s.erase(it);
    }
    for(auto x:a)
        cout<<x<<" ";

}   aryanc403();
    return 0;
}