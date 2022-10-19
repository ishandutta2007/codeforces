#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

template <typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p){
    return os << "{" << p.fs << ", " << p.sn << "}";
}

const int MN = 2e5 + 5;
int t, n, m;
vpii adjList[MN];
int par[MN], dep[MN];
vector<pair<pii, int>> remEdges;
bool ans[MN];

void dfs(int n1){
    for(auto [n2, e] : adjList[n1]){
        if(e == par[n1]) continue;
        if(par[n2] == -1){
            par[n2] = e;
            dep[n2] = dep[n1] + 1;
            dfs(n2);
        }
        else if(n1 < n2) remEdges.pb({{n1, n2}, e});
    }
}

void solve(){
    cin >> n >> m;
    FR(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].pb({b, i});
        adjList[b].pb({a, i});
    }

    fill_n(ans, m, 0);
    fill_n(par, n, -1);
    par[0] = -2;
    dfs(0);

    //dbgArr(remEdges, SZ(remEdges));
    assert(SZ(remEdges) <= 3);
    assert(SZ(remEdges) == m-n+1);

    for(auto [p, id] : remEdges) ans[id] = 1;

    if(SZ(remEdges) == 3){
        vi vec;
        for(auto [p, id] : remEdges) vec.pb(p.fs), vec.pb(p.sn);
        UNIQUE(vec);

        assert(SZ(vec) >= 3);
        if(SZ(vec) == 3){
            //cerr << "must swap\n";
            auto [p, id] = remEdges[0];
            auto [a, b] = p;
            ans[id] = 0;
            if(dep[a] < dep[b]) ans[par[b]] = 1;
            else ans[par[a]] = 1;
        }
    }

    FR(i, m) cout << ans[i];
    cout << '\n';

    FR(i, n) adjList[i].clear();
    remEdges.clear();
}

int main(){
    boost();
    cin >> t;
    while(t--){
        solve();
    }
}