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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

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
cin>>T;while(T--)
{

    cin>>m>>k;
    vi a(k);
    for(auto &x:a)
        cin>>x;
    vi b(k);
    iota(all(b),0);
    sort(all(b),[&](const lli &x,const lli &y){
        return a[x]>a[y];
    });

    lli l=-1,r=m+1;
    while(r-l>1){
        lli mid=(l+r)/2;
        if(a[b[0]]<=mid*((mid+1)/2)&&m<=mid*mid-(mid/2)*(mid/2))
            r=mid;
        else
            l=mid;
    }
    n=r;
    cout<<n<<endl;
    dbg(n);
    vector<vi> c(n,vi(n,-1));
    vii aa;

    for(int i=1;i<n;i+=2)
    for(int j=0;j<n;j+=2)
        aa.pb({i,j});

    for(int i=0;i<n;i+=2)
    for(int j=0;j<n;j+=2)
        aa.pb({i,j});

    for(int i=0;i<n;i+=2)
    for(int j=1;j<n;j+=2)
        aa.pb({i,j});

    lli idx=0;
    for(auto cur:b){
        while(a[cur]--){
            const lli x=aa[idx].X,y=aa[idx].Y;
            idx++;
            c[x][y]=cur;
        }
    }

    for(const auto &v:c){
        for(auto x:v)
            cout<<x+1<<" ";
        cout<<endl;
    }
}   aryanc403();
    return 0;
}