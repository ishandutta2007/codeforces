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

const lli mod = 998244353LL;
// const lli maxN = 1000000007L;
// #include <atcoder/dsu>
// #include <atcoder/modint>
// using namespace atcoder;
// using mint = modint998244353;
// //using mint = modint1000000007;
// std::ostream& operator << (std::ostream& out, const mint& rhs) {
//         return out<<rhs.val();
//     }

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .
using bt = bitset<1000>;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n;
    m=2*n;
    vector<vi> a(m,vi(n));
    for(auto &v:a)
    for(auto &x:v){
        cin>>x;
        x--;
    }

    auto clash = [&](lli x,lli y){
        for(lli i=0;i<n;++i){
            if(a[x][i]==a[y][i])
                return true;
        }
        return false;
    };

    vector<bt> e(m);
    for(lli i=0;i<m;++i)
    for(lli j=0;j<i;++j)
    {
        if(!clash(i,j))
            e[i][j]=e[j][i]=1;
    }


    bt active;
    fo(i,m)
        active[i]=1;

    vi validPermutation;
    lli ans=1;

    while(sz(validPermutation)<n){
        vector<vi> b(n,vi(n));
        for(lli v=0;v<m;++v)
        {
            if(!active[v])
                continue;
            for(lli i=0;i<n;++i){
                b[i][a[v][i]]++;
            }
        }

        lli chose=-1;
        for(lli v=0;v<m;++v)
        {
            if(!active[v])
                continue;
            for(lli i=0;i<n;++i){
                if(b[i][a[v][i]]==1)
                    chose=v;
            }
        }

        if(chose==-1){
            ans=(ans*2)%mod;
            for(lli i=0;i<m;++i){
                if(active[i])
                    chose=i;
            }
        }
        validPermutation.pb(chose);
        active&=e[chose];
        active[chose]=0;
    }
    cout<<ans<<endl;
    sort(all(validPermutation));
    for(auto x:validPermutation)
        cout<<x+1<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}