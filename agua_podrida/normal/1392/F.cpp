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
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

void f(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll total = 0;
    for(auto hi : a) total += hi;
    vector<int> plano;
    ll hi1 = a[n-1];
    int i = n-2;
    while(i >= 0){
        while(!plano.empty() and a[i] + plano.back()-i <= hi1-1){
            a[i] += plano.back()-i;
            hi1--;
            plano.pop_back();
        }
        if(!plano.empty()){
            plano.back() -= hi1-1-a[i];
            a[i] = hi1-1;
        }
        ll cantVeces = (hi1-1-a[i]) / (n-i);
        a[i] += (n-i-1)*cantVeces;
        hi1 -= cantVeces;

        if(a[i] <= hi1-2) {
            plano.pb(n-2);
            a[i]++;
            plano.back() -= hi1-1-a[i];
            a[i] = hi1-1;
        }
        if(a[i] == hi1) plano.pb(i);
        hi1 = a[i];
        i--;
    }
    vll h(n,1);
    h[0] = 0;
    for(auto j : plano) h[j+1] = 0;
    F1(i,n-1) h[i] += h[i-1];
    ll suma = 0;
    for(auto hi : h) suma += hi;
    F0(i,n) h[i] += (total-suma)/n;

    F0(i,n) cout<<h[i]<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f();
}