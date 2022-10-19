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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

bool hayVecinosIguales(vvi& g, vi& t, int n){
    F1(i,n){
        vi vecinos(g[i].size());
        F0(j,g[i].size()){
            vecinos[j] = (t[g[i][j]]);
        }
        sort(todo(vecinos));
        if((vecinos.empty() or vecinos[0] != 1) and t[i] != 1) return true;
        if((vecinos.empty() or vecinos[0] != 1) and t[i] == 1) continue;
        int k = 0;
        while(k+1 < vecinos.size() and vecinos[k] + 1 >= vecinos[k+1]) k++;
        if(t[i] != vecinos[k]+1) return true;
    }
    return false;
}

void a(){
    int n,m;
    cin>>n>>m;
    vvi g(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi t(n+1);
    F1(i,n) cin>>t[i];

    if(hayVecinosIguales(g,t,n)){
        cout<<"-1\n";
        return;
    }

    vpi orden;
    F1(i,n) orden.pb(mp(t[i],i));
    sort(todo(orden));

    F0(i,n) cout<<orden[i].second<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    a();
    return 0;
}