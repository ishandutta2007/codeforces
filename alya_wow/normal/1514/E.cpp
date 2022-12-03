#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int q[500];

int hid[150][150];

int ca, co, n;

int ask(int v, int u) {
    ca++;
    assert(ca <= 9 * n);
#ifndef ONPC
    cout << "1 " << v << ' ' << u << endl;
    int w;
    cin >> w;
    return w;
#else
    return hid[v][u];
#endif
}

int ok(int v, vector<int> u) {
    co++;
    assert(co <= 2 * n);
#ifndef ONPC
    cout << "2 " << v << ' ' << u.size();
    for (int i : u)
        cout << ' ' << i;
    cout << endl;
    int w;
    cin >> w;
    return w;
#else
    for (int i : u)
        if (hid[v][i])
            return 1;
    return 0;
#endif
}

void init(int v, int l, int r) {
    if (l == r) {
        q[v] = l;
        return;
    }
    int m = (l + r) / 2;
    init(2 * v, l, m);
    init(2 * v + 1, m + 1, r);
    if (ask(q[2 * v], q[2 * v + 1]))
        q[v] = q[2 * v];
    else
        q[v] = q[2 * v + 1];
}

void go(int v, int l, int r) {
    if (l == r) {
        q[v] = -1;
        return;
    }
    int m = (l + r) / 2;
    if (q[2 * v] == q[v]) {
        go(2 * v, l, m);
    } else {
        go(2 * v + 1, m + 1, r);
    }
    if (q[2 * v] == -1)
        q[v] = q[2 * v + 1];
    else if (q[2 * v + 1] == -1)
        q[v] = q[2 * v];
    else if (ask(q[2 * v], q[2 * v + 1]))
        q[v] = q[2 * v];
    else
        q[v] = q[2 * v + 1];
}

void trav(int v, int l, int r) {
    cerr << v << ' ' << q[v] << '\n';
    if (l == r)
        return;
    int m = (l + r) / 2;
    trav(2 * v, l, m);
    trav(2 * v + 1, m + 1, r);
}

int p[200];

int get(int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
}

int uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return 0;
    if (x > y)
        swap(x, y);
    p[y] = x;
    return 1;
}

void solve() {
    ca = co = 0;
    n = 10;
    cin >> n;
#ifdef ONPC
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            hid[i][j] = (i < j);
            if (i > 0)
                hid[i][j] = rnd() & 1;
            //hid[i][j] = rnd() % 2;
            hid[j][i] = !hid[i][j];
        }
#endif
    init(1, 0, n - 1);
    vector<int> q;
    //
    for (int i = 0; i < n; i++) {
        q.push_back(::q[1]);
        //trav(1, 0, n - 1);
        go(1, 0, n - 1);
    }
    //trav(1, 0, n - 1);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++) {
        while (1) {
            int x = get(i);
            if (x == 0)
                break;
            int w = ok(q[i], vector<int>(q.begin(), q.begin() + x));
            if (w == 1) {
                uni(x, x - 1);
            } else {
                break;
            }
        }
    }
    cout << 3 << endl;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            g[q[i]][q[j]] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (get(i) == get(j))
                g[q[i]][q[j]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    int ueban_tishachnogo_ranga;
    cin >> ueban_tishachnogo_ranga;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 100;
    cin >> t;
    while (t--) {
        //cerr << t << '\n';
        solve();
    }
}