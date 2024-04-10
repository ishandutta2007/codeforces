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
#define INF 3e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int n,m;

bool dfs(vvi& grafo, vi& color, int nodo){
    if(color[nodo] == 2) return false;
    if(color[nodo] == 1) return true;
    color[nodo] = 1;
    F0(i,grafo[nodo].size()){
        int otro = grafo[nodo][i];
        if(dfs(grafo,color,otro)) return true;
    }
    color[nodo] = 2;
    return false;
}

bool hayCiclo(vvi& grafo){
    vi color(n+1);
    F1(i,n) if(dfs(grafo,color,i)) return true;
    return false;
}

void dfs2(vvi& grafo, vb& visitado, int nodo){
    if(visitado[nodo]) return;
    visitado[nodo] = true;
    F0(i,grafo[nodo].size()){
        int otro = grafo[nodo][i];
        dfs2(grafo,visitado,otro);
    }
}

void c(){
    cin>>n>>m;
    vvi grafo(n+1),grafor(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[u].pb(v);
        grafor[v].pb(u);
    }

    if(hayCiclo(grafo)){
        cout<<"-1\n";
        return;
    }

    vc res(n+1);
    int cant = 0;
    vb visitado1(n+1,false);
    vb visitado2(n+1,false);
    F1(i,n){
        if(visitado1[i] or visitado2[i]) res[i] = 'E';
        else res[i] = 'A';
        dfs2(grafo,visitado1,i);
        dfs2(grafor,visitado2,i);
    }

    F1(i,n) if(res[i] == 'A') cant++;
    cout<<cant<<'\n';
    F1(i,n) cout<<res[i];
    cout<<'\n';
}

ll cuantos(ll a, ll delta){
    if(a-1 < delta) return 0;
    ll lo = 0;
    ll hi = a;
    while(lo+1 != hi){
        ll mid = (lo+hi)/2;
        if(a - 3*mid*mid - 3*mid - 1 >= delta) lo = mid;
        else hi = mid;
    }
    return hi;
}

bool llegoAK(vll& a, ll k, ll mid){
    F0(i,n) k -= cuantos(a[i],mid);
    return k <= 0;
}

void d(){
    ll k;
    cin>>n>>k;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll lo = -INF;//llego a k
    ll hi = INF;//no llego a k
    while(lo+1 != hi){
        ll mid = (lo+hi)/2;
        if(llegoAK(a,k,mid)) lo = mid;
        else hi = mid;
    }
    ll delta = lo;
    vll b(n);
    vi masChiquitos;
    ll minDelta = INF;
    F0(i,n){
        b[i] = cuantos(a[i],delta);
        k -= b[i];
        if(a[i] - 3*b[i]*b[i] - 3*b[i] - 1 < minDelta){
            minDelta = a[i] - 3*b[i]*b[i] - 3*b[i] - 1;
            masChiquitos.clear();
            masChiquitos.pb(i);
        }
        else if(a[i] - 3*b[i]*b[i] - 3*b[i] - 1 == minDelta) masChiquitos.pb(i);
    }

    while(k < 0){
        k++;
        b[masChiquitos.back()]--;
        masChiquitos.pop_back();
    }

    F0(i,n) cout<<b[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}