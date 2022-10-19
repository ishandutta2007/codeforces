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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

const int N = 1000000;
int lp[N+1];
vector<int> pr;

void eratos(){
    F1(i,N) lp[i] = 0;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

map<int,int> factorizar(int a){
    map<int,int> res;
    while(a != 1) {
        res[lp[a]]++;
        a /= lp[a];
    }
    return res;
}

vi factImp(int a){
    map<int,int> f = factorizar(a);
    vi res;
    for(auto p : f) {
        if(p.second % 2) res.pb(p.first);
    }
    return res;
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vvi f(n);
    F0(i,n)
        f[i] = factImp(a[i]);
    sort(todo(f));
    int totalPares = 0;
    int grande = 0;
    int l = 0;
    while(l < n){
        int r = l;
        while(r < n and f[r] == f[l]) r++;
        if((r-l) % 2 == 0 or f[l].empty()) totalPares += r-l;
        maxi(grande,r-l);
        l = r;
    }

    int q;
    ll w;
    cin>>q;
    while(q--){
        cin>>w;
        if(w == 0) cout<<grande<<' ';
        else cout<<max(grande,totalPares)<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    eratos();
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}