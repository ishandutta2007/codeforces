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
#define mod 998244353

int n,m,a,b,c;

vi distancias(vvi& grafo, int nodo){
    vi d(n+1,-1);
    queue<pi> q;
    q.push(mp(nodo,0));
    pi p;
    while(!q.empty()){
        nodo = q.front().F;
        if(d[nodo] != -1) {
            q.pop();
            continue;
        }
        d[nodo] = q.front().S;
        F0(i,grafo[nodo].size()) q.push(mp(grafo[nodo][i],q.front().S+1));
        q.pop();
    }
    return d;
}

void e(){
    cin>>n>>m>>a>>b>>c;
    vll suma(m+1);
    F1(i,m) cin>>suma[i];
    sort(todo(suma));
    F1(i,m) suma[i] += suma[i-1];
    vvi grafo(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }

    vi da = distancias(grafo,a);
    vi db = distancias(grafo,b);
    vi dc = distancias(grafo,c);

    ll res = INF;

    F1(z,n){
        if(da[z]+db[z]+dc[z] > m) continue;
        mini(res,suma[db[z]]+suma[da[z]+db[z]+dc[z]]);
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    F1(x,t) e();
    return 0;
}