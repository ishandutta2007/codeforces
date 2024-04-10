/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

// #pragma warning(disable:4996)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize ("-ffloat-store")

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

typedef struct _node{
    vi v;
    struct _node *l,*r;
}node;

node *NODE()
{
    node *nd=(node*)calloc(1,sizeof(node));
    (nd->v).clear();
    // dbg(nd->v);
    (nd->v).pb(INF);
    nd->l=nd->r=NULL;
    return nd;
}

const lli N=35LL;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,ans;
    lli m;
    vi a;
    node* root;
    stack<lli> s;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void add(lli x,lli cnt)
{
    lli i;
    node *nd=root;
    repD(i,N,0)
    {
        if(x&(1LL<<i))
        {
            if(nd->r==NULL)
                nd->r=NODE();
            nd=nd->r;
            if(cnt==1)
            {
                assert((nd->v).back()>x);
                (nd->v).pb(x);
            }
            else
            {
                assert((nd->v).back()==x);
                (nd->v).pop_back();
            }
        }
        else
        {
            if(nd->l==NULL)
                nd->l=NODE();
            nd=nd->l;
            if(cnt==1)
            {
                assert((nd->v).back()>x);
                (nd->v).pb(x);
            }
            else
            {
                assert((nd->v).back()==x);
                (nd->v).pop_back();
            }
        }
    }
}

void find(lli x)
{
    node *nd=root;
    lli val=0,i;
    repD(i,N,0)
    {
        if(x&(1LL<<i))
        {
            if(nd->l==NULL)
                nd->l=NODE();
            if((nd->l->v).back()<x)
            {
                val|=(1LL<<i);
                nd=nd->l;
            }
            else
            {
                if(nd->r==NULL)
                    nd->r=NODE();
                nd=nd->r;
            }
        }
        else
        {
            if(nd->r==NULL)
                nd->r=NODE();
            if((nd->r->v).back()<x)
            {
                val|=(1LL<<i);
                nd=nd->r;
            }
            else
            {
                if(nd->l==NULL)
                    nd->l=NODE();
                nd=nd->l;
            }
        }
    }
    dbg(x,val);
    ans=max(ans,val);
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

    root=NODE();
    s.push(INF);

    fo(i,n)
    {
        auto x=a[i];
        find(x);
        while(s.top()<=x)
        {
            add(s.top(),-1);
            // dbg("rmv",s.top());
            s.pop();
        }
        s.push(x);
        // dbg("add",x);
        add(x,1);
        dbg(ans);
    }

    while(!s.empty())   s.pop();
    dbg("Part 2");
    root=NODE();
    s.push(INF);

    repD(i,n-1,0)
    {
        auto x=a[i];
        dbg(i);
        find(x);
        dbg(i);
        while(s.top()<=x)
        {
            add(s.top(),-1);
            dbg("rmv",s.top());
            s.pop();
        }
        s.push(x);
        dbg("add",x);
        add(x,1);
        dbg(ans);
    }

    cout<<ans<<endl;
    dbg("exit");
    return 0;

}   aryanc403();
    return 0;
}