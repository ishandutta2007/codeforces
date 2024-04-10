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
const double eps = 0.000000001;

void a(){
    int m,k,ap;
    cin>>m>>k;
    vpi a;
    F1(i,k) {
        cin>>ap;
        if(ap) a.pb({ap,i});
    }
    sort(todo(a));
    int f = a.back().first,n = 0;
    while(f > (n+1)/2*n or m > n*n - (n/2)*(n/2)) n++;

    vvi res(n,vi(n));
    if(m == 1) res[0][0] = a.back().second, a.pop_back();
    int i = 0, j = 1;
    while(!a.empty()){
        res[i][j] = a.back().second;
        a.back().first--;
        if(a.back().first == 0) a.pop_back();
        if(j % 2) {
            j += 2;
            if(j >= n) i += 2, j = 1;
        }
        else {
            j += 2;
            if(j >= n) i += 2, j = 0;
        }
        if(i >= n) i = (j+1)%2, j = 0;
    }
    cout<<n<<'\n';
    F0(i,n){
        F0(j,n) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    F1(x,t) a();
    return 0;
}