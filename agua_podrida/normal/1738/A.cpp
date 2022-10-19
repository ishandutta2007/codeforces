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
const ll mod = 1e9+7;
const ll INF  = 8e18;
const int inf = 1e9;
const double eps = 0.00000001;

void a(){
    int n;
    cin>>n;
    vvll a(2);
    vll x(n),y(n);
    F0(i,n) cin>>x[i];
    F0(i,n) cin>>y[i];
    F0(i,n) a[x[i]].pb(y[i]);
    sort(todo(a[0]));
    sort(todo(a[1]));
    ll res = 0;
    if(a[0].size() == a[1].size()){
        res -= min(a[0][0],a[1][0]);
        F0(i,2) for(auto x : a[i]) res += 2*x;
    }
    else {
        if(a[0].size() < a[1].size()) swap(a[0],a[1]);
        //a[0] mas grande
        F0(i,2) for(auto x : a[i]) res += 2*x;
        F0(i,a[0].size() - a[1].size()) res -= a[0][i];
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) a();
}