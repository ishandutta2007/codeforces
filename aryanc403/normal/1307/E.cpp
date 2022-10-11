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
const lli N = 5000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<int> a;
    int cow[N+5][N+5];
    int pref[N+5][N+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    a.clear();a.reserve(n+1);
    a.pb(0);

    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
        repA(j,1,n)
            pref[i][j]=pref[i-1][j];
        pref[i][in]++;
    }

    fo(i,m)
    {
        lli f,h;
        cin>>f>>h;
        cow[f][h]=1;
    }

    repA(i,1,n)
    {
        repA(j,1,n)
            cow[i][j]+=cow[i][j-1];
    }

    lli ansmx=0,ansmj=0;
    repA(i,0,n)
    {
        const lli c=a[i];
        if(i)
        {
            const lli f=pref[i][c];
            // dbg(i,c,cow[c][i],cow[c][i-1])
            if(cow[c][f]==cow[c][f-1])
                continue;
        }
        dbg("len",i)
        lli curn=0,curw=1;
        repA(j,1,n)
        {
            const lli f=pref[i][j];
            const lli b=pref[n][j]-f;
            const lli fn=cow[j][f],bn=cow[j][b];
            dbg(i,j,fn,bn);
            if(j==c)
            {
                curn++;
                if(fn<=bn)
                {
                    if(bn>1)
                    {
                        curn++;
                        curw=(curw*(bn-1))%mod;
                    }
                    continue;
                }
                

                    if(bn)
                    {
                        curn++;
                        curw=(curw*bn)%mod;
                    }

                continue;
            }

            if(fn==0&&bn==0)
                continue;
            
            if(fn==0)
            {
                curn++;
                curw=(curw*bn)%mod;
                continue;
            }

            if(bn==0)
            {
                curn++;
                curw=(curw*fn)%mod;
                continue;
            }

            if(fn==1&&bn==1)
            {
                curn++;
                curw=(curw*2)%mod;
                continue;
            }

            curn+=2;
            lli s=min(fn,bn);
            lli d=max(fn,bn)-s;
            curw*=s*(s-1+d)%mod;
            curw%=mod;
        }
        
        if(ansmx==curn)
        {
            ansmj=(ansmj+curw)%mod;
        }
        else if(ansmx<curn)
        {
            ansmx=curn;
            ansmj=curw;
        }
        dbg(i,curn,curw);
    }

    ansmj%=mod;
    ansmj+=mod;
    ansmj%=mod;
    
    cout<<ansmx<<" "<<ansmj<<endl;
}   aryanc403();
    return 0;
}