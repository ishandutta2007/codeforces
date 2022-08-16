/***************************************** START OF TEMPLATE *********************************************/
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  SPEED           ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT      mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)      for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)      for(ll i = (a); i >= n; i--)
#define  fo(i,n)         for(ll i = 0; i < n; i++)
#define  newl            cout<<"\n";
#define  f               first
#define  s               second
#define  pb              push_back
#define  mp              make_pair
#define  sym(s)          s="#"+s+"#";
#define  sqr(v)          v*v;
#define  all(x)          (x).begin(),(x).end()
#define  alll(x,n)       x+1, x+n+1
#define  uniq(a)         a.resize(unique(a.begin(), a.end()) - a.begin());
#define  mset(x,val)     memset(x,val,sizeof(x))
#define  mset1d(a,n,v)   foo(i,0,n+5)a[i]=v;
#define  mset2d(a,n,m,v) foo(i,0,n+5)foo(j,0,m+5)a[i][j]=v;
#define  deb1(a)         cout<<a<<"\n";
#define  deb2(a,b)       cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)     cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  debp(a)         cout<<a.f<<" "<<a.s<<"\n";
#define  debv(a)         for(auto it: a)cout<<it<<" ";newl;
#define  debm(a)         for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  deb1d(a,n)      foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)    foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}    

template <typename T> 
using  ordered_set =  tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
using  ll          =  long long;
using  ull         =  unsigned long long;
using  ld          =  long double;
using  pll         =  pair<ll,ll>;
using  vll         =  vector<ll>;
using  vpll        =  vector<pll>;

const ld   PI    =  3.14159265358979323846; 
const ll   MOD   =  1e+9+7;
const ll   INF   =  LLONG_MAX;
const int  INFi  =  INT_MAX;
const ll   N     =  1e+6+8;

vll adj[N]; ll vis[N];
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

ll test_cases = 1; randomINIT;

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll n, m;    
string a[N], b[N];

static int base = ((int)1e9+7);
static const int mod = (int)1e9+123; // prime mod of polynomial hashing
vector<int> pow1;        // powers of base modulo mod
vector<ull> pow2;        // powers of base modulo 2^64
// -------------- Variables of class -------------
int pref1[N]; // Hash on prefix modulo mod
ull pref2[N]; // Hash on prefix modulo 2^64

/***************************************** FUNCTION IMPLEMENTATIONS **************************************/
struct PolyHash { 
    // Constructor from string:
    PolyHash(const string& s){
        const int n = s.size(); // Firstly calculated needed power of base:
        pref1[0] = pref2[0] = 0;
        for (int i = 0; i < n; ++i) { // Fill arrays with polynomial hashes on prefix
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }
 
    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return make_pair(hash1, hash2);
    }
};
 
// Init static variables of PolyHash class:
map<pair<int,ull>,ll> cnt;

/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc){
    //input
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sym(a[i]);
    }
    a[0]=a[n+1]=string(m+2,'#');
    for(int i=1; i<=m; i++){
        cin>>b[i];
        sym(b[i]);
    }
    b[0]=b[m+1]=string(n+2,'#');

    // pre calculate hash for string 2;
    for(int k=1; k<=n-m+1; k++){
        string s;
        
        for(int i=1; i<=m; i++){
            for(int j=k; j<k+m && j<=n; j++){
                s += b[i][j];
            }
        }

        PolyHash hs(s);
        pair<int, ull> hash = hs(0,s.size());
        cnt[hash]=k; 
    }

    //finding ans
    for(int k=1; k<=n-m+1; k++){
        string s;
        
        for(int i=k; i<k+m && i<=n; i++){
            for(int j=1; j<=m; j++){
                s += a[i][j];
            }
        }

        PolyHash hs(s);
        pair<int, ull> hash = hs(0,s.size());
        if(cnt.find(hash)!=cnt.end()){
            cout<<k<<" "<<cnt[hash];
            return;
        }
    }
}

int main(){
    SPEED;

    pow1.pb(1); pow2.pb(1);
    while ((int)pow1.size() <= N) {
        pow1.push_back(1LL * pow1.back() * base % mod);
        pow2.push_back(pow2.back() * base);
    }

    //cin>>test_cases;
    foo(i,1,test_cases){
        MAIN(i);
    }
}