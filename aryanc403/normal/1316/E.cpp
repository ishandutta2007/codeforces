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
#define sz(x) (lli)(x).size()
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
const lli N = 100000L;
const lli M = 7L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,p;
    string s;
    vi a,b;
    vector<vi> prf;
    // lli dp[1LL<<M][N];
    vector<vi> dp;
    vi prt;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli bc(lli x)
{
    return __builtin_popcount(x);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>p>>k;
    a.clear();a.reserve(n);
    b.resize(n+1);
    iota(all(b),0);

    prt.resize(n+1,-1);

    // dbg(b);
    a.pb(INF);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    prf.resize(n+1,vi(p,0));
    repA(i,1,n)
        fo(j,p)
            cin>>prf[i][j];

    sort(all(b),[&](const lli x,const lli y){
        return a[x]>a[y];
    });

    dp.resize(n+1,vi(1LL<<p,-INF));
    dp[0][0]=0;
    repA(i,1,n)
    {
        const lli x=b[i];
        const vi &pvr=dp[i-1];
        const vi &curprf=prf[x];
        vi &cur=dp[i];
        
        fo(j,1LL<<p)
        {
            // dbg(i,j,k,i-bc(j))
            cur[j]=max(cur[j],pvr[j]+ ( i-bc(j)<=k ?a[x]:0LL) );
            fo(l,p)
            {
                if(j&(1LL<<l))
                    continue;
                cur[j^(1LL<<l)]=max(cur[j^(1LL<<l)],pvr[j]+curprf[l]);
            }
        }

        dbg(i,cur);
        dbg(a[x],curprf);
    }

    lli cst=dp[n][(1LL<<p)-1],msk=(1LL<<p)-1;
    cout<<cst<<endl;
    return 0;
    repD(i,n,1)
    {
        const lli x=b[i];
        const vi &pvr=dp[i-1];
        const vi &curprf=prf[x];
        
        lli pos=-1;
        fo(l,p)
        {
            if((msk&(1LL<<l))==0)
                continue;
    ;       if(pvr[msk^(1LL<<l)]+curprf[l]==cst)
            {
                pos=l;
                break;
            }
        }

        if(pos!=-1)
        {
            prt[x]=pos+1;
            cst-=curprf[pos];
            msk^=(1LL<<pos);
            continue;
        }

        if(i-bc(msk)<=k)
        {
            prt[x]=0;
            cst-=a[x];
        }
    }

    assert(cst==0);
    repA(i,1,n)
        cout<<prt[i]<<" ";
    

}   aryanc403();
    return 0;
}