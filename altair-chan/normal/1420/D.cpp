//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define ALL(v) v.begin(), v.end()

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
    return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
    return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
    int sign = 1;
    T ret = 0;
    char c;

    do{
        c = getc();
    }while(c == ' ' || c == '\n');
    if(c == '-')sign = -1;
    else ret = c-'0';
    while(1){
        c = getc();
        if(c < '0' || c > '9')break;
        ret = 10*ret + c-'0';
    }
    return sign * ret;
}

inline void ini(int& x){
    x = getnum<int>();
}

inline void scani(int& x){
    scanf("%d",&x);
}

//end of macro

const ll MOD = 998244353;
inline ll domod(ll x){
    if(abs(x) >= MOD) x %= MOD;
    if(x < 0)x += MOD;
    return x;
}
inline ll addmod(ll a, ll b){
    a += b; if(a >= MOD) a -= MOD; return a;
}
inline ll submod(ll a, ll b){
    a -= b; if(a < 0) a += MOD; return a;
}
inline ll mulmod(ll a, ll b){return (a*b)%MOD;}
inline ll powmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}
inline ll invmod(ll a){ // change this if non-prime modulus
    return powmod(a, MOD-2);
}
inline ll divmod(ll a, ll b){
    return mulmod(a, invmod(b));
}

const int N = 3e5 + 5;

ll fac[N];
ll C(int n, int r){
    return divmod(fac[n], mulmod(fac[r], fac[n-r]));
}

int n,k;
int l[N], r[N];
vii liner; // -x = enter, x = exit

set<int>st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    fac[0] = 1;
    REP(i,1,N-1)fac[i] = mulmod(fac[i-1], i);

    cin>>n>>k;
    REP(i,1,n){
        cin>>l[i]>>r[i];
        liner.pb({l[i], -i});
        liner.pb({r[i], i});
    }

    sort(ALL(liner));

    ll ans = 0;
    for(auto x : liner){
        int i = abs(x.S);
        if(x.S < 0){
            if(st.size() >= k-1){
                ans = addmod(ans, C(st.size(), k-1));
            }
            st.insert(i);
        }else{
            st.erase(i);
        }
    }

    cout << ans << endl;

    return 0;
}