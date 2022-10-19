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

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

bool esCreciente(vll& a){
    F1(i,a.size()-1) if(a[i] < a[i-1]) return false;
    return true;
}

bool vale(int k, vll a){
    ll uno = 1;
    ll sumaMaxima = (1<<k)-1;
    a.back() += sumaMaxima;
    F0R(i,a.size()-1) {
        if(a[i] > a[i+1])
            return false;
        a[i] = min(a[i]+sumaMaxima,a[i+1]);
    }
    return true;
}

void a(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];

    if(esCreciente(a)) {
        cout<<"0\n";
        return;
    }
    int lo = 0;
    int hi = 32;
    while(lo+1 != hi){
        int mid = (lo+hi)/2;
        if(vale(mid,a)) hi = mid;
        else lo = mid;
    }
    cout<<hi<<'\n';
}

int n;

void dfs(vvi& grafo, vi& padre, int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(padre[hijo] != 0) continue;
        padre[hijo] = nodo;
        dfs(grafo,padre,hijo);
    }
}

void resolver(vvi& grafo, vi& padre, vi& valorCamino, unordered_set<int>& pesosUsados, int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        resolver(grafo,padre,valorCamino,pesosUsados,hijo);
    }
    vb disponible(grafo[nodo].size()+1,true);
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        disponible[valorCamino[hijo]] = false;
    }
    int j = 0;
    while(!disponible[j]) j++;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        pesosUsados.insert(j ^ valorCamino[hijo]);
    }
    valorCamino[nodo] = j;
}

void resolverMax(vvi& grafo,vi& padre,int& fMax,int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        resolverMax(grafo,padre,fMax,hijo);
    }
    int hojasHijos = 0;
    F0(i,grafo[nodo].size()) if(grafo[grafo[nodo][i]].size() == 1) hojasHijos++;
    if(hojasHijos > 1) fMax -= hojasHijos-1;
}

void b(){
    cin>>n;
    vvi grafo(n+1);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vi padre(n+1);
    padre[1] = -1;
    dfs(grafo,padre,1);

    unordered_set<int> pesosUsados;
    vi valorCamino(n+1);
    resolver(grafo,padre,valorCamino,pesosUsados,1);
    int fMin = pesosUsados.size();
    int fMax = n-1;
    resolverMax(grafo,padre,fMax,1);
    cout<<fMin<<' '<<fMax<<'\n';
}

void caux(int n){
    vi s;
    set<int> use;
    while(s.size() < n){
        int a = 1;
        while(use.count(a)) a++;
        int b = a+1;
        while(use.count(b) or use.count(a^b)) b++;
        int c = a^b;
        s.pb(a); s.pb(b); s.pb(c);
        use.insert(a); use.insert(b); use.insert(c);
    }
    F0(i,3) cout<<s[i]<<' ';
    cout<<'\n';
    REP(i,3,14) cout<<s[i]<<' ';
    cout<<'\n';
    REP(i,15,62) cout<<s[i]<<' ';
    cout<<'\n';
    REP(i,63,126) cout<<s[i]<<' ';
    cout<<'\n';
}

ll solve(ll n){
    ll m12 = n % 12;
    ll offset = 0;
    if(m12 == 3 or m12 == 8 or m12 == 10) offset = 1;
    else if(m12 == 4 or m12 == 6 or m12 == 11) offset = 2;
    else if(m12 == 5 or m12 == 7 or m12 == 9) offset = 3;
    while(n%12 >= 3) n -= 3;
    if(n < 3)
        return n*4+4+offset;
    ll recursivo = (n/12)*3 - 3 + (n%12);
    return solve(recursivo)*4 + offset;
}

void c(){
    ll n;
    cin>>n;
    if(n <= 3) cout<<n<<'\n';
    else cout<<solve(n-4)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}