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
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF  = 8e18;
const int inf = 1e9;
const double eps = 0.00000001;

//cout<<"Case #"<<tc<<": ";

struct unionFindPC {
    unionFindPC(int n);
    int find(int i); // pre, el nodo est
    void unite(int s, int t);

    vector<int> set; //en la posicin de cada elemento est su padre
    vector<int> peso; //peso
    vector<int> nxt;
};

unionFindPC::unionFindPC(int n) {
    set = vector<int> (n);
    peso = vector<int> (n, 1);
    nxt = vi(n);
    for(int i = 0; i< n; i++){
        set[i] = i; // al principio cada uno es su propio padre
        nxt[i] = i;
    }
}

int unionFindPC::find(int i) {
    if(set[i] != i)
        set[i] = find(set[i]);
    return set[i];
}

void unionFindPC::unite(int s, int t) {
    int i = find(s);
    int j = find(t);
    if (i == j) return;
    if (peso[i] <= peso[j]) swap(i, j);
    set[j] = i;
    peso[i] += peso[j];
    nxt[i] = max(nxt[i],nxt[j]);
}

void C(){
    int n,m;
    cin>>n>>m;
    vll a(n+1);
    F1(i,n) cin>>a[i];
    ll x;
    F1(i,n) cin>>x, a[i] -= x;
    F1(i,n) a[i] += a[i-1];

    unionFindPC uf(n+2);
    vpi inter(m),listo;
    F0(i,m) cin>>inter[i].first>>inter[i].second,inter[i].first--;
    vvi wake(n+1);
    F0(i,m) {
        wake[inter[i].first].pb(i);
        wake[inter[i].second].pb(i);
    }
    vi ceros(m);
    F0(i,n+1) {
        if(a[i]) continue;
        uf.unite(i,i+1);
        for(auto j : wake[i]) {
            ceros[j]++;
            if(ceros[j] == 2) listo.pb(inter[j]);
        }
    }

    while(!listo.empty()){
        int l = listo.back().first;
        int r = listo.back().second;
        listo.pop_back();
        while(uf.nxt[uf.find(l)] <= r){
            int i = uf.nxt[uf.find(l)];
            uf.unite(i,i+1);
            for(auto j : wake[i]) {
                ceros[j]++;
                if(ceros[j] == 2) listo.pb(inter[j]);
            }
        }
    }

    if(uf.nxt[uf.find(0)] > n) cout<<"YES\n";
    else cout<<"NO\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) C();
}