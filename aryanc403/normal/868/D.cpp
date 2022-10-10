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
const lli L = 9L;

struct node{
    lli l,r;
    lli size;
    node():l(0),r(0),size(0){};
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<pair<string,string>> a;
    vector<vector<lli>> rt;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

vector<node> nodes;

lli NODE(lli cpy)
{
    // assert(0<=cpy&&cpy<sz(nodes));
    nodes.pb(nodes[cpy]);
    return sz(nodes)-1;
}

lli add(lli par,lli val,lli len)
{
    lli nd=NODE(par);
    auto cur=nodes[nd];
    if(len==-1)
    {
        cur.size=1;
        nodes[nd]=cur;
        return nd;
    }

    if(val&(1LL<<len))
        cur.l=add(cur.l,val,len-1);
    else
        cur.r=add(cur.r,val,len-1);
    cur.size=nodes[cur.l].size+nodes[cur.r].size;
    nodes[nd]=cur;
    return nd;
}

void add(vi &rt,const string &s)
{
    const lli n=sz(s);
    for(lli i=0;i<n;++i)
    {
        cnt=0;
        for(lli j=i;j<n&&j-i<L;++j)
        {
            cnt<<=1;
            if(s[j]=='1')
                cnt^=1;
            rt[j-i]=add(rt[j-i],cnt,j-i);
        }        
    }
}

lli merge(lli lf,lli rf,lli size)
{
    if(lf==0||nodes[rf].size==size)
        return rf;
    if(rf==0||nodes[lf].size==size)
        return lf;
    lli cur=NODE(0);
    nodes[cur].l=merge(nodes[lf].l,nodes[rf].l,size>>1);
    nodes[cur].r=merge(nodes[lf].r,nodes[rf].r,size>>1);
    nodes[cur].size=nodes[nodes[cur].l].size+nodes[nodes[cur].r].size;
    return cur;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    // nodes.reserve(1000000);
    nodes.resize(1);

    rt.reserve(300);
    cin>>n;
    a.clear();
    a.pb({"",""});
    rt.pb(vector<lli>(L));

    fo(i,n)
    {
        cin>>s;
        rt.pb(vector<lli>(L));
        add(rt.back(),s);
        const lli nn=min(L,sz(s));
        a.pb({s.substr(0,nn),s.substr(sz(s)-nn)});
    }

    cin>>m;
    while(m--)
    {
        cin>>l>>r;
        a.pb({a[l].X+a[r].X,a[l].Y+a[r].Y});
        auto &u=a.back();
        u.X.resize(min(L,sz(u.X)));
        u.Y=u.Y.substr(max(sz(u.Y)-L,0LL));
        
        rt.pb(vector<lli>(L));
        auto &cur=rt.back();
        for(lli i=0;i<L;++i)
            cur[i]=merge(rt[l][i],rt[r][i],2LL<<i);
        add(cur,a[l].Y+a[r].X);
        lli ans=0;
        for(lli i=0;i<L;++i)
            if(nodes[cur[i]].size==(2LL<<i))
                ans=i+1;
        cout<<ans<<endl;
    }

}   aryanc403();
    return 0;
}