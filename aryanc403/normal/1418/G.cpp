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
typedef lli hl;
typedef pair<pair<hl,hl>,pair<hl,hl>> hii;
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
const lli L = 39;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    vector<hii> hashes,prefHash;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

hl getHash()
{
    hl a=0;
    for(lli i=0;i<L;++i)
        a=a*3+rnd(0,2);
    return a;
}

void getVec(vector<hl> &a,hl n)
{
    for(lli i=0;i<L;++i)
    {
        a.pb(n%3);
        n/=3;
    }
}

hl getXOR(const hl &a1,const hl  &b1)
{
    vector<hl> a,b;
    getVec(a,a1);reverse(all(a));
    getVec(b,b1);reverse(all(b));
    hl ans=0;
    for(lli i=0;i<L;++i)
        ans=ans*3+((a[i]+b[i])%3);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    hashes.resize(n+1);
    for(auto &v:hashes)
    {
        v.X.X=getHash();
        v.X.Y=getHash();
        v.Y.X=getHash();
        v.Y.Y=getHash();
    }

    a.clear();a.reserve(n+1);
    prefHash.resize(n+1);
    a.pb(0);
    prefHash[0]=hashes[0];
    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
        prefHash[i].X.X=getXOR(prefHash[i-1].X.X,hashes[in].X.X);
        prefHash[i].X.Y=getXOR(prefHash[i-1].X.Y,hashes[in].X.Y);
        prefHash[i].Y.X=getXOR(prefHash[i-1].Y.X,hashes[in].Y.X);
        prefHash[i].Y.Y=getXOR(prefHash[i-1].Y.Y,hashes[in].Y.Y);
    }

    vi freq(n+1,0);
    map<hii,lli> hval;
    lli l=0;
    lli ans=0;
    hval[prefHash[0]]++;
    for(lli i=1;i<=n;++i)
    {
        freq[a[i]]++;
        while(l<i&&freq[a[i]]>3)
        {
            hval[prefHash[l]]--;
            l++;
            freq[a[l]]--;
        }
        ans+=hval[prefHash[i]];
        hval[prefHash[i]]++;
    }
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}