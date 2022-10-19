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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi b(n);
    F0(i,n) cin>>b[i];

    int megana = 0;
    F0(i,n) if(b[i] == 1 and a[i] == 0) megana++;
    int gano = 0;
    F0(i,n) if(b[i] == 0 and a[i] == 1) gano++;

    if(gano == 0){
        cout<<"-1\n";
        return;
    }
    int res = megana / gano + 1;
    cout<<res<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll dp(1e6);
    vll a(n);
    F0(i,n) cin>>a[i];
    F0(i,n) dp[a[i]+n-i] += a[i];
    ll res = 0;
    for(auto resi : dp) maxi(res,resi);
    cout<<res<<'\n';
}

bool sacarLaMasGrande(string& s){
    char grande = 'z';
    while(grande >= 'a'){
        F0(i,s.size()){
            if(s[i] == grande){
                if((i > 0 and s[i-1] == grande-1) or (i+1 < s.size() and s[i+1] == s[i]-1)){
                    REP(j,i,s.size()-2) s[j] = s[j+1];
                    s.pop_back();
                    return true;
                }
            }
        }
        grande--;
    }
    return false;
}

void c(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    while(sacarLaMasGrande(s));
    int res = n - s.size();
    cout<<res<<'\n';
}

void bfs(vvi& g, vi& d, int origen){
    queue<pi> q;
    q.push({origen,0});
    int nodo,dist;
    while(!q.empty()){
        nodo = q.front().first;
        dist = q.front().second;
        q.pop();
        if(d[nodo] != -1) continue;
        d[nodo] = dist;
        for(auto v : g[nodo]){
            q.push({v,dist+1});
        }
    }
}

vvi g,gc;
int n,m,k;

void d(){
    cin>>n>>m;
    g.resize(n+1);
    gc.resize(n+1);
    int u,v;
    F0(i,m){
        cin>>v>>u;
        gc[u].pb(v);
        g[v].pb(u);
    }
    cin>>k;
    vi p(k);
    F0(i,k) cin>>p[i];
    vi d(n+1,-1);
    bfs(gc,d,p.back());
    vi dpmax(k);

    F0R(i,k-1){
        u = p[i];
        dpmax[i] = dpmax[i+1];
        for(auto v : g[u]) {
            if(d[v] == d[u]-1 and v != p[i+1]) dpmax[i] = dpmax[i+1]+1;
        }
    }

    vi dpmin(k);
    F0R(i,k-1){
        u = p[i];
        dpmin[i] = dpmin[i+1]+1;
        for(auto v : g[u]){
            if(d[v] == d[u]-1 and v == p[i+1]) dpmin[i] = dpmin[i+1];
        }
    }

    cout<<dpmin[0]<<' '<<dpmax[0]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    d();
    return 0;
}