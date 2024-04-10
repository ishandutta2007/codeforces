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

// #undef ARYANC403
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
    #define dbg(args...) ;
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
const lli maxN = 100000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,q;
    lli m;
    string s;
    vi a,b;
    lli final[4*maxN+5],lazy[4*maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void upd(lli id,lli l,lli r,lli x)
{
    if(x==-INF)
        return;
    lazy[id]=x;
    final[id]=(r-l+1)*x;
}

void shift(lli id,lli l,lli r)
{
    upd(2*id,l,(l+r)/2,lazy[id]);
    upd(2*id+1,(l+r)/2+1,r,lazy[id]);
    lazy[id]=-INF;
}

lli sum(lli id,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||R<l)
        return 0;
    if(L<=l&&r<=R)
    {
        // dbg(l,r,final[id]);
        return final[id];
    }
    shift(id,l,r);
    lli m=(l+r)/2;
    return sum(2*id,l,m,L,R)+sum(2*id+1,m+1,r,L,R);
}

lli sum(lli l,lli r)
{
    return sum(1,1,n,l,r);
}

void add(lli id,lli l,lli r,lli L,lli R,lli x)
{
    if(l>r||r<L||R<l)
        return;
    if(L<=l&&r<=R)
    {
        upd(id,l,r,x);
        return;
    }
    lli m=(l+r)/2;
    shift(id,l,r);
    add(2*id,l,m,L,R,x);
    add(2*id+1,m+1,r,L,R,x);
    final[id]=final[2*id]+final[2*id+1];
}

lli get(lli i)
{
    return sum(1,1,n,i,i);
}

lli bs(lli x)
// max r such that a[r]<x
{
    lli l=1,r=n+1,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(get(m)>=x)
            r=m;
        else
            l=m;
    }
    return l;
}

void add(lli l,lli x)
{
    // dbg(l,bs(get(l)+x));
    lli v=get(l)+x;
    add(1,1,n,l,bs(v),v);
    return;
}

void built(lli id,lli l,lli r)
{
    if(l>r)
        return;
    if(l==r)
    {
        final[id]=b[l];
        return;
    }
    lli m=(l+r)/2;
    built(2*id,l,m);
    built(2*id+1,m+1,r);
    final[id]=final[2*id]+final[2*id+1];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    fo(i,4*maxN+5)
        lazy[i]=-INF;

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);a.pb(0);
    b.clear();b.reserve(n+1);
    b.pb(0);
    repA(i,1,n)
    {
        cin>>in;
        b.pb(in);
    }

    repA(i,2,n)
    {
        cin>>in;
        a.pb(in+a[i-1]);
        b[i]-=a[i];
        dbg(i,a[i],b[i]);
    }

    repA(i,1,n)
        a[i]+=a[i-1];

    built(1,1,n);

    repA(i,1,n)
        dbg(i,get(i)+a[i]-a[i-1]);

    cin>>q;
    dbg("Queries");
    while(q--)
    {
        cin>>s>>l>>r;

        if(s=="s")
            cout<<sum(l,r)+a[r]-a[l-1]<<endl;
        else
        {
            add(l,r);
            repA(i,1,n)
                dbg(i,get(i)+a[i]-a[i-1]);
            dbg("end");
        }
    }

}   aryanc403();
    return 0;
}