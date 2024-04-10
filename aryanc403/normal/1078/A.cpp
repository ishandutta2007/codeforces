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
    lli a,b,c;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

mytype dist(mytype x1,mytype y1,mytype x2,mytype y2)
{
    mytype ans=0;
    ans+=(x1-x2)*(x1-x2);
    ans+=(y1-y2)*(y1-y2);
    ans=sqrt(ans);
    return ans;
}

mytype chk(lli x1,lli y1,lli x2,lli y2)
{
    mytype x,y;

    // x1,y1 -> x1,y
    y=(-c-a*x1)/(mytype)b;

    //x2,y2 -> x,y2.
    x=(-c-b*y2)/(mytype)a;
    dbg(x1,y1,x1,y);
    dbg(x2,y2,x,y2);
    dbg(dist(x1,y,x,y2));
    return abs(y1-y)+abs(x2-x)+dist(x1,y,x,y2);
}

mytype chk2(lli x1,lli y1,lli x2,lli y2)
{
    mytype xa,xb;
    xa=(-c-b*y1)/(mytype)a;
    xb=(-c-b*y2)/(mytype)a;
    return abs(x1-xa)+abs(x2-xb)+dist(xa,y1,xb,y2);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    lli x1,x2,y1,y2;

    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;

    mytype ans=abs(x1-x2)+abs(y1-y2);

    if(x1==x2||y1==y2||a==0||b==0)
    {
        cout<<ans<<endl;
        return 0;
    }

    ans=min(ans,chk(x1,y1,x2,y2));
    ans=min(ans,chk(x2,y2,x1,y1));

    ans=min(ans,chk2(x2,y2,x1,y1));
    swap(a,b);
    ans=min(ans,chk2(y2,x2,y1,x1));

    cout<<ans<<endl;

}   aryanc403();
    return 0;
}