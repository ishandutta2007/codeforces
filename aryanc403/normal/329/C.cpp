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

mytype aryanc()
{
    clock_t time_tt=clock()-time_p;
    return (time_tt)/(mytype)CLOCKS_PER_SEC;
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
const lli maxN = 100000L;
const mytype TL = 1.5;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    set<ii> e,e1;
    map<lli,lli> deg;
    vii ans1,ans;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool solve()
{
    if(aryanc()>TL)
    {
        cout<<-1<<endl;
        exit(0);
    }

    deg.clear();
    ans1.clear();
    e1.clear();

    repA(i,1,n)
    {
        e1.insert({i,i});
        deg[i]=2;
    }

    shuffle(a.begin(),a.end(),rng);
    dbg(a);

    while((lli)ans1.size()!=m)
    {
        bool fl=true;

        for(auto u:deg)
        {
            for(auto v:deg)
            {
                ii x={a[u.X-1],a[v.X-1]};
                if(e.find(x)==e.end()&&e1.find(x)==e1.end())
                {
                    ans1.pb(x);
                    del(deg,u.X);
                    del(deg,v.X);
                    e1.insert(x);
                    swap(x.X,x.Y);
                    e1.insert(x);
                    fl=false;
                    break;
                }
            }

            if(!fl)
                break;
        }

        if(fl)
            return true;
    }

    return false;
}

bool solve2()
{
    dbg(aryanc());
    if(aryanc()>TL)
    {
        cout<<-1<<endl;
        exit(0);
    }

    shuffle(a.begin(),a.end(),rng);
    dbg(a);

    lli i;
    fo(i,m)
    {
        if(e.find({a[i],a[(i+1)%n]})!=e.end())
            return true;
    }

    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n>>m;
    fo(i,m)
    {
        cin>>u>>v;
        ans.pb({u,v});
        e.insert({u,v});
        e.insert({v,u});
    }

    if(n*(n-1)<4*m)
    {
        cout<<-1<<endl;
        return 0;
    }

    repA(i,1,n)
        a.pb(i);

    // if(n<=6)
    // {
    //     while(solve());
    //     for(auto x:ans1)
    //         cout<<x.X<<" "<<x.Y<<endl;
    // }
    // else
    {
        while(solve2());
        fo(i,m)
        {
            cout<<a[i]<<" "<<a[(i+1)%n]<<endl;
        }
    }

}   aryanc403();
    return 0;
}