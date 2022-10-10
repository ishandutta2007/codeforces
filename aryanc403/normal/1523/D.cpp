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
const int itr=64;
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
const lli logN = 60;
const lli MN = 15;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    lli fhat[1LL<<MN],bc[1LL<<MN];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli n,m,p;
    cin>>n>>m>>p;
    vi a;
    map<lli,lli> sets;
    fo(i,n)
    {
        cin>>s;
        lli msk=0;
        for(lli i=0;i<m;++i){
            if(s[i]=='1')
                msk|=1LL<<i;
        }
        sets[msk]++;
        a.pb(msk);
    }

    for(lli msk=0;msk<(1LL<<MN);++msk)
        bc[msk]=bcnt(msk);

    dbg(a);
    lli ans=0,bcans=0;
    for(lli it=0;it<itr;++it){
        const lli smsk=a[rnd(0,n-1)];
        if(smsk==0)
            continue;

        const lli req=(n+1)/2;
        vi onbts;

        for(lli i=0;i<logN;++i){
            if(smsk&(1LL<<i))
                onbts.pb(i);
        }
        const lli N=sz(onbts);
        dbg(onbts,N);
        const lli lim=(1LL<<N)-1;
        memset(fhat,0,sizeof(fhat));
        // map<lli,lli> sosori,sosfina;
        for(auto x:sets){
            const lli pc=x.X&smsk;
            lli msk=lim;
            for(lli i=0;i<N;++i){
                if(pc&(1LL<<onbts[i]))
                    msk^=1LL<<i;
            }
            fhat[msk]+=x.Y;
        }

        // https://codeforces.com/blog/entry/72488
        // Apply zeta transform
        for(int i = 0; i < N; i++) {
            for(int mask = 0; mask < (1 << N); mask++) {
                if((mask & (1 << i)) != 0) {
                    fhat[mask] += fhat[mask ^ (1 << i)];
                }
            }
        }

        for(lli mas = 0; mas < (1 << N); mas++){
            const lli mask=mas;
            const lli val=fhat[lim^mas];
            // sosfina[mask]+=val;
            if(val<req)
                continue;
            if(bcans>=bc[mask])
                continue;
            lli cur=0;
            for(lli i=0;i<N;++i){
                if(mask&(1LL<<i)){
                    cur|=1LL<<onbts[i];
                }
            }
            ans=cur;
            bcans=bcnt(ans);
        }
        // dbg(sosori);
        // dbg(sosfina);
    }

    dbg(ans);
    string s=string(m,'0');
    for(lli i=0;i<m;++i)
    {
        if(ans&(1LL<<i))
            s[i]='1';
    }

    cout<<s<<endl;
}   aryanc403();
    return 0;
}