/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

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
{    return ! ( a.Y <= b.Y);   }};

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
    if(a.X!=b.X)
        return a.X<b.X;
    if(a.Y*b.Y<0)
        return a.Y<b.Y;
    return abs(a.Y)<abs(b.Y);
}

const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,w,ans,t;
    lli m,s,N;
    vector<pair<ii,lli>> a;
    vii ed[100005];
    lli dps[100005],dpt[100005];
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void solve(lli dp[100005],lli u, vii ed[100005])
{
    pq.push({u,0});
    while(!pq.empty())
    {
        auto x=pq.top();pq.pop();
        if(dp[x.X]<=x.Y)
            continue;
        dp[x.X]=x.Y;
        for(auto y:ed[x.X])
            pq.push({y.X,y.Y+x.Y});
    }
}

vii b;
bool def[100005];

void process()
{
    lli i,j;
    fo(i,m)
    {
        auto x=a[i];
        w=dps[x.X.X]+x.Y+dpt[x.X.Y];
        if(w==ans)
        {
            b.pb({dps[x.X.X],i+1});
            b.pb({dps[x.X.X]+x.Y,-i-1});
        }
    }

    sort(b.begin(),b.end(),cmp);
    dbg(b);
    lli cnt=0;
    lli n=(lli)b.size();
    fo(i,n-1)
    {
        if(b[i].Y>0)
            cnt++;
        if(b[i].Y+b[i+1].Y==0&&cnt==1)
            def[b[i].Y-1]=true;
        if(b[i].Y<0)
            cnt--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>s>>t;
    a.clear();a.reserve(m);

    fo(i,m)
    {
        cin>>u>>v>>w;
        a.pb({{u,v},w});
        ed[u].pb({v,w});
    }

    repA(i,1,n)
        dps[i]=dpt[i]=INF;

    solve(dps,s,ed);

    repA(i,1,n)
        ed[i].clear();
    for(auto x:a)
        ed[x.X.Y].pb({x.X.X,x.Y});

    solve(dpt,t,ed);
    ans=dps[t];
    dbg(ans);

    process();

    fo(i,m)
    {
        auto x=a[i];
        w=dps[x.X.X]+x.Y+dpt[x.X.Y];
        // dbg(x,w);
        if(w==ans)
        {
            if(def[i])
                cout<<"YES"<<endl;
            else if(1<x.Y)
                cout<<"CAN "<<1<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(w-ans+1<x.Y)
        {
            cout<<"CAN "<< w-ans+1 <<endl;
        }
        else
            cout<<"NO"<<endl;
    }

}   aryanc403();
    return 0;
}