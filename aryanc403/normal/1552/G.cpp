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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;
#define bcnt(x) (__builtin_popcountll(x))
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

    cin>>n>>k;
    vii s,t;
    s.pb({0,(1LL<<n)-1});
    while(k--)
    {
        cin>>m;
        vi a(m);
        lli cur=0;
        for(auto &x:a){
            cin>>x;
            x--;
            cur|=1LL<<x;
        }
        sort(all(a));
        vi b(m+1);
        for(int i=0;i<m;++i)
            b[i+1]=b[i]|(1LL<<a[i]);
        t.clear();
        for(const auto &z:s){
            const lli u=z.X&(~cur),v=z.Y&(~cur);
            const int unassigned=bcnt(z.Y&cur);
            const int one=bcnt(z.X&cur);
            for(int j=one;j<=one+unassigned;++j){
                t.pb({u|b[j],v});
            }
        }
        s.swap(t);
        cerr<<sz(s)<<endl;
    }
    dbg(s);
    bool fl=true;
    {
        set<lli> c;
        c.insert(0);
        for(lli cur=0,j=0;j<n;++j){
            cur|=1LL<<j;
            c.insert(cur);
        }
        lli cur=0,j=0;
        for(const auto &z:s){
            if(!fl)
                break;
            if(z.Y)
                fl=false;
            else if(!c.count(z.X))
                fl=false;
            cur|=1LL<<j;
            j++;
        }
    }
    if(n==1)
        fl=true;
    cout<<(fl?"ACCEPTED":"REJECTED")<<endl;
}   aryanc403();
    return 0;
}