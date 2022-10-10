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
const lli maxN = 2000L;

struct node{
    lli val;
    node *l,*r;
};

node* NODE(lli n=0)
{
    node *nd=(node*)malloc(sizeof(node));
    nd->val=0;
    nd->l=nd->r=NULL;
    return nd;
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,w;
    lli m,q;
    string s;
    lli a[maxN+5][maxN+5];
    bool vis[maxN+5];
    pair<ii,ii> queries[maxN+5];
    vector<pair<ii,lli>> garland[maxN+5];
    vi garInQuery[maxN+5];
    lli ans[maxN+5];
lli lx,ly,rx,ry;

void update(lli x,lli y,lli w)
{
    while(x<=n)
    {
        lli yy=y;
        while(yy<=m)
        {
            a[x][yy]+=w;
            yy+=yy&(-yy);
        }
        x+=x&(-x);
    }
}

lli query(lli x,lli y)
{
    lli ans=0;
    while(x>0)
    {
        lli yy=y;
        while(yy>0)
        {
            ans+=a[x][yy];
            yy-=yy&(-yy);
        }
        x-=x&(-x);
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m>>k;

    repA(i,1,k)
    {
        cin>>l;
        while(l--)
        {
            cin>>x>>y>>w;
            garland[i].pb({{x,y},w});
        }
    }

    cin>>q;
    lli cur=0;
    for(lli qq=1;qq<=q;++qq)
    {
        cin>>s;
        if(s=="SWITCH")
        {
            cin>>i;
            vis[i]=!vis[i];
        }
        else
        {
            cin>>lx>>rx>>ly>>ry;
            cur++;
            queries[cur]={{lx,rx},{ly,ry}};
            repA(i,1,k)
                if(!vis[i])
                    garInQuery[i].pb(cur);
        }
    }

    repA(i,1,k)
    {
        for(auto x:garland[i])
            update(x.X.X,x.X.Y,x.Y);

        for(auto x:garInQuery[i])
            ans[x]+=query(queries[x].Y.X,queries[x].Y.Y)
                    +query(queries[x].X.X-1,queries[x].X.Y-1)
                    -query(queries[x].X.X-1,queries[x].Y.Y)
                    -query(queries[x].Y.X,queries[x].X.Y-1);

        for(auto x:garland[i])
            update(x.X.X,x.X.Y,-x.Y);
    }

    repA(i,1,cur)
        if(queries[i].X.X!=-1)
            cout<<ans[i]<<endl;

    aryanc403();
    return 0;
}