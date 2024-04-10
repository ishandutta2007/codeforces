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
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

const lli bcnt[8]={0,1,1,2,1,2,2,3};
bool chk3(lli x)
{
    return (x==2||x==5);
}

lli solve3(){

    vi dp(8,INF);
    lli i,j,k;
    fo(i,8)
        dp[i]=bcnt[a[0]^i];
    dbg(a);
    dbg(dp);
    repA(i,1,m-1)
    {
        vi cur(8,INF);
        const lli x=a[i];
        fo(j,8)
        fo(k,8)
        {
            if(!chk3(k^j))
                continue;
            cur[j]=min(cur[j],dp[k]+bcnt[j^x]);
        }
        dp=cur;
        dbg(dp);
    }

    lli ans=INF;
    for(auto x:dp)
        ans=min(ans,x);
    return ans;
}


bool chk2(lli x)
{
    return (x==2||x==1);
}

lli solve2(){

    vi dp(4,INF);
    lli i,j,k;
    fo(i,4)
        dp[i]=bcnt[a[0]^i];
    dbg(a);
    dbg(dp);
    repA(i,1,m-1)
    {
        vi cur(4,INF);
        const lli x=a[i];
        fo(j,4)
        fo(k,4)
        {
            if(!chk2(k^j))
                continue;
            cur[j]=min(cur[j],dp[k]+bcnt[j^x]);
        }
        dp=cur;
        dbg(dp);
    }

    lli ans=INF;
    for(auto x:dp)
        ans=min(ans,x);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;

    if(n>=4&&m>=4)
    {
        cout<<-1<<endl;
        return 0;
    }

    bool fl=false;
    if(n>m)
    {
        fl=true;
        a.resize(n,0);
    }
    else
    {
        a.resize(m,0);
    }

    fo(i,n)
    {
        cin>>s;
        // dbg(s);
        fo(j,m)
        {
            // dbg(s[j]);
            if(s[j]=='0')
                continue;
            if(fl)
                a[i]|=1<<j;
            else
                a[j]|=1<<i;
        }
    }

    if(fl)
        swap(n,m);
    if(n<2)
    {
        cout<<0<<endl;
        return 0;
    }
    dbg(n,m,a);
    if(n==2)
        cout<<solve2()<<endl;
    else
        cout<<solve3()<<endl;
}   aryanc403();
    return 0;
}