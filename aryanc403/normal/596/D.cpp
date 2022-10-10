/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#ifdef ARYANC403
    #include "/home/aryan/codes/PastCodes/template/header.h"
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<iostream>
    #include<bits/stdc++.h>
    #define dbg(args...)
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

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
const lli N = 2000;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,h;
    lli m;
    string s;
    vi a,al,ar;
    mytype p,dp[4][N+5][N+5];
    bool vis[4][N+5][N+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli moveLeft(lli l)
{
    if(al[l]!=-1)
        return al[l];
    lli &i=al[l];
    i=l;
    if(a[i+1]-a[i]<h)
        i=moveLeft(i+1);
    return i;
}

lli moveRight(lli r)
{
    if(ar[r]!=-1)
        return ar[r];
    lli &j=ar[r];
    j=r;
    if(a[j]-a[j-1]<h)
        j=moveRight(j-1);
    return j;
}

mytype solve(lli l,lli r,lli msk)
{
    if(r<l)
        return 0;
    mytype &ans=dp[msk][l][r];
    if(vis[msk][l][r])
        return ans;
    ans=0;
    vis[msk][l][r]=true;
    lli lf=0,rt=0;
    if(msk&2)
        lf=min(h,a[l]-a[l-1]-h);
    else
        lf=min(h,a[l]-a[l-1]);

    if(msk&1)
        rt=min(h,a[r+1]-a[r]-h);
    else
        rt=min(h,a[r+1]-a[r]);
    ans+=p*(lf+solve(l+1,r,msk&1));
    ans+=(1-p)*(rt+solve(l,r-1,msk&2));
    lli i=min(r,moveLeft(l));
    if(i==r)
        ans+=(1-p)*(a[i]-a[l]+rt+solve(i+1,r,msk|2));
    else
        ans+=(1-p)*(a[i]-a[l]+h+solve(i+1,r,msk|2));

    lli j=max(l,moveRight(r));
    if(j==l)
        ans+=p*(a[r]-a[j]+lf+solve(l,j-1,msk|1));
    else
        ans+=p*(a[r]-a[j]+h+solve(l,j-1,msk|1));
    ans/=2;
    dbg(msk,l,i,r,j,ans);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>h>>p;
    a.clear();a.reserve(n+2);
    al.resize(n+2,-1);
    ar.resize(n+2,-1);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    a.pb(-INF);a.pb(INF);
    sort(all(a));
    dbg(a);
    cout<<solve(1,n,0)<<endl;
}   aryanc403();
    return 0;
}