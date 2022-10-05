#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
    mt19937 rng(1033);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, s, V;
vector<int> a, b;

vector<vector<pii>> e;


void add_edge(int u, int v, int w = 0) {
    // cout << "\t[" << w << "] " << v << " -> " << u << endl;
    // e[u].push_back({v, w});
    e[v].push_back({u, w});
}

void work(int pl, int l, int r, int ver, int tl, int tr) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        add_edge(2 * s + pl, ver, 1);
        return;
    }
    int tm = tl + tr >> 1;
    work(pl, l, r, 2 * ver + 0, tl, tm);
    work(pl, l, r, 2 * ver + 1, tm, tr);
}

void seg(int pl, int l, int r) {
    l = max(l, 0);
    work(pl, l, r + 1, 1, 0, s);
}

void BFS(int st) {
    vector<int> d(V, mod);
    vector<int> pr(V, -1);
    d[st] = 0;
    deque<int> a, b;
    a.push_back(st);
    while (a.size()) {
        while (a.size()) {
            int v = a.front();
            a.pop_front();
            for (auto [u, w] : e[v]) {
                if (d[u] > d[v] + w) {
                    d[u] = d[v] + w;
                    pr[u] = v;
                    if (w == 0)
                        a.push_back(u);
                    else
                        b.push_back(u);
                }
            }
        }
        swap(a, b);
    }
    int res = d.back();
    if (res == mod)
        res = -1;
    cout << res << '\n';
    if (res == -1)
        return;

    vector<int> path(1, 2 * s + n);
    while (path.back() != st) {
        path.push_back(pr[path.back()]);
        // if (path.size() == 10 * ml) {
        //     cout << "STOP" << endl;
        //     exit(1);
        // }
    }
    vector<int> ans;
    for (auto i : path)
        if (s <= i && i < 2 * s)
            ans.push_back(i - s);
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}

void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    s = 1;
    while (s < (n + 1))
        s <<= 1;

    V = 2 * s + n + 1;
    e.resize(V);
    for (int i = 2; i < 2 * s; i++) {
        add_edge(i / 2, i);
    }

    for (int i = 0; i < n; i++) {
        int pl = i + 1;
        add_edge(s + pl, 2 * s + pl + b[i]);
    }
    add_edge(s, 2 * s);


    for (int i = 0; i < n; i++) {
        int pl = i + 1;
        seg(pl, pl - a[i], pl);
    }

    BFS(2 * s);

}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int t = 1; 
    // cin >> t;
    while (t--)
        solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}