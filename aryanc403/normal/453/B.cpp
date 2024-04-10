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
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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
const lli maxN = 100L;
const lli N = 16L;
const lli A = 53L;
const lli L = 1<<N;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,p,b;
    lli dp[maxN+5][L+5];
    vi bb[L];
    lli msk[A+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void pre(lli n)
{
    for(lli i=2;i<=n;++i)
    {
        bool fl=true;
        for(lli j=2;j*j<=i;j++)
        {
            if(i%j==0)
                fl=false;
        }
        if(fl)
            p.pb(i);
    }
    dbg(p);
    repA(i,1,A)
    {
        repA(j,0,N-1)
            if(i%p[j]==0)
                msk[i]|=1LL<<j;
        bb[msk[i]].pb(i);
    }
}

void solve(lli i)
{
for(lli m=0;m<L;++m)
{
    lli &ans=dp[i][m];
    ans=INF;
    repA(j,1,A)
    {
        if(m&msk[j])
            continue;
        ans=min(ans,abs(j-a[i])+dp[i+1][m|msk[j]]);
    }
}
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    pre(A);
    dbg((lli)p.size());
    cin>>n;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    dbg(a);
    memset(dp,-1,(maxN+5)*(L+5)*sizeof(lli));
    memset(dp[n],0,(L+5)*sizeof(lli));
    repD(i,n-1,0)
        solve(i);
    lli cst=dp[0][0];
    m=0;
    dbg(cst);
    fo(i,n)
    {
        repA(j,1,A)
        {
            if(m&msk[j])
                continue;
            if(dp[i][m]==cst&&dp[i+1][m|msk[j]]==cst-abs(j-a[i]))
            {
                b.pb(j);
                m|=msk[j];
                cst-=abs(a[i]-j);
                break;
            }
        }
        // dbg(i,b,m,cst);
        // assert(j!=A+1);
    }

    for(auto x:b)
        cout<<x<<" ";

}   aryanc403();
    return 0;
}