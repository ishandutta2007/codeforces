#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void a(){
    int l,r;
    cin>>l>>r;
    if(r < 2*l) cout<<"YES\n";
    else cout<<"NO\n";
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res = 0;
    F1(i,n-1) if(s[i] == s[i-1]) res++;
    res++;
    res /= 2;
    cout<<res<<'\n';
}


void c(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));

    vvi dp(n+1,vi(2*n));
    F1(i,n){
        F0(j,2*n){
            dp[i][j] = INF;
            F0(jp,j){
                mini(dp[i][j],dp[i-1][jp] + abs((jp+1) - a[i-1]));
            }
        }
    }
    cout<<dp[n][2*n-1]<<'\n';
}

int prof(vvi& g, int nodo){
    if(g[nodo].empty()) return 0;
    int res = 1;
    for(auto hijo : g[nodo]) maxi(res,prof(g,hijo) + 1);
    return res;
}

void d(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vvi g(n+1);
    g[1].pb(a[1]);
    int p = 0;
    int i = 2;
    while(i < n){
        while(i < n and a[i] > a[i-1]) {
            g[a[p]].pb(a[i]);
            i++;
        }
        p++;
        if(i < n) g[a[p]].pb(a[i]);
        i++;
    }
    int res = prof(g,1);
    cout<<res<<'\n';
}

int bb(vi& v, int x){
    int hi = v.size()-1;
    int lo = 0;
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(x < v[m]) hi = m;
        else lo = m;
    }
    return hi;
}

int lis(vi& a, int l, int r){
    int res = 0;
    vi coso;
    REP(i,l+1,r-1){
        if(a[i] < a[l]) res++;
        else if(a[i] > a[r]) res++;
        else coso.pb(a[i]);
    }
    int n = coso.size();
    vi dp(n+1,INF);
    dp[0] = -INF;
    F0(i,n){
        int j = bb(dp,coso[i]);
        dp[j] = coso[i];
    }
    int llis = 0;
    F1(i,n) if(dp[i] != INF) llis = i;
    return r - l - 1 - llis;
}

void e(){
    int n,k;
    cin>>n>>k;
    vi a(n+2);
    F1(i,n) cin>>a[i];
    a[0] = -INF;
    F1(i,n) a[i] -= i;
    a[n+1] = INF+10;
    vi b(k+2);
    F1(i,k) cin>>b[i];
    b[0] = 0;
    b[k+1] = n+1;

    F0(i,k+1){
        if(a[b[i+1]] < a[b[i]]) {
            cout<<"-1\n";
            return;
        }
    }

    int res = 0;
    F0(i,k+1) {
        res += lis(a,b[i],b[i+1]);
    }

    cout<<res<<'\n';
}

void f(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));

    vi opciones(n);
    F1(i,n-1){
        opciones[i] = opciones[i-1];
        while(a[opciones[i]]*2 <= a[i]) opciones[i]++;
    }

    vll dpp(n,1);
    vll dp(n);
    int len = 1;
    while(len < n){
        F0(i,n) {
            if(opciones[i] >= len) dp[i] = (dpp[i] * (opciones[i] - len +1)) % mod;
            else dp[i] = 0;
        }
        F1(i,n-1) dpp[i] = (dpp[i] + dpp[i-1]) % mod;
        F0(i,n){
            if(opciones[i] == 0) continue;
            dp[i] += dpp[opciones[i]-1];
            dp[i] %= mod;
        }
        dpp = dp;
        len++;
    }
    ll res = 0;
    F0(i,n) {
        res += dpp[i];
        res %= mod;
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    f();
    return 0;
}