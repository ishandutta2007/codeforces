/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
    #undef endl
    const bool db=true;
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
    const bool db=false;
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
    vi bb;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .
lli query(lli t,lli i,lli j,lli x){
    cout<<"? "<<t<<" "<<i+1<<" "<<j+1<<" "<<x<<endl;

    if(db&&t==2){
        const lli ans=min(max(x,bb[i]),max(x+1,bb[j]));
        dbg(ans);
        return ans;
    }
    if(db&&t==1){
        const lli ans = max(min(x,bb[i]),min(x+1,bb[j]));
        dbg(ans);
        return ans;
    }
    cin>>x;
    if(x==-1)
        exit(0);
    return x;
}

lli getOne(vi a){
    while(sz(a)>1)
    {
        const lli x=a.back();a.pop_back();
        const lli y=a.back();a.pop_back();
        if(query(2,x,y,1)==1)
            return x;
        a.pb(y);
    }
    return a[0];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
if(db)
{
    n=5;
    bb.resize(n);
    iota(all(bb),1);
}
cin>>T;while(T--)
{

    // if(db){
        // bb.resize(n);
        // for(auto &x:bb)
        //     cin>>x;
        // dbg(bb);
    // }
    if(!db) {
        cin>>n;
    }
    lli one=-1;
    vi a;
    if(n%2==1)
        a.pb(n-1);
    for(int i=0;i+1<n;i+=2){
        lli g=query(2,i,i+1,1);
        if(g==1){
            one=i;
            break;
        }
        if(g>2)
            continue;
        if(g==2){
            a.pb(i+1);
        }
    }
    if(one==-1)
        one=getOne(a);
    dbg(a,one);
    a.clear();
    a.resize(n);
    a[one]=1;
    for(int i=0;i<n;++i){
        if(i==one)
            continue;
        a[i]=query(1,one,i,n-1);
    }
    dbg(a,bb);
    cout<<"! ";
    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;
    if(db){
        assert(a==bb);
        next_permutation(all(bb));
    }
}   aryanc403();
    return 0;
}