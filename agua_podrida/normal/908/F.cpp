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
#define INF 1e15
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

ll pot(ll a, int exp){
    if(exp == 0) return 1;
    ll b = pot(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

ll inv(ll a){
    return pot(a,mod-2);
}

int k;
ll a,b;

ll f(vvll& dp, int i, int j){
    if(j >= k) return j;
    if(i+j >= k){
        ll res = (ll) i + (ll) j + (a+b)*inv(b) - 1ll;
        res %= mod;
        if(res < 0) res += mod;
        return res;
    }
    if(dp[i][j] == -1){
        if(i == 0){
            return f(dp,i+1,j);
        }
        else {
            dp[i][j] = ((f(dp,i+1,j) * a) %mod) * inv(a+b);
            dp[i][j] %= mod;
            dp[i][j] += ((f(dp,i,j+i) * b)%mod) * inv(a+b);
            dp[i][j] %= mod;
        }
    }
    return dp[i][j];
}

void d(){
    cin>>k>>a>>b;
    vvll dp(k+1,vll(k+1,-1));
    ll res = f(dp,0,0);
    cout<<res<<'\n';
}

ll P[51][51];

ll C[51][51];

void c(){
    C[0][0] = 1;
    F1(i,50){
        C[i][0] = 1;
        C[i][i] = 1;
        F1(j,i-1) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}

void p(){
    c();
    F0(i,51) F0(j,51) P[i][j] = 0;
    P[0][0] = 1;
    F1(i,50){
        F1(j,i){
            F1(tam,i){
                P[i][j] += P[i-tam][j-1] * C[i-1][tam-1];
                P[i][j] %= mod;
            }
        }
    }
    F1(i,50){
        F0R(j,50) {
            P[i][j] = (P[i][j] + P[i][j+1]) % mod;
        }
    }
}

void e(){
    int m,n;
    cin>>m>>n;
    vector<string> t(n);
    F0(i,n) cin>>t[i];
    vvi g(m);
    F0(u,m){
        REP(v,u+1,m-1){
            int ig = 0;
            F0(i,n) if(t[i][u] == t[i][v]) ig++;
            if(ig == n) {
                g[u].pb(v);
                g[v].pb(u);
            }
        }
    }
}

int bb(vll& v, ll x){
    if(v.empty()) return 0;
    if(v[0] > x) return 0;
    if(v.back() <= x) return v.size();
    int lo = 0; // <= x
    int hi = (int) v.size()-1; // > x
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(v[m] > x) hi = m;
        else lo = m;
    }
    return hi;
}

ll unir(vll& red, vll& blue, vll& g){
    ll res = 0;
    F0(i,g.size()-1){
        if(i+1 >= g.size()) break;
        int ib = bb(blue,g[i]);
        int jb = bb(blue,g[i+1])-1;
        int ir = bb(red,g[i]);
        int jr = bb(red,g[i+1])-1;

        ll descb = 0;
        if(ib > jb) descb = g[i+1]-g[i];
        else {
            REP(m,ib,jb-1) maxi(descb,blue[m+1]-blue[m]);
            if(ib < blue.size()) maxi(descb,blue[ib]-g[i]);
            if(jb < blue.size()) maxi(descb,g[i+1]-blue[jb]);
        }

        ll descr = 0;
        if(ir > jr) descr = g[i+1]-g[i];
        else {
            REP(m,ir,jr-1) maxi(descr,red[m+1]-red[m]);
            if(ir < red.size()) maxi(descr,red[ir] - g[i]);
            if(jr < red.size()) maxi(descr,g[i+1] - red[jr]);
        }

        res += min(2*(g[i+1]-g[i]),3*(g[i+1]-g[i]) - descb - descr);
    }
    return res;
}

void f(){
    int n;
    cin>>n;
    vll r,b,g;
    char c;
    ll x;
    F0(i,n) {
        cin>>x>>c;
        if(c == 'G') g.pb(x);
        if(c == 'R') r.pb(x);
        if(c == 'B') b.pb(x);
    }

    ll res = 0;
    if(g.empty()){
        if(!r.empty()) res += r.back() - r[0];
        if(!b.empty()) res += b.back() - b[0];
        cout<<res<<'\n';
        return;
    }

    res = unir(r,b,g);
    if(!r.empty() and r[0] < g[0]) res += g[0] - r[0];
    if(!r.empty() and r.back() > g.back()) res += r.back() - g.back();
    if(!b.empty() and b[0] < g[0]) res += g[0] - b[0];
    if(!b.empty() and b.back() > g.back()) res += b.back() - g.back();

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    f();
    return 0;
}