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
const lli maxN = 150000L;
const lli maxC = 27L;

struct node{
    lli a[maxC+2];
    bool fl;

    node(){
        fl=true;
        lli i;
        fo(i,maxC)
            a[i]=0;
    }

    void add(char c,lli x)
    {
        a[c-'a']+=x;
    }

    void add(const node &o)
    {
        lli i;
        fo(i,maxC)
            a[i]+=o.a[i];
    }

    bool isValid()
    {
        return fl;
    }

    lli cost()
    {
        lli i,cnt=0;
        fo(i,maxC-1)
            cnt+=(a[maxC-1]+a[i])*(i+1);
        return cnt;
    }

};

node merge(const node &a,const node &b)
{
    node ans;
    lli x=a.a[maxC-1],y=b.a[maxC-1],m,i;
    ans.fl=(a.fl&&b.fl);

    fo(i,maxC-1)
    {
        m=max(a.a[i],b.a[i]);
        x-=m-a.a[i];
        y-=m-b.a[i];
        ans.a[i]=m;
    }

    if(x<0||y<0||x!=y)
        ans.fl=false;

    ans.a[maxC-1]=min(x,y);
    return ans;
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,q,N;
    string s;
    char c;
    vi e[maxN+5],ee[maxN+5];
    lli id[maxN+5],pp[maxN+5];
    node pn[maxN+5],clds[maxN+5];
    set<lli> heights;

void dfs1(lli u,lli i,lli h)
{
    id[u]=i;

    if(u!=1)
        pn[i].add(s[u],1);

    bool fl=(e[u].size()>1);
    dbg(u,e[u]);

    for(auto x:e[u])
    {
        if(fl)
            dfs1(x,++N,h+1);
        else
            dfs1(x,i,h+1);
    }

    if(fl)
    {
        for(auto x:e[u])
        {
            ee[i].pb(id[x]);
            pp[id[x]]=i;
        }
    }

    if(e[u].empty())
        heights.insert(h);
}

void dfs2(lli u)
{
    if(ee[u].empty())
    {
        clds[u]=pn[u];
        return;
    }

    assert((lli)ee[u].size()==2);
    dfs2(ee[u][0]);
    dfs2(ee[u][1]);
    clds[u]=merge(clds[ee[u][0]],clds[ee[u][1]]);
    clds[u].add(pn[u]);
}

void moveUp(lli u)
{
while(u!=0)
{
    if(ee[u].empty())
    {
        clds[u]=pn[u];
        u=pp[u];
        continue;
    }

    dbg(u,ee[u]);
    assert((lli)ee[u].size()==2);
    clds[u]=merge(clds[ee[u][0]],clds[ee[u][1]]);
    clds[u].add(pn[u]);
    u=pp[u];
}
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>q;
    s="00";

    heights.clear();

    repA(i,2,n)
    {
        cin>>u>>c;
        if(c=='?')
            c='z'+1;
        e[u].pb(i);
        s+=c;
    }

    N=1;
    dfs1(1,1,1);

    dfs2(1);

    dbg(id[1],id[2],id[3],id[4],id[5]);
    dbg(heights);

    while(q--)
    {
        cin>>u>>c;
        dbg(u,c);

        if((lli)heights.size()>1)
        {
            cout<<"Fou"<<endl;
            continue;
        }

        if(c=='?')
            c='z'+1;
        dbg(u,s[u],c)
        pn[id[u]].add(s[u],-1);
        s[u]=c;
        pn[id[u]].add(s[u],1);

        moveUp(id[u]);

        if(!clds[1].isValid())
        {
            cout<<"Fou"<<endl;
            continue;
        }
        cout<<"Shi"<<" "<<clds[1].cost()<<endl;
    }

    aryanc403();
    return 0;
}