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

//Original Code: https://www.codechef.com/viewsolution/8424830
struct cht{
    struct Line{
	   lli a;
	   lli b;
	   lli val;
	   double xLeft;
	   bool type;
	   Line(lli _a = 0 , lli _b = 0){
		  a = _a;
		  b = _b;
		  xLeft = -INF;
		  type = 0;
		  val = 0;
	   }
	   lli valueAt(lli x) const{
		  return 1LL * a * x + b;
	   }
	   friend bool areParallel(const Line &l1, const Line &l2){
		  return l1.a == l2.a;
	   }
	   friend double intersectX(const Line &l1 , const Line &l2){
		  return areParallel(l1 , l2) ? INF : (l2.b - l1.b) / (double) (l1.a - l2.a);
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
	   double val = intersectX(*it , *next(it));
	   Line buf(*it);
	   it = hull.erase(it);
	   buf.xLeft = val;
	   it = hull.insert(it, buf);
	   return it;
    }
    void addLine(lli a , lli b){
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
    lli getBest(lli x){
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
};

//Problem 1: http://codeforces.com/contest/320/problem/E
//Solution 1: http://codeforces.com/contest/320/submission/40481396

const lli mod = 1000000007L;
const lli maxN = 300000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    cht f[4*maxN+5];
    ii aa[maxN+5];
    lli tout[maxN+5];
    vii qur;

void add(lli id,lli l,lli r,lli L,lli R,ii x)
{
    if(L>R||l>r||r<L||R<l)
        return;
    if(L<=l&&r<=R)
    {
        f[id].addLine(x.X,x.Y);
        return;
    }
    lli m=(l+r)/2;
    add(2*id,l,m,L,R,x);
    add(2*id+1,m+1,r,L,R,x);
}

lli query(lli id,lli l,lli r,lli i,lli x)
{
    if(r<i||i<l)
        return -INF;
    lli ans=-INF;
    lli m=(l+r)/2;
    ans=max(ans,-f[id].getBest(x));
    if(l==r)
        return ans;
    ans=max(ans,query(2*id,l,m,i,x));
    ans=max(ans,query(2*id+1,m+1,r,i,x));
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    repA(i,1,n)
    {
        cin>>T;
        if(T==1)
        {
            cin>>x>>y;
            x*=-1;y*=-1;
            tout[i]=n+1;
            aa[i]={x,y};
        }
        else if(T==2)
        {
            cin>>x;
            tout[x]=i;
        }
        else
        {
            cin>>x;
            qur.pb({i,x});
        }
    }

    repA(i,1,n)
        add(1,1,n,i,tout[i],aa[i]);

    for(auto x:qur)
    {
        lli ans=query(1,1,n,x.X,x.Y);
        if(ans==-INF)
            cout<<"EMPTY SET"<<endl;
        else
            cout<<ans<<endl;
    }

}   aryanc403();
    return 0;
}