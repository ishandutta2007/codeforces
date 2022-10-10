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
{    return ! ( a.X < b.X || a.X==b.X && a.Y == b.Y);   }};

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
const lli logN = 20L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,q;
    lli m;
    vi a,p;
    lli dp[maxN+5][logN+5];
    lli final[4*maxN+5],pos[maxN+5],nxt[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void pre()
{
    lli i,j,x,y;
    repA(i,1,n)
        nxt[i]=m;
    repA(i,0,logN)
        dp[m][i]=m;

    repD(i,m-1,0)
    {
        x=a[i];
        y=p[(pos[x]+1)%n];
        dbg(x,y);
        nxt[x]=i;
        dp[i][0]=nxt[y];
        repA(j,1,logN)
            dp[i][j]=dp[dp[i][j-1]][j-1];
    }
}

lli find(lli x,lli n)
{
    lli i;
    repA(i,0,logN)
    {
        if(n&(1LL<<i))
            x=dp[x][i];
    }
    return x;
}

void built(lli id,lli l,lli r)
{
    if(l>r)
    {
        final[id]=INF;
        return;
    }
    if(l==r)
    {
        final[id]=find(l,n-1);
        dbg(l,find(l,n-1));
        return;
    }
    lli m=(l+r)/2;
    built(2*id,l,m);
    built(2*id+1,m+1,r);
    final[id]=min(final[2*id],final[2*id+1]);
}

lli query(lli id,lli l,lli r,lli L,lli R)
{
    if(r<L||R<l)
        return INF;
    if(L<=l&&r<=R)
        return final[id];
    lli m=(l+r)/2;
    return min(query(2*id,l,m,L,R),query(2*id+1,m+1,r,L,R));
}

lli query(lli l,lli r)
{
    return query(1,0,m-1,l,r);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>q;
    a.clear();a.reserve(m);
    p.clear();p.reserve(n);

    fo(i,n)
    {
        cin>>in;
        pos[in]=i;
        p.pb(in);
    }

    fo(i,m)
    {
        cin>>in;
        a.pb(in);
    }

    pre();
    built(1,0,m-1);

    while(q--)
    {
        cin>>l>>r;
        l--;r--;
        dbg(query(l,r));
        cout<<(r>=query(l,r));
    }

}   aryanc403();
    return 0;
}