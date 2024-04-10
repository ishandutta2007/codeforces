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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n;

ll score(vll& a, int m){
    int k = n+m;
    k -= k/4;
    ll res = 100*m;
    k -= m;
    F0R(i,a.size()){
        if(k == 0) break;
        k--;
        res += a[i];
    }
    return res;
}

ll scoreb(vll&a, int m){
    int k = n+m;
    k -= k/4;
    ll res = 0;
    F0R(i,a.size()){
        if(k == 0) break;
        k--;
        res += a[i];
    }
    return res;
}

void c(){
    cin>>n;
    vll a(n),b(n);
    F0(i,n) cin>>a[i];
    F0(i,n) cin>>b[i];
    sort(todo(a)); sort(todo(b));

    if(score(a,0) >= scoreb(b,0)){
        cout<<"0\n";
        return;
    }
    int lo = 0;
    int hi = n;
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(score(a,m) >= scoreb(b,m)) hi = m;
        else lo = m;
    }
    cout<<hi<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}