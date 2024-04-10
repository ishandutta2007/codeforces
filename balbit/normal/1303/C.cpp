#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define pb push_back
#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) for (int i = 1; i<=n; ++i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT


const int maxn = 200+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

// doable iff it is a series of chains (!)

vector<int> g[maxn];
bool seen[maxn];

string re;

bool dfs(int v, int p) {
    seen[v] = 1; re.pb(v + 'a');
    for (int u : g[v]) {
        if (u == p) continue;
        if (seen[u] || !dfs(u, v)) return 0;
    }
    return 1;
}

string run(){
    string s; cin>>s;
    int n = SZ(s);
    REP(i,26) {
        seen[i] = 0; g[i].clear();
    }
    set<pii> st;
    REP(i, n-1) {
        if (s[i] != s[i+1]) {
            int x = s[i] - 'a', y = s[i+1]-'a';
            if (x > y) swap(x,y);
            st.insert({x,y});
        }
    }
    for (pii p : st) {
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
    }

    REP(i,26) {
        if (SZ(g[i]) > 2) {
            return "";
        }
    }
    re.clear();
    REP(i,26) {
        if (!seen[i] && SZ(g[i]) <= 1) {
            if (!dfs(i, -1)) return "";
        }
    }
    bug(SZ(re));
    if (SZ(re) != 26) return "";
    return re;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    bug(1,2,rnd());

    int t; cin>>t;
    while (t--) {
        string s = run();
        if (s == "") cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl; cout<<s<<endl;
        }
    }

}