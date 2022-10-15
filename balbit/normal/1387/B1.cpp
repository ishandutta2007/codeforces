#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()

#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define endl '\n'
#define bug(...)
#endif // BALBIT


#define IOS() ios::sync_with_stdio(0), cin.tie(0)

const int maxn = 2e5+5;

vector<int> g[maxn];
bool mtch[maxn];
int to[maxn];

void dfs(int v, int p) {
    for (int u : g[v]) {
        if (u != p)
            dfs(u,v);
    }
    if (p != -1) {
        if (!mtch[v] && !mtch[p] ) {
            mtch[v] = mtch[p] = 1;
            to[v] = p; to[p] = v;
        }
    }
}

signed main(){
    IOS();
    bug(1,2);
    int n; cin>>n;
    for (int i = 0; i<n; ++i) to[i] = i;
    for (int i = 0; i<n-1; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    int re = 0;
    dfs(0,-1);
    for (int i = 0; i<n; ++i) {
        if (!mtch[i]) {
            swap(to[i], to[g[i][0]]);
            re += 2;
        }else re++;
    }
    cout<<re<<endl;
    for (int i = 0; i<n; ++i)
        cout<<to[i]+1<<' ';
}