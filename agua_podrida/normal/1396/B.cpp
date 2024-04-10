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
#define mod 1000000007

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

void a(){
    ll n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    if(n == 1){
        cout<<"1 1\n"<<-a[0]<<"\n1 1\n0\n1 1\n0\n";
        return;
    }
    ll g;
    vll x(n);
    vll y(n);
    F0(i,n-1){
        find_any_solution(n-1,n,-a[i],x[i],y[i],g);
    }
    find_any_solution(1,n,-a[n-1],x[n-1],y[n-1],g);
    cout<<"1 "<<n<<'\n';
    F0(i,n) cout<<y[i]*n<<' ';
    cout<<'\n';
    cout<<"1 "<<n-1<<'\n';
    F0(i,n-1) cout<<x[i]*(n-1)<<' ';
    cout<<'\n';
    cout<<n<<' '<<n<<'\n';
    cout<<x[n-1]<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    if(n == 1) {
        cout<<"T\n";
        return;
    }
    ll suma = 0;
    F0(i,n) suma += a[i];
    ll alta = 0;
    F0(i,n) maxi(alta,a[i]);
    if(alta > suma-alta) {
        cout<<"T\n";
        return;
    }
    if(suma % 2 == 0) cout<<"HL\n";
    else cout<<"T\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}