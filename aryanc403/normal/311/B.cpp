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
struct line {
    int a;
    long long b;

    line(int _a, long long _b) : a(_a), b(_b) {}

    double intersect(const line &oth) const {
        if(a==oth.a)
            return -INF;
        return 1.0 * (oth.b - b) / (a - oth.a);
    }

    long long at(long long x) {
        return a * x + b;
    }
};

    deque < line >  hull;

    void init(){
    	while(!hull.empty())
            hull.pop_back();
    }

    void addLine(lli a , lli b){
        line cur(a,b);

        lli sz=(lli)hull.size();
        while (sz >= 2 && hull[sz - 2].intersect(cur) > hull[sz - 2].intersect(hull[sz - 1])) {
            hull.pop_back();
            sz--;
        }
        hull.push_back(cur);
    }

    lli getBest(lli x){
        // assert(!hull.empty());
        lli sz=(lli)hull.size();
        if(sz==0)
            return INF;
        while(sz>=2&&hull[0].at(x)>=hull[1].at(x))
        {
            hull.pop_front();
            sz--;
        }
        return hull[0].at(x);
    }
};

const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,p;
    string s;
    vi b,a,prf;
    cht dp[105];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>p;
    b.pb(0);
    b.pb(0);
    fo(i,n-1)
    {
        cin>>in;
        b.pb(b.back()+in);
    }

    fo(i,m)
    {
        lli h,t;
        cin>>h>>t;
        a.pb(t-b[h]);
    }

    n=(lli)a.size();
    a.pb(-INF);
    sort(a.begin(),a.end());
    a[0]=0;
    cnt=0;
    for(auto x:a)
    {
        cnt+=x;
        prf.pb(cnt);
    }

    dp[0].addLine(-a[n],(n+1)*a[n]-prf[n]);

    dbg(a,prf);

    repD(i,n,1)
    repD(j,p,1)
    {
        lli cst=dp[j-1].getBest(i);
        dp[j].addLine(-a[i-1],cst+i*a[i-1]);
        dbg(i,j,cst);
        // dbg(i,j,"added",-a[i-1],cst+i*a[i-1]-prf[i-1]);
    }

    // for(auto x:dp[p].hull)
    //     dbg(x.a,x.b);

    lli ans=INF;
    fo(i,p)
        ans=min(ans,dp[i].getBest(1));
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}