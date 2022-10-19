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

struct coso{
    coso(ll a, char op, ll b) : a(a), op(op), b(b) {}

    ll a;
    char op;
    ll b;
};

vector<coso> res;

int g(ll x){
    int res = -1;
    while(x > 0){
        res++;
        x /= 2;
    }
    return res;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void multiplicar(ll a, ll x){
    ll b = a;
    while(b <= 2e18){
        res.pb(coso(b,'+',b));
        b *= 2;
    }
    if(__builtin_popcount(x) == 1) return;
    int i = 0;
    while((x & (1ll<<i)) == 0) i++;
    ll suma = a*(1ll<<i);
    while(i < 60){
        int j = i+1;
        while(j < 60 and (x & (1ll<<j)) == 0) j++;
        if(j == 60)
            return;
        res.pb(coso(suma,'+',a*(1ll<<j)));
        suma += a*(1ll<<j);
        i = j;
    }
}

void c(){
    ll a;
    cin>>a;
    int bms = g(a);
    ll b = a;
    F0(i,bms) {
        res.pb(coso(b,'+',b));
        b *= 2;
    }
    res.pb(coso(b,'^',a));
    b = b ^ a;
    ll x1,x2,y1,y2,g;
    find_any_solution(a,b,1,x1,y1,g);
    find_any_solution(a,b,0,x2,y2,g);
    while(x1 <= 0 or y1 <= 0 or x2 <= 0 or y2 <= 0){
        x1 += b; x2 += b;
        y1 += a; y2 += a;
    }
    multiplicar(a,x1);
    multiplicar(a,x2);
    multiplicar(b,y1);
    multiplicar(b,y2);

    res.pb(coso(a*x1,'+',b*y1));
    res.pb(coso(a*x2,'+',b*y2));
    res.pb(coso(a*x1+b*y1,'^',a*x2+b*y2));

    cout<<res.size()<<'\n';
    for(auto c : res){
        cout<<c.a<<' '<<c.op<<' '<<c.b<<'\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}