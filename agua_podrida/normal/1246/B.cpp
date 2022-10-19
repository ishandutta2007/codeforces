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
#define mod 1000000007

void c(){
    int n,m;
    cin>>n>>m;
    vector<string> t(n);
    F0(i,n) cin>>t[i];
    vvi rocas(n,vi(m));
    F0(i,n) F0(j,m) if(t[i][j] == 'R') rocas[i][j]++;
    F0(i,n) F0(j,m) {
        if(i > 0) rocas[i][j] += rocas[i-1][j];
        if(j > 0) rocas[i][j] += rocas[i][j-1];
        if(i > 0 and j > 0) rocas[i][j] -= rocas[i-1][j-1];
    }

    vvll dp(n,vll(m));
    vvll aux(n,vll(m));
    F0R(i,n){
        F0R(j,m){

        }
        //actualizar aux
    }
}

const int N = 100000;
int lp[N+1];
vector<int> pr;

void eratos(){
    F1(i,N) lp[i] = 0;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

map<int,int> factorizar(int a){
    map<int,int> res;
    while(a != 1) {
        res[lp[a]]++;
        a /= lp[a];
    }
    return res;
}

bool esPot2(int a){
    int p = 1;
    while(p < a) p *= 2;
    return p == a;
}

int lg2(int a){
    int res = 0;
    int p = 1;
    while(p < a) {
        p *= 2;
        res++;
    }
    return res;
}

vpi factorMod(int a, int k){
    map<int,int> f = factorizar(a);
    vpi res;
    for(auto p : f) {
        if(p.second % k) res.pb({p.first,p.second % k});
    }
    return res;
}

vpi darVuelta(vpi& v, int k){
    vpi res;
    for(auto p : v) res.pb({p.first,k-p.second});
    return res;
}

void b(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    F0(i,n) cin>>a[i];
    map<vpi,int> s;
    ll res = 0;
    F0(i,n){
        vpi v = factorMod(a[i],k);
        vpi w = darVuelta(v,k);
        res += (ll) s[w];
        s[v]++;
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    eratos();
    b();
    return 0;
}