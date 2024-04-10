/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
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
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

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
const lli N = 150000LL+5;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;

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

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,ans;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int subtree[N], parentcentroid[N];
vector<set<int>> g;
int nodes;

void dfs(int k, int par)
{
	nodes++;
	subtree[k]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
}

int centroid(int k, int par)
{
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		if(subtree[it]>(nodes>>1))
			return centroid(it, k);
	}
	return k;
}

void dfs3(lli u, lli p,cht &cur1,vii &cur2,lli val1,lli sum,lli h,lli sumrt,lli valrt)
{
    h++;
    sum+=a[u];
    val1+=sum;
    cur1.addLine(-h,-val1);
    valrt+=a[u]*(h+1);
    sumrt+=a[u];
    cur2.pb({sumrt,valrt});
    for(auto x:g[u])
        if(x!=p)
            dfs3(x,u,cur1,cur2,val1,sum,h,sumrt,valrt);
}

vector<cht> curS;
vector<vii> curqurS;

void combine(lli l,lli r)
{
    auto &cur=curS[l];
    auto &cld=curS[r];
    auto &curqur=curqurS[l];
    auto &cldqur=curqurS[r];
    
    for(auto x:cldqur)
        ans=max(ans,-cur.getBest(x.X)+x.Y);

    for(auto x:curqur)
        ans=max(ans,-cld.getBest(x.X)+x.Y);

    if(sz(cldqur)>sz(curqur))
        curqur.swap(cldqur);

    if(sz(cld.hull)>sz(cur.hull))
        cur.hull.swap(cld.hull);

    for(auto x:cld.hull)
        cur.addLine(x.a,x.b);
    
    for(auto x:cldqur)
        curqur.pb(x);
}

void solve(lli l,lli r)
{
    dbg(l,r);
    if(l==r)
        return;
    const lli m=(l+r)/2;
    solve(l,m);
    solve(m+1,r);
    combine(l,m+1);
}

void dfs2(lli rt)
{
    const lli n=sz(g[rt]);
    if(n==0)
        return;    
    curS.clear();curS.resize(n);
    curqurS.clear();curqurS.resize(n);
    
    lli i=0;
    for(auto x:g[rt])
    {
        dfs3(x,rt,curS[i],curqurS[i],0,0,0,a[rt],a[rt]);
        i++;
    }
    assert(n>=1);
    solve(0,n-1);
}

lli decompose(int k, int par)
{
	nodes=0;
	dfs(k, k);
	int node=centroid(k, k);
	parentcentroid[node]=par;
    
    dfs2(node);
    
	for(auto it:g[node])
	{
		g[it].erase(node);
		decompose(it, node);
	}

    return node;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n;
    g.resize(n+1);
    a.pb(0);
    
    fo(i,n-1)
    {
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    if(n==2)
    {
        cout<<a[1]+a[2]+max(a[1],a[2])<<endl;
        return 0;
    }

    decompose(1,-1);

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}