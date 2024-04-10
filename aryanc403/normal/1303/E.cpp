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
    string s,t,a,b;
    bool fl;
    vector<vi> dp,bb;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli solve(lli n,lli m)
{
    // dbg(n,m)
    
    lli &ans=dp[n+1][m+1];
    if(ans!=-1)
        return ans;
    ans=INF;
    if(n!=-1)
    {
        // dbg(n,n-1,m);
        lli cur=solve(n-1,m)+1;
        // dbg(cur,sz(bb));
        if(cur<INF)
            ans=min(ans,bb[cur][a[n]-'a']);
    }

    if(m!=-1)
    {
        lli cur=solve(n,m-1)+1;
        // dbg(cur,sz(bb));
        if(cur<INF)
            ans=min(ans,bb[cur][b[m]-'a']);
    }

    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>s>>t;
    s="#"+s;
    fl=false;
    bb.clear();
    bb.resize(sz(s)+5,vi(26,INF));
    // dbg(sz(s),sz(bb));
    // dbg(s)
    repD(i,sz(s)-1,1)
    {
        // dbg(i,s[i],sz(s));
        assert(i+1<sz(bb));
        // dbg(s[i],s[i]-'a');
        bb[i]=bb[i+1];
        bb[i][s[i]-'a']=i;
    }
    // continue;
    for(lli l=1;l<=sz(t);++l)
    {
        a=t.substr(0,l);
        b=t.substr(l);
        n=sz(a);m=sz(b);
        dp.clear();
        dp.resize(n+2,vi(m+2,-1));
        dp[0][0]=0;
        // dbg(n,m,a,b)
        // dbg(solve(n-1,m-1),sz(s))
        if(solve(n-1,m-1)<sz(s))
        {
            fl=true;
            break;
        }
    }
    cout<<(fl?"YES":"NO")<<endl;
}   aryanc403();
    return 0;
}