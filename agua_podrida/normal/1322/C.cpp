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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void c(){
    int n,m;
    cin>>n>>m;
    vll c(n+1);
    F1(i,n) cin>>c[i];
    vvi grafo(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[v].pb(u);
    }
    F1(i,n) sort(todo(grafo[i]));
    vector<pair<vi,ll>> juntar;
    F1(i,n){
        if(!grafo[i].empty()) juntar.pb(mp(grafo[i],c[i]));
    }
    sort(todo(juntar));

    vll valores;
    F0(i,juntar.size()){
        if(i > 0 and juntar[i].F == juntar[i-1].F) valores.back() += juntar[i].S;
        else valores.pb(juntar[i].S);
    }

    ll res = 0;
    F0(i,valores.size()) res = gcd(res,valores[i]);
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}