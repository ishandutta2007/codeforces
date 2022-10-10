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
typedef long double mytype;
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
const lli N = 1000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s,t;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

const lli B1=107;
const lli mod1=982451707;
const lli B2=209;
const lli mod2=1190500783;

vi pw1,pw2;
void pre(lli n)
{
    n+=5;
    pw1.clear();pw1.pb(1);
    pw2.clear();pw2.pb(1);
    while(n--)
    {
        pw1.pb(pw1.back()*B1%mod1);
        pw2.pb(pw2.back()*B2%mod2);
    }
}

void hashh(vi &a,const string &s,lli fl)
{
    a.clear();
    a.pb(0);

    if(fl==1)
    {
        for(auto x:s)
            a.pb((a.back()*B1+x)%mod1);
    }

    if(fl==2)
    {
        for(auto x:s)
            a.pb((a.back()*B2+x)%mod2);
    }
}

lli gt(const vi &a,lli i,lli j,lli fl)
{
    i--;
    lli x=0;
    
    if(fl==1)
    {
        x=a[j]-a[i]*pw1[j-i];
        x%=mod1;x+=mod1;x%=mod1;
    }

    if(fl==2)
    {
        x=a[j]-a[i]*pw2[j-i];
        x%=mod2;x+=mod2;x%=mod2;
    }
    return x;
}

string solveP(const string &s,const vi &p1,const vi &s1,const vi &p2,const vi &s2)
{
    const lli n=sz(s);
    lli ans=0;
    for(lli i=1;i<=n;++i)
    {
        if(gt(p1,1,i,1)==gt(s1,n-i+1,n,1)&&gt(p2,1,i,2)==gt(s2,n-i+1,n,2))
            ans=i;
    }
    return s.substr(0,ans);
}

string solve(string s)
{
    string ans1="",ans2="";
    string t=s;
    reverse(all(t));
    vi p1,s1;
    hashh(p1,s,1);
    hashh(s1,t,1);

    vi p2,s2;
    hashh(p2,s,2);
    hashh(s2,t,2);

    ans1=solveP(s,p1,s1,p2,s2);
    reverse(all(s));
    ans2=solveP(s,s1,p1,s2,p2);
    dbg(ans1,ans2);
    if(sz(ans1)>sz(ans2))
        return ans1;
    return ans2;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
pre(N);
cin>>T;while(T--)
{

    cin>>s;
    dbg(s);
    n=sz(s);
    lli i=0,j=n-1;

    while(i<j&&s[i]==s[j])
    {
        i++;
        j--;
    }

    if(i>=j)
    {
        cout<<s<<endl;
        continue;
    }

    t=s.substr(0,i);
    cout<<t;
    cout<<solve(s.substr(i,j-i+1));
    reverse(all(t));
    cout<<t;
    cout<<endl;

}   aryanc403();
    return 0;
}