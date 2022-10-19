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
#define todo(v) v.begin(),v.end()
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
double PI = acos(-1.0);
#define fora(e,v) for(auto e : v)
const int mod = 1e9+7;
const ll INF  = 1e18;
const double eps = 0.00000001;

struct pto{

    bool operator<(pto p){
        if(x != p.x) return x < p.x;
        return y < p.y;
    }

    ll x,y;

    bool operator==(pto p){
        return x == p.x and y == p.y;
    }

    pto operator-(pto p){
        return {x-p.x,y-p.y};
    }

    pto operator+(pto p){
        return {x+p.x,y+p.y};
    }

    pto rotar(pto p){
        return {p.x-(y-p.y),p.y+(x-p.x)};
    }

    ll operator*(pto p){
        return x*p.x + y*p.y;
    }
};

void inc(vi& v){
    int i = 0;
    while(i+1 < v.size() and v[i] == 3) v[i] = 0, i++;
    v[i]++;
}

int suma(vi& v){
    int res = 0;
    for(auto x : v) res += x;
    return res;
}

bool haceCuadrado(vector<vector<pto>>& p, vi& cand){
    vector<pto> pc(4);
    F0(i,4) pc[i] = p[i][cand[i]];
    sort(todo(pc));
    if(pc[0] == pc[1]) return false;
    pto a = pc[1] - pc[0];
    pto b = pc[2] - pc[0];
    if(!(pc[0] + a + b == pc[3])) return false;
    pto o = {0,0};
    return a.rotar(o) == b or b.rotar(o) == a;
}

void marmota(){
    vector<vector<pto>> p(4);
    ll x,y,a,b;
    F0(i,4){
        cin>>x>>y>>a>>b;
        p[i].pb({x,y});
        F0(j,3) p[i].pb(p[i].back().rotar({a,b}));
    }
    int res = 16;
    vi cand(4);
    while(cand[3] <= 3){
        if(haceCuadrado(p,cand)) mini(res,suma(cand));
        inc(cand);
    }
    if(res == 16) res = -1;
    cout<<res<<'\n';
}

int main(){
    int n;
    cin>>n;
    while(n--) marmota();
    return 0;
}