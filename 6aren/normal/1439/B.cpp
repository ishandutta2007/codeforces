#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;
const int K = 100;

vector<int> g[N];
int deg[N];
int n, m, k;
int cand[N];
set<ii> ed;

void clean_up() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        deg[i] = 0;
        cand[i] = 0;
    }
    ed.clear();
}



bool checkClique1(vector<int> v) {
    bool ok = 1;
    vector<int> check(n + 1);
    for (int e : v) check[e] = 1;
    
    for (int u : v) {
        int cnt = 0;
        for (int e : g[u]) {
            if (!check[e]) continue;
            cnt++;
        }
        if (cnt != k - 1) ok = 0;
    }

    return ok;
}

bool checkClique2(vector<int> v) {
    bool ok = 1;
    for (int i = 1; i < v.size(); i++) {
        int x = v[i];
        for (int j = i + 1; j < v.size(); j++) {
            int y = v[j];
            if (ed.count({x, y}) == 0) ok = 0;
        }
    }
    return ok;
}

bool checkClique(vector<int> v) {
    if (k < K) return checkClique2(v);
    else return checkClique1(v);
}

vector<int> calc(int bound) {
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) d[i] = deg[i];
    set<ii> s;
    
    for (int i = 1; i <= n; i++) {
        s.insert({d[i], i});
    }

    while (true) {
        if (s.empty()) break;
        ii foo = *s.begin();
        if (foo.x >= bound) break;
        s.erase(foo);
        int u = foo.y;
        d[u] = -1e9;
        for (int e : g[u]) {
            if (d[e] == -1e9) continue;
            s.erase({d[e], e});
            d[e]--;
            s.insert({d[e], e});
        }
    }

    vector<int> res;
    for (ii e : s) res.pb(e.y);
    return res;

}


void solve() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
        ed.insert({u, v});
        ed.insert({v, u});
    }

    if (k == 1) {
        cout << 2 << '\n' << 1 << '\n';
        return;
    }

    vector<int> ans = calc(k);

    if (ans.size()) {
        cout << 1 << ' ' << ans.size() << '\n';
        for (int e : ans) {
            cout << e << ' ';
        }
        cout << '\n';
        return;
    }

    ans = calc(k - 1);
    for (int e : ans) {
        cand[e] = 1;
    }

    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int e : g[i]) {
            if (cand[e]) d[i]++;
        }
    }

    set<ii> s;
    for (int e : ans) s.insert({d[e], e});

    while (true) {
        if (s.size() < k) break;
        auto foo = *s.begin();
        int u = foo.y;
        vector<int> tmp;
        tmp.pb(u);
        for (int v : g[u]) {
            if (cand[v]) tmp.pb(v);
        }
        if (tmp.size() != k) {
            cand[u] = 0;
            s.erase(foo);
            for (int e : g[u]) {
                if (cand[e] == 0) continue;
                s.erase({d[e], e});
                d[e]--;
                s.insert({d[e], e});
            }
            continue;
        }
        if (checkClique(tmp)) {
            cout << 2 << '\n';
            for (int e : tmp) cout << e << " ";
            cout << '\n';
            return;
        } else {
            s.erase(foo);
            cand[u] = 0;
            for (int e : g[u]) {
                if (cand[e] == 0) continue;
                s.erase({d[e], e});
                d[e]--;
                s.insert({d[e], e});
            }
        }
    }
    

    cout << -1 << '\n';
    
}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        solve();
        clean_up();
    }

    return 0;
}