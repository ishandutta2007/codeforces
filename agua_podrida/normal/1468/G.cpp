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
#define eps 0.000000001
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

struct pto{

    bool operator==(pto p){
        return abs(p.x - x) + abs(p.y - y) < eps;
    }

    pto(ll a, ll b){
        x = a;
        y = b;
    }
    pto(const double &x, const double &y) : x(x), y(y) {}
    pto operator+(pto o){
        return pto(x+o.x,y+o.y);
    }
    pto operator-(pto o){
        return pto(x-o.x,y-o.y);
    }
    double operator*(pto o){
        return x*o.x + y*o.y;
    }
    double operator^(pto o){
        return x*o.y - y*o.x;
    }

    pto operator*(double b){
        return pto(x * b, y * b);
    }

    double x;
    double y;
};

double alfa(pto p1, pto v1, pto p2, pto v2){
    return ((p2-p1) ^ v2) / (v1 ^ v2);
}

double norma2(ll x1, ll y1, ll x2, ll y2){
    x1 -= x2;
    y1 -= y2;
    double res = x1*x1 + y1*y1;
    return sqrt(res);
}

bool paralelos(pto v1, pto v2){
    return abs(v1.x * v2.y - v1.y * v2.x) < eps;
}

void g(){
    int n;
    ll h;
    cin>>n>>h;
    vll x(n),y(n);
    F0(i,n) cin>>x[i]>>y[i];

    double res = 0.0;
    res += norma2(x[n-2],y[n-2],x[n-1],y[n-1]);
    ll xm = x[n-2];
    ll ym = y[n-2];
    F0R(i,n-2){
        if(ang({x[i+1]-x[n-1],y[i+1]-y[n-1]-h},{xm-x[n-1],ym-y[n-1]-h})) {
            xm = x[i+1];
            ym = y[i+1];
        }
        pto p1(x[i],y[i]);
        pto v1(x[i+1]-x[i],y[i+1]-y[i]);
        pto p2(xm,ym);
        pto v2(x[n-1]-xm,y[n-1]+h-ym);
        if((v1 ^ v2) > eps){
            double a = alfa(p1,v1,p2,v2);
            if(a < 0.0) a = 0.0;
            if(a > 1.0) a = 1.0;
            res += norma2(x[i],y[i],x[i+1],y[i+1]) * a;
        }
        else if(abs(v1 ^ v2) < eps) {
            pto v3(x[n-1]-x[i],y[n-1]+h-y[i]);
            if((v3 ^ v2) > -eps) res += norma2(x[i],y[i],x[i+1],y[i+1]);
        }
    }

    cout<<setprecision(9)<<fixed<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    g();
    return 0;
}