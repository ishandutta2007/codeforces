#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n - 2), b(n - 2), c(n - 2), cnt(n + 1, 0);
    vector <int> adj[n + 1];
    map <pii, int> m1;
    set <int> aa[n + 1];
    fop (i,0,n-2) {
        cin >> a[i] >> b[i] >> c[i];
        aa[a[i]].insert(i);
        aa[b[i]].insert(i);
        aa[c[i]].insert(i);
        m1[{a[i], b[i]}]++;
        m1[{b[i], a[i]}]++;
        m1[{a[i], c[i]}]++;
        m1[{c[i], a[i]}]++;
        m1[{b[i], c[i]}]++;
        m1[{c[i], b[i]}]++;
        cnt[a[i]]++; cnt[b[i]]++; cnt[c[i]]++;
    }
    for (auto A : m1) {
        if (A.Y == 1) {
            adj[A.X.X].pb(A.X.Y);
        }
    }
    vector <int> p, q;
    function<void(int, int)> dfs = [&](int v, int pa) {
        p.pb(v);
        if (p.size() == n) return;
        for (int u : adj[v]) if (u != pa) {
            dfs(u, v);
        	if (p.size() == n) return;
        }
    };
    dfs(1, -1);
    set <pii> s1;
    fop (i,1,n+1) s1.insert({cnt[i], i});
    int v, d;
    while (s1.size()) {
        tie(d, v) = *s1.begin(); s1.erase(s1.begin());
        int id = *aa[v].begin();
        q.pb(id);
        aa[a[id]].erase(id);
        aa[b[id]].erase(id);
        aa[c[id]].erase(id);
        s1.erase({cnt[a[id]], a[id]});
        s1.erase({cnt[b[id]], b[id]});
        s1.erase({cnt[c[id]], c[id]});
        cnt[a[id]]--; cnt[b[id]]--; cnt[c[id]]--;
        if (cnt[a[id]]) s1.insert({cnt[a[id]], a[id]});
        if (cnt[b[id]]) s1.insert({cnt[b[id]], b[id]});
        if (cnt[c[id]]) s1.insert({cnt[c[id]], c[id]});
    }
    for (int i : p) cout << i << ' ';
    cout << '\n';
    for (int i : q) cout << i + 1 << ' ';
    cout << '\n';
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}