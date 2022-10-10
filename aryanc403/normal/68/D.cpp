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

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,q,h;
    string s;
    map<lli,lli> a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void add(lli x,lli v)
{
    if(v==0)
        return;
    while(x)
    {
        a[x]+=v;
        x/=2;
    }
}

lli get(lli x)
{
    auto it=a.find(x);
    if(it==a.end())
        return 0;
    return it->Y;
}

mytype fnd(lli h)
{
    mytype ans=0;
    lli v=1,mx=0,x,y,t=get(1),H=h;
    h--;
    while(h>=0)
    {
        x=get(2*v);
        y=get(2*v+1);
        dbg(x,y);
        if((x==y)||(t-x<=mx&&t-y<=mx))
        {
            ans+=2*max({mx,t-x,t-y})*(mytype)(1LL<<h);
            break;
        }
        else if(x>y)
        {
            dbg(mx,t,x,y,"left",max(mx,t-y)*(1LL<<h));
            ans+=max(mx,t-y)*(1LL<<h);
            mx=max(mx,t-x);
            t=x;
            v*=2;
        }
        else
        {
            // dbg(mx,t,x,y,"right",max(mx,t-x)*(1LL<<h));
            ans+=max(mx,t-x)*(1LL<<h);
            mx=max(mx,t-y);
            t=y;
            v=2*v+1;
        }
        h--;
    }

    if(h==-1)
    {
        ans+=max(mx,t);
        // dbg(mx,"Hello");
    }
    ans/=(1LL<<H);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>h>>q;

    while(q--)
    {
        cin>>s;
        if(s=="add")
        {
            cin>>x>>y;
            add(x,y);
        }
        else
            cout<<std::fixed<<std::setprecision(6)<<fnd(h)<<endl;
    }

}   aryanc403();
    return 0;
}