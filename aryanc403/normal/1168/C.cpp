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
typedef int lli;
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
    return a.Y>b.Y;
}

const lli mod = 1000000007L;
const lli maxN = 300000L;
const lli logN = 22;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,q;
    string s;
    vi a;
    // vector<pair<lli,ii>> qur,f[4*maxN+5];
    vii f[maxN+5];
    bool ans[maxN+5];
    lli pp[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void sol(lli id,lli l,lli r)
{
    // dbg(l,r,q);

    if(l>=r)
        return;

    lli i,j;
    repA(i,l,r)
        pp[i]=a[i];

    lli m=(l+r)/2,val[logN+5];

    repA(i,0,logN)
        val[i]=0;
    repA(i,m+1,r)
    {
        fo(j,logN)
        {
            if(a[i]&(1LL<<j))
            {
                pp[i]|=pp[val[j]];
                val[j]=i;
            }
        }
    }

    repA(i,0,logN)
        val[i]=0;
    repD(i,m,l)
    {
        fo(j,logN)
        {
            if(a[i]&(1LL<<j))
            {
                pp[i]|=pp[val[j]];
                val[j]=i;
            }
        }
    }

    repA(i,l,m)
    {
        for(auto x:f[i])
        {
            if(x.Y<=m)
                break;
            // ans[x.X]=true;
            if(pp[i]&pp[x.Y])
                ans[x.X]=true;
        }
    }
    // q.clear();
    sol(2*id,l,m);
    sol(2*id+1,m+1,r);
}
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    n=q=maxN;
    cin>>n>>q;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        in=1;
        cin>>in;
        a.pb(in);
    }

    repA(i,1,q)
    {
        x=i;y=i;
        cin>>x>>y;
        f[x].pb({i,y});
    }

    repA(i,1,n)
    {
        sort(f[i].begin(),f[i].end(),cmp);
        dbg(f[i]);
    }
    // dbg(q,qur);
    sol(1,1,n);

    repA(i,1,q)
        cout<<(ans[i]?"Shi":"Fou")<<endl;

}   aryanc403();
    return 0;
}