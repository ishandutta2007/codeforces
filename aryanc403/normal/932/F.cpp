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
typedef long long int mylong;
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

struct cht{

/*** Ref and Credits
    CHT - https://www.codechef.com/viewsolution/8424830
***/

    struct Line{
	   mylong a;
	   mylong b;
	   mylong val;
	   mytype xLeft;
	   bool type;
	   Line(mylong _a = 0 , mylong _b = 0){
		  a = _a;
		  b = _b;
		  xLeft = -INF;
		  type = 0;
		  val = 0;
	   }
	   mylong valueAt(mylong x) const{
		  return 1LL * a * x + b;
	   }
	   friend bool areParallel(const Line &l1, const Line &l2){
		  return l1.a == l2.a;
	   }
	   friend mytype intersectX(const Line &l1 , const Line &l2){
		  return areParallel(l1 , l2) ? INF : (l2.b - l1.b) / (mytype) (l1.a - l2.a);
	   }
	   bool operator < (const Line &l2) const{
		  if(!l2.type)
			 return a < l2.a;
		  return xLeft > l2.val;
	   }
    };
    set < Line >  hull;
    void init(){
    	hull.clear();
    }
    bool hasPrev(set < Line > :: iterator it){
	   return it != hull.begin();
    }
    bool hasNext(set < Line > :: iterator it){
	   return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3){
	   return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < Line > :: iterator it){
	   return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it){
	   if(!hasNext(it)){
		  return it;
	   }
	   mytype val = intersectX(*it , *next(it));
	   Line buf(*it);
	   it = hull.erase(it);
	   buf.xLeft = val;
	   it = hull.insert(it, buf);
	   return it;
    }
    void addLine(mylong a , mylong b){
        // dbg("add",a,b);
	   Line l3 = Line(a, b);
	   auto it = hull.lower_bound(l3);
	   if(it != hull.end() && areParallel(*it , l3)){
		  if(it -> b > b){
			 it = hull.erase(it);
		  }
		  else{
			 return;
		  }
	   }
	   it = hull.insert(it, l3);
	   if(irrelevant(it)){
		  hull.erase(it);
		  return;
	   }
	   while(hasPrev(it) && irrelevant(prev(it))){
		  hull.erase(prev(it));
	   }
	   while(hasNext(it) && irrelevant(next(it))){
		  hull.erase(next(it));
	   }
	   it = updateLeftBorder(it);
	   if(hasPrev(it)){
		  updateLeftBorder(prev(it));
	   }
	   if(hasNext(it)){
		  updateLeftBorder(next(it));
	   }
    }
    mylong getBest(mylong x){
        // assert(!hull.empty());
        if(hull.empty())
            return INF;
	   Line q;
	   q.val = x;
	   q.type = 1;
	   auto bestLine = hull.lower_bound(q);
	   if(bestLine == hull.end()){
		  return INF;
	   }
	   return bestLine -> valueAt(x);
    }

    void merge(cht o)
    {
        if((lli)hull.size()<(lli)o.hull.size())
            o.hull.swap(hull);
        for(auto x:o.hull)
            addLine(x.a,x.b);
    }

};

const lli maxN=100000;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,dp[maxN+5];
    string s;
    vi a,b,e[maxN+5];

void dfs(lli u,lli p,cht &c)
{
    cht d;
    if(u!=1&&e[u].size()==1)
    {
        dp[u]=0;
        c.addLine(b[u],dp[u]);
        return;
    }

    for(auto x:e[u])
    {
        if(x==p)
            continue;
        d.init();
        dfs(x,u,d);
        c.merge(d);
    }

    dp[u]=c.getBest(a[u]);
    c.addLine(b[u],dp[u]);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);
    b.clear();b.reserve(n+1);
    a.pb(0);b.pb(0);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    fo(i,n)
    {
        cin>>in;
        b.pb(in);
    }

    fo(i,n-1)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }

    cht aa;
    dfs(1,0,aa);

    repA(i,1,n)
        cout<<dp[i]<<" ";

}   aryanc403();
    return 0;
}