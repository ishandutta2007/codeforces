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
const lli logN = 35L;

struct node{
    bool fl,fr;
    node *l,*r;
    node():fl(false),fr(false),l(NULL),r(NULL){};
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,ans;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli fndh(lli x)
{
    for(lli i=logN;i>=0;i--)
    {
        if(x&(1LL<<i))
            return (1LL<<i);
    }
    assert(false);
}

void add(node *u,lli x)
{
    lli i;
    repD(i,logN,0)
    {
        if(x&(1LL<<i))
        {
            if(u->fr);
            else
            {
                u->fr=true;
                u->r=new node();
            }
            u=u->r;
        }
        else
        {
            if(u->fl);
            else
            {
                u->fl=true;
                u->l=new node();
            }
            u=u->l;
        }
    }
}

lli query(node *u,lli x)
{
    lli i,ans=0;
    repD(i,logN,0)
    {
        if(x&(1LL<<i))
        {
            if(u->fr) u=u->r;
            else
            {
                assert(u->fl);
                ans|=(1LL<<i);
                u=u->l;
            }
        }
        else
        {
            if(u->fl) u=u->l;
            else
            {
                assert(u->fr);
                ans|=(1LL<<i);
                u=u->r;
            }
        }
    }
    return ans;
}

node* merge(node *l,node* r)
{
    if(!l)  return r;
    if(!r)  return l;
    l->fl|=r->fl;
    l->fr|=r->fr;
    l->l=merge(l->l,r->l);
    l->r=merge(l->r,r->r);
    return l;
}

node* solve(lli l,lli r,lli mx=INF)
{
    dbg(l,r);
    if(l>r)
        return new node();
    if(l==r)
    {
        node *rt=new node();
        add(rt,a[l]);
        return rt;
    }

    lli i,cnt=0,m;
    repA(i,l,r-1)
        cnt=max(cnt,a[i]^a[i+1]);
    cnt=fndh(cnt);

    repA(m,l+1,r)
    {
        if(cnt&(a[m-1]^a[m]))
            break;
    }

    auto ll=solve(l,m-1);
    auto rr=solve(m,r);
    cnt=INF;
    repA(i,m,r)
        cnt=min(cnt,query(ll,a[i]));
    ans+=cnt;
    return merge(ll,rr);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n=(lli)a.size();
    solve(0,n-1);
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}