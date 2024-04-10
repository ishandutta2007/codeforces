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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

const int N = 1000;
int lp[N+1];
vector<int> pr;

void criba() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

vll fact(ll n){
    vll res;
    ll x = 2;
    while(x*x <= n){
        while(n % x == 0){
            n /= x;
            res.pb(x);
        }
        x++;
    }
    if(n != 1) res.pb(n);
    return res;
}

ll pot(ll a, ll exp){
    ll res = 1;
    while(exp--) res *= a;
    return res;
}

ll X = 2*3*5*7*11;

ll getgcd(ll a, ll b){
    if(b == 0) return a;
    return getgcd(b,a%b);
}

void f(){
    int i = 0;
    vll res(17);
    F0(q,17){
        ll prod = 1;
        while(pr[i] <= (ll) 1e18 / prod) {
            prod *= pr[i];
            i++;
        }
        cout<<'\n';
        cout<<"? "<<prod<<'\n';
        cin>>res[q];
    }

    vll p;
    F0(j,17) {
        vll f = fact(res[j]);
        for(auto factor : f) p.pb(factor);
    }
    ll gcd;
    ll primos = 1;
    ll exp;
    i = 0;
    while(i < p.size()){
        ll prod = 1;
        int hi = 1;
        while(pot(p[i],hi) <= 1e9) hi++;
        prod *= pot(p[i],hi-1);
        if(i+1 < p.size()) {
            hi = 1;
            while(pot(p[i+1],hi) <= 1e9) hi++;
            prod *= pot(p[i+1],hi-1);
        }
        cout<<"? "<<prod<<'\n';
        cin>>gcd;
        exp = 0;
        while(gcd % p[i] == 0) {
            gcd /= p[i];
            exp++;
        }
        primos *= exp+1;
        if(i+1 < p.size()) {
            exp = 0;
            while(gcd%p[i+1] == 0){
                gcd /= p[i+1];
                exp++;
            }
            primos *= exp+1;
        }
        i += 2;
    }

    cout<<"! "<<max(2*primos,primos+7)<<'\n';

}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    criba();
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}