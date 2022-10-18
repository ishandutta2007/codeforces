#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define link avba

const int maxn = 1e6 + 42, sigma = 26;
int to[maxn][sigma];
int link[maxn];
int sz = 1;
int active[maxn];

int add_str(string s) {
    int v = 0;
    for(auto c: s) {
        c -= 'a';
        if(!to[v][c]) {
            to[v][c] = sz++;
        }
        v = to[v][c];
    }
    active[v] = 1;
    return v;
}

int que[maxn];
vector<int> g[maxn];

void push_links() {
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi) {
        int v = que[st++];
        int u = link[v];
        if(u != v) {
            g[u].push_back(v);
        }
        for(int c = 0; c < sigma; c++) {
            if(to[v][c]) {
                que[fi++] = to[v][c];
                link[to[v][c]] = v ? to[u][c] : 0;
            } else {
                to[v][c] = to[u][c];
            }
        }
    }
}

int vrt[maxn];

int in[maxn], out[maxn];
int t;


int ad[4 * maxn];

void add(int a, int b, int c, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        ad[v] += c;
        return;
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        add(a, b, c, 2 * v, l, m);
        add(a, b, c, 2 * v + 1, m, r);
    }
}

int get(int p, int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        return ad[v];
    }
    int m = (l + r) / 2;
    if(p < m) {
        return ad[v] + get(p, 2 * v, l, m);
    } else {
        return ad[v] + get(p, 2 * v + 1, m, r);
    }
}

void dfs(int v = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        dfs(u);
    }
    out[v] = t;
    add(in[v], out[v], active[v]);
}


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        string s;
        cin >> s;
        vrt[i] = add_str(s);
        active[vrt[i]] = 1;
    }
    push_links();
    dfs();
    for(int i = 0; i < n; i++) {
        string que;
        cin >> que;
        if(que[0] == '?') {
            int v = 0;
            int ans = 0;
            for(auto c: que.substr(1)) {
                c -= 'a';
                v = to[v][c];
                ans += get(in[v]);
            }
            cout << ans << "\n";
        } else {
            int x = stol(que.substr(1));
            int v = vrt[x - 1];
            bool c = que[0] == '+';
            if(c == active[v]) {
                continue;
            }
            active[v] = c;
            add(in[v], out[v], (c ? 1 : -1));
        }
    }
}