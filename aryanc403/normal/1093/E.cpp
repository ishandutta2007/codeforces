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

typedef int lli;
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

const lli INF = 1000000000;

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
  
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    ordered_set f[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli query(lli id,ii lb,ii ub)
{
    lli cnt=0;
    while(id>0)
    {
        cnt+=f[id].order_of_key(ub)-f[id].order_of_key(lb);
        id-=id&(-id);
    }
    return cnt;
}

void update(lli id,ii ol,ii nw)
{
    while(id<=n)
    {
        if(ol.X)
            f[id].erase(f[id].find(ol));
        f[id].insert(nw);
        id+=id&(-id);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    lli q;
    cin>>n>>q;
    a.clear();a.reserve(n);
    map<lli,lli> mm;
    
    repA(i,1,n)
    {
        cin>>in;
        mm[in]=i;
    }

    a.pb(0);
    repA(i,1,n)
    {
        cin>>in;
        a.pb(mm[in]);
        update(i,mp(0,0),mp(a[i],i));
    }

    while(q--)
    {
        cin>>T;
        if(T==1)
        {
            lli lx,rx,ly,ry;
            cin>>lx>>rx>>ly>>ry;
            cout<<query(ry,mp(lx,-INF),mp(rx,INF))-query(ly-1,mp(lx,-INF),mp(rx,INF))<<endl;
        }
        else
        {
            lli x,y;
            cin>>x>>y;
            update(x,mp(a[x],x),mp(a[y],x));
            swap(x,y);
            update(x,mp(a[x],x),mp(a[y],x));
            swap(a[x],a[y]);
        }
    }

}   aryanc403();
    return 0;
}