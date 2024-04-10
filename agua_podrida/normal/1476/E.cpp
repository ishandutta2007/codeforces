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
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

string coso(string s, int bit){
    F0(i,s.size()) if(bit & (1<<i)) s[i] = '_';
    return s;
}

bool compatible(string s, string p){
    F0(i,s.size()) if(s[i] != p[i] and p[i] != '_') return false;
    return true;
}

vi orden;
int n;

bool dfs(vvi& g, vi& visitado, int v){
    if(visitado[v] == 1) return true;
    if(visitado[v] == 2) return false;
    visitado[v] = 1;
    for(auto u : g[v]){
        if(dfs(g,visitado,u)) return true;
    }
    orden.pb(v);
    visitado[v] = 2;
    return false;
}

bool toposort(vvi& g){
    vi visitado(n,0);
    F0(i,n) if(dfs(g,visitado,i)) return false;
    reverse(todo(orden));
    return true;
}

void e(){
    int m,k;
    cin>>n>>m>>k;
    vector<string> p(n),s(m);
    vi mt(m);
    F0(i,n) cin>>p[i];
    F0(i,m) cin>>s[i]>>mt[i];
    F0(i,m) mt[i]--;

    vvi g(n);

    map<string,int> a;
    F0(i,n) a[p[i]] = i;

    F0(i,m){
        if(!compatible(s[i],p[mt[i]])) {
            cout<<"NO\n";
            return;
        }
        F0(bit,(1<<k)){
            string pi = coso(s[i],bit);
            if(a.count(pi) and pi != p[mt[i]]) g[mt[i]].pb(a[pi]);
        }
    }

    if(!toposort(g)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    F0(i,n) cout<<orden[i]+1<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    e();
}