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

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X <= b.X);   }};

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vii a;
    vi b;
    vector<vi> ans;
    priority_queue < ii , vector < ii > , CMP > pp,pn;// min priority_queue .

void prt(bool fl=false)
{
    if(!fl)
    {
        cout<<"NO"<<endl;
        exit(0);
    }

    cout<<"YES"<<endl;
    cout<<(lli)ans.size()<<endl;
    for(const auto &x:ans)
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    exit(0);

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

    repA(i,1,n)
    {
        cin>>in;
        a.pb({in,i});
    }

    sort(a.begin(),a.end(),cmp);

    cnt=0;

    fo(i,n)
    {
        cin>>in;
        b.pb(in);
    }

    sort(b.begin(),b.end());

    fo(i,n)
    {
        in=b[i];
        in-=a[i].X;
        cnt+=in;
        if(in>0)
            pp.push({a[i].X,i});
        if(in<0)
            pn.push({a[i].X,i});
    }

    if(cnt)
        prt();

    while(!pp.empty()&&!pn.empty())
    {
        dbg(a);
        dbg(b);
        auto u=pp.top();pp.pop();
        auto v=pn.top();pn.pop();
        lli mv=min({b[u.Y]-u.X,v.X-b[v.Y],(v.X-u.X)/2});
        dbg(u,b[u.Y],v,b[v.Y],mv);
        if(mv<=0)
            prt();
        ans.pb({a[u.Y].Y,a[v.Y].Y,mv});
        a[u.Y].X+=mv;
        a[v.Y].X-=mv;

        if(b[u.Y]!=a[u.Y].X)
            pp.push({a[u.Y].X,u.Y});
        if(b[v.Y]!=a[v.Y].X)
            pn.push({a[v.Y].X,v.Y});
    }

    prt(true);

}   aryanc403();
    return 0;
}