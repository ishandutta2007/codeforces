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

void dfs(vvi& grafo, vi& padre, vi& prof,vi& tam, int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        padre[hijo] = nodo;
        prof[hijo] = prof[nodo]+1;
        dfs(grafo,padre,prof,tam,hijo);
        tam[nodo] += tam[hijo];
    }
    tam[nodo]++;
}

void a(){
    int n,k;
    cin>>n>>k;
    k = n-k;
    int u,v;
    vvi grafo(n+1);
    F0(i,n-1){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vi padre(n+1);
    vi prof(n+1);
    prof[1] = 0;
    padre[1] = -1;
    vi tam(n+1);
    dfs(grafo,padre,prof,tam,1);

    priority_queue<pi> q;
    q.push(mp(tam[1]-1,1));
    int elegi = 0;
    ll res = 0;
    while(elegi < k){
        pi p = q.top();
        q.pop();
        int nodo = p.S;
        int dif = p.F;
        res += (ll) dif;
        F0(i,grafo[nodo].size()){
            int hijo = grafo[nodo][i];
            if(hijo == padre[nodo]) continue;
            q.push(mp(tam[hijo]-prof[hijo]-1,hijo));
        }
        elegi++;
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    a();
    return 0;
}