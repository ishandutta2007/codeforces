#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    ll s,a,b,c;
    cin>>s>>a>>b>>c;
    s /= c;
    ll res = (s/a) * (a+b);
    res += s % a;
    cout<<res<<'\n';
}

void b(){
    ll n,m;
    cin>>n>>m;
    ll a,b;
    if(m*2 >= n) a = 0;
    else a = n-2*m;

    b = 0;
    while(b*(b-1) < 2*m) b++;
    b = n-b;

    cout<<a<<' '<<b<<'\n';
}

void c(){
    ll n,k;
    cin>>n>>k;
    vll h(n);
    F0(i,n) cin>>h[i];
    sort(todo(h));
    reverse(todo(h));
    int res = 0;
    int i = 0; //intervalo [0..i] miden h[i]
    ll alt = h[0];
    while(i < n and h[i] == alt) i++;
    while(i < n){
        ll corto = 0;

        while(true){
            while(i < n and h[i] == alt) i++;
            if(corto + (ll) i <= k){
                corto += (ll) i;
                alt--;
            }
            else break;
        }

        res++;
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    c();
    return 0;
}