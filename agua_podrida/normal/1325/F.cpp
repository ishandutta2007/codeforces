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

void d(){
    ll u,v;
    cin>>u>>v;
    if(u == 0 and v == 0){
        cout<<"0\n";
        return;
    }
    if(u == v){
        cout<<"1\n";
        cout<<u<<'\n';
        return;
    }
    if(v-u >= 0 and (v-u)%2 == 0 and (((v-u)/2) & u) == 0){
        ll b = (v - u)/2;
        ll a = b;
        ll pot = 1;
        F0(i,63){
            if(pot & u) a |= pot;
            pot *= 2;
        }
        cout<<2<<'\n';
        cout<<a<<' '<<b<<'\n';
        return;
    }
    if(v >= u and (v-u)%2 == 0){
        v -= u;
        v /= 2;
        cout<<"3\n";
        cout<<u<<' '<<v<<' '<<v<<'\n';
        return;
    }
    cout<<-1<<'\n';
}

void f(){
    int n,m;
    cin>>n>>m;
    int sq = 1;
    while(sq * sq < n) sq++;
    vector<set<int>> grafo(n+1);
    vi d(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[u].insert(v);
        grafo[v].insert(u);
        d[u]++;
        d[v]++;
    }
    set<pi> porD;
    F1(i,n) porD.insert(mp(d[i],i));
    vb sirven(n+1,true);

    set<int> conjInd;
    while(conjInd.size() < sq and !porD.empty()){
        auto it = porD.begin();
        int nodo = it->second;
        int degree = it->first;
        if(degree >= sq-1) break;
        forall(it2,grafo[nodo]){
            if(sirven[nodo]) sirven[*it2] = false;
            grafo[*it2].erase(nodo);
            porD.erase(mp(d[*it2],*it2));
            d[*it2]--;
            porD.insert(mp(d[*it2],*it2));
        }
        grafo[nodo].clear();
        porD.erase(mp(d[nodo],nodo));
        d[nodo] = 0;
        if(sirven[nodo]) conjInd.insert(nodo);
    }
    if(conjInd.size() == sq){
        cout<<"1\n";
        forall(it,conjInd) cout<<*it<<' ';
        cout<<'\n';
        return;
    }
    int nodo = 1;
    while(d[nodo] < sq-1) nodo++;
    set<int> camino;
    camino.insert(nodo);
    vi res;
    res.pb(nodo);
    while(true){
        bool agregue = false;
        forall(it,grafo[nodo]){
            if(camino.count(*it)) continue;
            agregue = true;
            nodo = *it;
            camino.insert(nodo);
            res.pb(nodo);
            break;
        }
        if(!agregue) break;
    }
    reverse(todo(res));
    F0R(i,res.size()) {
        if(grafo[res[0]].count(res.back())) break;
        res.pop_back();
    }

    cout<<"2\n";
    cout<<res.size()<<'\n';
    F0(i,res.size()) cout<<res[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f();
    return 0;
}