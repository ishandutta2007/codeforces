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
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

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
#define PI acos(-1.0)

int cuad(pll a){
    if(a.second > 0 or (a.second == 0 and a.first > 0)) return 0;
    return 1;
}

bool ang(pll a, pll b){
    if(cuad(a) != cuad(b)) return cuad(a) < cuad(b);
    return a.second * b.first < a.first * b.second;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void f(){
    int n;
    cin>>n;
    ll x,y,u,v;
    vpll p;
    F0(i,n) {
        cin>>x>>y>>u>>v;
        u -= x;
        v -= y;
        p.pb({u,v});
    }

    sort(todo(p),ang);

    int i2 = 0;
    while(i2 < n and cuad(p[i2]) == 0) i2++;
    map<pll,ll> m;
    while(i2 < n) {
        tie(x,y) = p[i2];
        ll g = gcd(abs(x),abs(y));
        x /= g;
        y /= g;
        m[{-x,-y}]++;
        i2++;
    }

    ll res = 0;
    F0(i,n){
        if(cuad(p[i]) == 1) break;
        tie(x,y) = p[i];
        ll g = gcd(abs(x),abs(y));
        x /= g;
        y /= g;
        res += m[{x,y}];
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}