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
const lli maxN = 20000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,c;
    string s[maxN+5];
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

char chicken(lli n)
{
    if(n<10)
        return '0'+n;
    n-=10;
    if(n<26)
        return 'a'+n;
    n-=26;
    if(n<26)
        return 'A'+n;
    assert(false);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>r>>c>>k;
    a.clear();a.reserve(n);

    lli cnt=0;
    fo(i,r)
    {
        cin>>s[i];
        for(auto x:s[i])
            cnt+=(x=='R');
    }

    fo(i,k)
        a.pb(cnt/k);

    dbg(cnt);
    cnt%=k;

    while(cnt)
    {
        a[cnt]++;
        cnt--;
    }

    sort(all(a));
    dbg(a);

    lli pre=sz(a)-1;
    fo(i,r)
    {
        lli dr,j;
        if(i%2)
        {
            dr=1;
            j=0;
        }
        else
        {
            dr=-1;
            j=c-1;
        }

        for(;0<=j&&j<c;j+=dr)
        {
            if(pre==-1)
                pre=0;
            if(s[i][j]=='R')
                a[pre]--;
            // dbg(pre,chicken(pre));
            s[i][j]=chicken(pre);
            if(a[pre]==0)
                pre--;
        }
    }

    fo(i,r)
        cout<<s[i]<<endl;
}   aryanc403();
    return 0;
}