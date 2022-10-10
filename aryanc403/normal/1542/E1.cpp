/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
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

lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>mod;
    const lli nInv = n*(n-1)/2;
    vector<vi> dpInv(n+1,vi(nInv+1,0));
    dpInv[0][0]=1;
    for(lli i=1;i<=n;++i){
        lli sum=0;
        const lli mInv = i*(i-1)/2;
        for(lli j=0;j<=mInv;++j){
            sum+=dpInv[i-1][j];
            if(j>=i)
                sum-=dpInv[i-1][j-i];
            sum%=mod;
            dpInv[i][j]=sum;
        }
        dbg(i,dpInv[i]);
    }
    const lli N = n;
    vector<vi> dpDif(n+1,vi(N+2,0));
    for(lli i=1;i<=n;++i){
        const auto &curInv=dpInv[i];
        auto &cur=dpDif[i];
        const lli mInv = i*(i-1)/2;
        lli sum=0;
        for(lli j=N+1;j<=mInv;++j){
            sum+=curInv[j];
            sum%=mod;
        }

        for(lli j=0;j<=mInv;++j){
            cur[N+1]=(cur[N+1]+sum*curInv[j])%mod;
            if(j+N+1<=mInv)
                sum-=curInv[j+N+1];
            sum%=mod;
        }

        for(lli j=0;j<=mInv;++j)
        for(lli k=j;j-k<=N&&k>=0;k--){
            cur[j-k]+=curInv[k]*curInv[j]%mod;
            cur[j-k]%=mod;
        }
        dbg(i,dpDif[i]);
    }

    lli ans=0;
    lli f=1;
    for(lli len=n;len>=1;--len){
        lli cur=0;
        vi dp(N+2);
        dp[N+1]=dpDif[len-1][N+1];
        for(lli i=N;i>=0;i--)
            dp[i]=(dpDif[len-1][i]+dp[i+1]);
        dbg(dp);
        for(lli x=1;x<=len;++x)
        for(lli y=x+1;y<=len;++y){
            cur+=dp[y-x+1];
            cur%=mod;
        }
        dbg(len,f,cur);
        ans+=f*cur;
        ans%=mod;
        f=f*len%mod;
    }
    ans%=mod;
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}