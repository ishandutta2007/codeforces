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
const lli N = 2000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s[N+5];
    lli dp[2][N+5][N+5];
    lli rst[2][N+5][N+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void add(lli bt[N+5],lli v,lli c)
{
    v++;
    while(v<=N)
    {
        bt[v]=(bt[v]+c)%mod;
        v+=v&(-v);
    }
}

lli query(lli bt[N+5],lli v)
{
    v++;
    lli cnt=0;
    while(v>0)
    {
        cnt=(cnt+bt[v])%mod;
        v-=v&(-v);
    }
    return cnt;
}

lli getR(lli x,lli y)
{
    return query(dp[0][x],y);
    // return dp[0][x][y];
    // lli cnt=0,i;
    // repA(i,0,y)
    //     cnt+=dp[0][x][i];
    // return cnt;
}

void addR(lli row,lli l,lli r,lli v)
{
    add(dp[0][row],l,v);
    add(dp[0][row],r+1,-v);
    // dp[0][row][l]+=v;
    // dp[0][row][r+1]-=v;
    return;
    // lli i;
    // repA(i,l,r)
    //     dp[0][row][i]+=v;
}

lli getC(lli x,lli y)
{
    return query(dp[1][y],x);
    // return dp[1][y][x];
    // lli cnt=0,i;
    // repA(i,0,x)
    //     cnt+=dp[1][y][i];
    // return cnt;
}

void addC(lli col,lli l,lli r,lli v)
{
    add(dp[1][col],l,v);
    add(dp[1][col],r+1,-v);

    // dp[1][col][l]+=v;
    // dp[1][col][r+1]-=v;
    return;
    // lli i;
    // repA(i,l,r)
    //     dp[1][col][i]+=v;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    fo(i,n)     cin>>s[i];
    n--;m--;

    //0 row, 1 col

    repD(i,n,0)
    repD(j,m,0)
    {
        rst[0][i][j]=rst[0][i][j+1]+(s[i][j]=='R');
        rst[1][i][j]=rst[1][i+1][j]+(s[i][j]=='R');
        // dbg(i,j,rst[0][i][j],rst[1][i][j]);
    }

    if(n==0)
    {
        cout<<(rst[0][0][0]==0)<<endl;
        return 0;
    }

    if(m==0)
    {
        cout<<(rst[1][0][0]==0)<<endl;
        return 0;
    }

    addC(0,0,0,1);
    addR(0,0,0,1);

    // dp[0][0][0]=dp[1][0][0]=1;
    // dp[0][0][1]=dp[1][0][1]=-1;

    repA(i,0,n)
    repA(j,0,m)
    {
        lli cnt;
        cnt=getR(i,j);
        // dbg(i,j,"add col",m-rst[0][i][j+1]);
        addC(j,i+1,n-rst[1][i+1][j],cnt);
        cnt=getC(i,j);
        addR(i,j+1,m-rst[0][i][j+1],cnt);
        dbg(i,j,getR(i,j),getC(i,j));
    }

    dbg(getR(n,m)+getC(n,m));
    lli ans=getR(n,m)+getC(n,m);
    ans%=mod;ans+=mod;ans%=mod;
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}