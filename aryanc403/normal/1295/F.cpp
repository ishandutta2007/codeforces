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

const lli mod = 998244353LL;
const lli N = 52LL;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vii a;

lli fac[N+5],inv[N+5];
lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n%2)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

void pre(lli n)
{
    lli i;
    fac[0]=1;
    repA(i,1,n)
        fac[i]=(i*fac[i-1])%mod;
    inv[n]=po(fac[n],mod-2);
    repD(i,n,1)
        inv[i-1]=(i*inv[i])%mod;
    assert(inv[0]==1);
}

lli interpolate(const vi &a,lli p)
{
    if(p<sz(a))
        return a[p];
    
    lli ans=0,i;
    const lli n=sz(a);
    vi pp(n,0);

    fo(i,n)
        pp[i]=(i==0?1:pp[i-1])*(p-i)%mod;

    fo(i,n)
    {
        lli v=a[i];
        // fo(j,n)
        // {
        //     if(i==j)
        //         continue;
            
        //     if(j<i)
        //         v*=p-j;
        //     else
        //         v*=j-p;
        //     v%=mod;
        //     // v*=po(i-j,mod-2);v%=mod;
        // }

        v*=inv[i];v%=mod;
        v*=inv[n-1-i];v%=mod;
        v*=po(p-i,mod-2);v%=mod;
        v*=pp[n-1];v%=mod;

        if(i%2==0)
            v*=-1;
        // v*=pp[n-1-i];v%=mod;
        ans+=v;
    }

    ans%=mod;
    ans+=mod;
    ans%=mod;
    return ans;
}

void addPoly(vi &a,const vi &b,lli cnt)
{
    a.clear();
    for(const auto &x:b)
    {
        cnt+=x;cnt%=mod;
        a.pb(cnt);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    // chk();
    pre(N);
    lli den=1;
    cin>>n;
    fo(i,n)
    {
        cin>>l>>r;
        a.pb({l,r});
        den*=r-l+1;
        den%=mod;
    }

    dbg(578894053*den%mod)

    den=po(den,mod-2);
    den%=mod;den+=mod;den%=mod;

    reverse(all(a));
    lli pvr=-INF;
    for(auto &x:a)
        pvr=x.X=max(x.X,pvr);
    
    pvr=INF;
    repD(i,n-1,0)
        pvr=a[i].Y=min(pvr,a[i].Y);

    for(auto x:a)
        if(x.Y<x.X)
        {
            cout<<0<<endl;
            return 0;
        }

    vi b;

    // b.pb(0);
    for(auto x:a)
        b.pb(x.X),b.pb(x.Y+1);
    
    sort(all(b));
    b.erase(unique(all(b)),b.end());

    n=sz(b);n--;
    dbg(b);

    vector<vi> dp(n,vi(N,1));
    // dp[0].clear();dp[0].resize(N,1);
    // fo(i,N)
    //     dp[0][i]=i+1;
    
    for(auto &x:dp)
        x=dp[0];

    dbg(a);
    dbg(dp);
    for(auto x:a)
    {
        const lli l=x.X,r=x.Y+1;
        lli cnt=0;
        vector<vi> dp2(n);
        fo(i,n)
        {
            if(r<=b[i]||b[i]<l)
            {
                dp2[i].clear();
                dp2[i].resize(N,cnt);
            }
            else
            {
                addPoly(dp2[i],dp[i],cnt);
                cnt=interpolate(dp2[i],b[i+1]-b[i]-1);
                // dbg(l,r,b[i])
            }
            
            dbg(b[i],b[i+1]-1,b[i+1]-b[i])
            cnt%=mod;cnt+=mod;cnt%=mod;
        }
        dp2.swap(dp);
        dbg(dp);
    }
    
    // den=1;
    cout<<(interpolate(dp[n-1],b[n]-b[n-1]-1)*den)%mod<<endl;

}   aryanc403();
    return 0;
}

/***
499122177
578894053
1
1
***/