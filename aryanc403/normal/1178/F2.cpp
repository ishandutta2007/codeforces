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

const lli mod = 998244353LL;
const lli maxN = 500;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b;
    lli dp[2*maxN+5][2*maxN+5];
    lli frst[maxN+5],lst[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli solve(lli l,lli r)
{
    // dbg(l,r);
    if(l>r||r<=0||l>m)
        return 1;

    if(l==r)
        return frst[a[l]]==lst[a[l]];

    lli &ans=dp[l][r];

    if(ans!=-1)
        return ans;
    // dbg(l,r);
    lli i,j;

    lli mn=INF;
    repA(i,l,r)
        mn=min(mn,a[i]);

    if(frst[mn]<l||r<lst[mn])
        return ans=0;

    lli cnt=0;
    i=l;
    while(a[i]!=mn)     i++;

    repA(j,l,i)
        cnt+=(solve(l,j-1)*solve(j,i-1))%mod;
    ans=cnt%mod;

    lli pvr=i;
    i++;
    while(i<=r)
    {
        if(a[i]==mn)
        {
            ans=(ans*solve(pvr+1,i-1))%mod;
            pvr=i;
        }
        i++;
    }

    // dbg("p",l,r,ans);
    cnt=0;
    repA(j,pvr,r)
        cnt+=(solve(pvr+1,j)*solve(j+1,r))%mod;

    cnt%=mod;
    ans=(ans*cnt)%mod;

    dbg(l,r,ans);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    a.clear();a.reserve(m);
    a.pb(0);

    fo(i,m)
    {
        cin>>in;
        a.pb(in);
    }

    a.resize(unique(a.begin(),a.end())-a.begin());

    repA(i,1,n)
        frst[i]=INF;
    m=(lli)a.size();
    m--;
    cnt=0;
    repA(i,1,m)
    {
        in=a[i];
        frst[in]=min(frst[in],i);
        lst[in]=max(lst[in],i);
    }

    if(m>2*n)
    {
        cout<<0<<endl;
        return 0;
    }
    dbg(a,n,m);
    memset(dp,-1,(2*maxN+5)*(2*maxN+5)*sizeof(lli));
    cout<<solve(1,m)<<endl;
}   aryanc403();
    return 0;
}