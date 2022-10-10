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
// #define endl "\n"

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
    // lli ans;
    bool fl;

//return x-y;
lli sub(lli x,lli y){
    lli ans=0,p=1;
    // dbg(x,y);
    while(x||y){
        lli c=x%k,d=y%k;
        c=(c-d+k)%k;
        ans+=c*p;
        x/=k;y/=k;
        p*=k;
    }
    // dbg(ans);
    return ans;
}

lli add(lli x,lli y){
    lli ans=0,p=1;
    while(x||y){
        lli c=x%k,d=y%k;
        c=(c+d)%k;
        ans+=c*p;
        x/=k;y/=k;
        p*=k;
    }
    return ans;
}

bool query(lli x){
    // dbg(x,y,ans);
    // x^=y;
    if(fl){
        x=sub(y,x);
    } else {
        x=add(y,x);
    }
    fl=!fl;
    y=sub(x,y);
    // {
    //     if(ans==x)
    //         return 1;
    //     ans=sub(x,ans);
    //     return 0;
    // }
    cout<<x<<endl;
    cin>>x;
    if(x==-1)
        exit(0);
    return x;
}

void solve(){
    // n=rnd(1,2e5);k=rnd(2,100);
    cin>>n>>k;
    y=fl=0;
    // ans=rnd(0,n-1);
    // dbg(n,ans);
    // assert(k==2);
    for(lli i=0;i<n;++i){
        if(query(i))
        {
            dbg("solved");
            return;
        }
    }
    assert(false);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{
    solve();
}   aryanc403();
    return 0;
}