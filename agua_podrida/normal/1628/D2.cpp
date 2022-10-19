#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 1e9+7;
const int INF  = 1e9;
const double eps = 0.00000001;

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi b(n),dp(n+1);
    int mex = 0;
    F0R(i,n){
        dp[a[i]] = 1;
        while(dp[mex]) mex++;
        b[i] = mex;
    }
    int l = 0;
    F0(i,n+1) dp[i] = 0;
    vi res;
    while(l < n){
        mex = 0;
        int r = l;
        while(l == r or (r < n and mex < b[l])){
            dp[a[r]] = 1;
            while(dp[mex]) mex++;
            r++;
        }
        while(l < r){
            dp[a[l]] = 0;
            l++;
        }
        res.pb(mex);
    }
    cout<<res.size()<<'\n';
    for(auto x : res) cout<<x<<' ';
    cout<<'\n';
}

void b(){
    int n;
    cin>>n;
    vector<string> a(n);
    F0(i,n) cin>>a[i];
    F0(i,n){
        if(a[i][0] == a[i].back()){
            cout<<"YES\n";
            return;
        }
    }
    set<string> s,t;
    F0(i,n){
        string b = a[i];
        reverse(todo(b));
        if(s.count(b)) {
            cout<<"YES\n";
            return;
        }
        if(b.size() == 2){
            if(t.count(b)){
                cout<<"YES\n";
                return;
            }
        }
        if(b.size() == 3){
            b.pop_back();
            if(s.count(b)) {
                cout<<"YES\n";
                return;
            }
        }
        s.insert(a[i]);
        if(a[i].size() == 3) a[i].pop_back();
        t.insert(a[i]);
    }
    cout<<"NO\n";
}

int n;

void avanzar(int& i, int& j){
    if(i < n/2){
        if(j >= i and j < n-i-1) j++;
        else if(j < n/2) i--;
        else i++;
    }
    else {
        if(j >= n-i and j <= i) j--;
        else if(j < n/2) i--;
        else i++;
    }
}

void c(){
    cin>>n;
    vvi a(n,vi(n));
    F0(i,n) F0(j,n) cin>>a[i][j];
    int res = 0;
    int it = 0;
    while(it < (n+2)/4){
        int i = 2*it, j = 2*it;
        do{
            res ^= a[i][j];
            avanzar(i,j);
            res ^= a[i][j];
            F0(k,3) avanzar(i,j);
        } while(i != 2*it or j != 2*it);
        it++;
    }
    cout<<res<<'\n';
}

ll powmod(ll a, ll exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b = (b*b) % mod;
    if(exp%2) b = (b*a) % mod;
    return b;
}

ll inv(ll a){
    return powmod(a,mod-2);
}

const int N = 1e6;

ll fact[N+1], invfact[N+1],pot2[N+1];

void precalc(){
    fact[0] = invfact[0] = pot2[0] = 1;
    F1(i,N) fact[i] = (fact[i-1] * (ll) i) % mod;
    F1(i,N) invfact[i] = inv(fact[i]);
    F1(i,N) pot2[i] = pot2[i-1] * 2 % mod;
}

void d1(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vvll dp(n+1,vll(m+1));
    F0(i,n+1){
        F0(j,min(m+1,i+1)){
            if(j == 0) dp[i][j] = 0;
            else if(i == j) dp[i][j] = (ll) i * k % mod;
            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) * inv(2) % mod;
        }
    }
    cout<<dp[n][m]<<'\n';
}

ll comb(int n, int k){
    ll res = fact[n];
    res *= invfact[k];
    res %= mod;
    res *= invfact[n-k];
    res %= mod;
    return res;
}

void d2(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    if(m == 0){
        cout<<"0\n";
        return;
    }
    if(n == m){
        cout<<k * (ll) n % mod<<'\n';
        return;
    }

    ll res = 0;
    int x = m;
    int i = n-m-1;
    int j = i;
    while(x > 0){
        ll sumo = pot2[x-1] * x % mod;
        sumo *= comb(i,j);
        res += sumo;
        res %= mod;
        i++;
        x--;
    }
    res *= k;
    res %= mod;
    res *= inv(pot2[n-1]);
    res %= mod;
    cout<<res<<'\n';
}

int main(){
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) d2();
}