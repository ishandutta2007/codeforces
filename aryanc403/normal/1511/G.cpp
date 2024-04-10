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
const lli L = 19;
const lli N = 4LL<<L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,q;
    string s;
    vi ans;
    vii qur;
    lli pref[N],a[N];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void solve(lli bt){
    for(lli i=N-1;i>=0;--i){
        pref[i]=a[i];
        if(i+2*bt<N)
            pref[i]+=pref[i+2*bt];
    }
    for(lli i=1;i<N;++i){
        pref[i]+=pref[i-1];
    }

    auto getSum=[&](lli l,lli r) -> lli{
        r=min(r-1,N-1);
        if(l==0)
            return pref[r];
        return pref[r]-pref[l-1];
    };

    auto get=[&](lli l,lli r) -> lli{
        const lli i=(r-l)/bt;
        if(i&1){
            return getSum(r,l+i*bt+bt)+getSum(l+i*bt+2*bt,r+2*bt);
        }
        else{
            return getSum(l+i*bt+bt,l+i*bt+2*bt);
        }
    };

    for(int i=0;i<q;++i){
        const lli l=qur[i].X,r=qur[i].Y;
        const lli c=get(l,l)^get(l,r);
        ans[i]^=(c&1)*bt;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    fo(i,n)
    {
        cin>>in;
        a[in]^=1;
    }

    cin>>q;
    ans.resize(q);
    fo(i,q){
        cin>>l>>r;
        r++;
        qur.pb({l,r});
    }

    for(lli bt=0;bt<L;++bt)
        solve(1LL<<bt);

    for(auto x:ans)
        cout<<(x?"A":"B");
    cout<<endl;

}   aryanc403();
    return 0;
}