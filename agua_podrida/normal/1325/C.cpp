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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    cout<<1<<' '<<n-1<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    vi b;
    F0(i,n){
        if(i == 0 or a[i] != a[i-1]) b.pb(a[i]);
    }
    cout<<b.size()<<'\n';
}

void c(){
    int n;
    cin>>n;
    vvi grafo(n+1);
    vpi aristas;
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        if(u > v) swap(u,v);
        grafo[u].pb(v);
        grafo[v].pb(u);
        aristas.pb(mp(u,v));
    }

    vi hojas;
    vi res(n-1,-1);
    F1(i,n) if(hojas.size() < 3 and grafo[i].size() == 1) hojas.pb(i);
    if(hojas.size() == 3){
        F0(i,3){
            u = hojas[i];
            v = grafo[u][0];
            F0(j,n-1) if(aristas[j].F == u or aristas[j].S == u) res[j] = i;
        }
    }

    int val = 3;
    F0(i,n-1){
        if(res[i] == -1){
            if(val >= n-1) val = 0;
            res[i] = val;
            val++;
        }
    }

    F0(i,n-1) cout<<res[i]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    c();
    return 0;
}