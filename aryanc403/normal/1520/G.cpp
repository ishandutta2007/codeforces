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
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<vi> a;
    lli ans,w;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli solve(lli sx,lli sy){
    auto chk=[&](lli x,lli y){
        return 0<=x&&x<n&&0<=y&&y<m;
    };
    queue<ii> pq;
    vi d(n*m,INF);
    lli mn=INF;
    pq.push({sx*m+sy,0});
    while(!pq.empty()){
        lli u=pq.front().X;
        lli dd=pq.front().Y;
        pq.pop();
        if(d[u]<=dd)
            continue;
        const lli r=u/m,c=u%m;
        if(a[r][c]==-1)
            continue;
        d[u]=dd;
        if(a[r][c])
            mn=min(mn,dd+a[r][c]);
        if(chk(r+1,c))
            pq.push({(r+1)*m+c,dd+w});
        if(chk(r-1,c))
            pq.push({(r-1)*m+c,dd+w});
        if(chk(r,c-1))
            pq.push({r*m+c-1,dd+w});
        if(chk(r,c+1))
            pq.push({r*m+c+1,dd+w});
    }
    if(sx==0&&sy==0)
        ans=min(ans,d[n*m-1]);
    return mn;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>w;
    a.resize(n,vi(m));
    for(auto &v:a)
    for(auto &x:v)
        cin>>x;

    ans=INF;
    const lli cnt1=solve(0,0);
    const lli cnt2=solve(n-1,m-1);
    dbg(cnt1,cnt2);
    ans=min(ans,cnt1+cnt2);
    if(ans>=INF)
        ans=-1;
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}