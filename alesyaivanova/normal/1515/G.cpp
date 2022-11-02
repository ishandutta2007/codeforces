#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
vector<pii> g[maxn];
vector<int> rg[maxn];
int n, m;
bool used[maxn];
int ts[maxn];
int pt;
int comp[maxn];
int d[maxn];
int used1[maxn];
int cur_w[maxn];
bool bad[maxn];

void topsort(int v) {
    used[v] = 1;
    for (pii to : g[v]) {
        if (!used[to.ff])
            topsort(to.ff);
    }
    ts[pt] = v;
    pt--;
}

void update_comp(int v, vector<int>& c) {
    used[v] = 1;
    comp[v] = pt;
    c.pb(v);
    for (int to : rg[v]) {
        if (!used[to]) {
            update_comp(to, c);
        }
    }
}

int find_cycle(int v) {
    used1[v] = 1;
    for (pii to : g[v]) {
        if (comp[to.ff] != comp[v])
            continue;
        if (used1[to.ff] == 1) {
            return cur_w[v] + to.ss - cur_w[to.ff];
        } else if (!used1[to.ff]) {
            cur_w[to.ff] = cur_w[v] + to.ss;
            int ans = find_cycle(to.ff);
            if (ans != -1)
                return ans;
        }
    }
    used1[v] = 2;
    return -1;
}

int check(int v, int x) {
//    cerr << "  " << v + 1 << " " << cur_w[v] << "\n";
    used1[v] = 1;
    for (pii to : g[v]) {
        if (comp[to.ff] != comp[v])
            continue;
        if (used1[to.ff]) {
            if ((cur_w[v] + to.ss) % x != cur_w[to.ff]) {
                return (cur_w[v] + to.ss - cur_w[to.ff] + x) % x;
            }
        } else if (!used1[to.ff]) {
            cur_w[to.ff] = (cur_w[v] + to.ss) % x;
            int ans = check(to.ff, x);
            if (ans)
                return ans;
        }
    }
    used1[v] = 2;
    return 0;
}

void get(int v, vector<int>& c) {
    for (int u : c) {
        used[u] = 0;
        used1[u] = 0;
        cur_w[u] = 0;
    }
    int x = find_cycle(v);
//    cerr << "     " << x << "\n";

    while (true) {
        for (int u : c) {
            used[u] = 0;
            used1[u] = 0;
            cur_w[u] = 0;
        }
        int y = check(v, x);
        if (y) {
            x = __gcd(x, y);
        } else {
            break;
        }
    }
    for (int u : c) {
        used[u] = 1;
        used1[u] = 0;
        cur_w[u] = 0;
    }

//    cerr << "          " << x << "\n";
    d[comp[v]] = x;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(b, c);
        rg[b].pb(a);
    }
    pt = n - 1;
    for (int i = 0; i < n; i++) {
        if (!used[i])
            topsort(i);
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    pt = 1;
    for (int i = 0; i < n; i++) {
        int v = ts[i];
        if (!used[v]) {
            vector<int> c;
            update_comp(v, c);
            if ((int)c.size() >= 2)
                get(v, c);
            else
                bad[v] = 1;
//            cerr << "   " << v + 1 << " " << d[comp[v]] << "\n";
            pt++;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        if (!s) {
            cout << "YES\n";
            continue;
        }
        if (bad[v]) {
            cout << "NO\n";
            continue;
        }
        int x = d[comp[v]];
        x = __gcd(x, t);
        if (s % x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}