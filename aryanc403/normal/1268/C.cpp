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
#include "/home/priank/codes/PastCodes/header.h"
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
const lli maxN = 200000L;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set =  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b,ans;
    ordered_set cc;

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

bit<lli> bt(1),ct(1);

lli eval(lli m)
{
    lli ans=0,l,r;

    r=m+bt.sum(n+1)-bt.sum(m);
    l=m;
    ans+=ct.sum(n+1)-ct.sum(m);
    ans-=r*(r+1)/2-l*(l+1)/2;

    r=m;
    l=m-bt.sum(m);
    ans-=ct.sum(m);
    ans+=r*(r+1)/2-l*(l+1)/2;
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);

    b.resize(n+1,0);
    ans.resize(n+1,0);

    bt=bit<lli>(n+1);
    ct=bit<lli>(n+1);

    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
        b[in]=i;
    }

    dbg(b);

    repA(i,1,n)
    {
        cnt+=i-1-bt.sum(b[i]);
        bt.add(b[i],1);
        ct.add(b[i],b[i]);

        ans[i]+=cnt;
        cc.insert(b[i]);

        if(i%2)
        {
            lli m=*cc.find_by_order(i/2);
            ans[i]+=eval(m);
        }
        else
        {
            lli m=0;
            m+=*cc.find_by_order(i/2);
            m+=*cc.find_by_order(i/2-1);
            m/=2;
            dbg(m);
            ans[i]+=eval(m);
        }
    }

    repA(i,1,n)
        cout<<ans[i]<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}