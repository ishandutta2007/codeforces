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
// typedef float mytype;
typedef double mytype;
// typedef long double mytype;
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
const lli maxN = 1000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void addLine(vii &c,ii z)
{
    lli n=sz(c);
    while(n>1)
    {
        ii x=c[n-2],y=c[n-1];
        if((x.Y-y.Y)*(z.X-y.X)>=(y.Y-z.Y)*(y.X-x.X))
            break;
        c.pop_back();
        n--;
    }
    c.pb(z);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cout<<std::setprecision(10);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in+a.back());
    }

    vii c;
    vi dd(n+1,0);

    repD(i,n,1)
    {
        addLine(c,{-i,a[i]});
        lli l=0,r=sz(c);
        while(r-l>1)
        {
            lli mi=(l+r)/2;
            if(  c[mi].X*(c[mi].Y-c[mi-1].Y)+c[mi].Y*(c[mi-1].X-c[mi].X) >= a[i-1]*(c[mi-1].X-c[mi].X)-(c[mi].Y-c[mi-1].Y)*(i-1))
                l=mi;
            else
                r=mi;
        }
        dd[i]=-c[l].X;
    }
    
    i=1;
    while(i<=n)
    {
        j=dd[i];
        const mytype m=(a[j]-a[i-1])/(mytype)(j-i+1);
        while(i<=j)
        {
            // printf("%.9lf\n",m);
            cout<<m<<" ";
            i++;
        }
    }

}   aryanc403();
    return 0;
}