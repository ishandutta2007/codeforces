#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

struct Data {
    int x, y;
};

bool cmp(Data a, Data b) {
    return (a.x - a.y) < (b.x - b.y);
}

int d1[N], d2[N];
vi g[N];
int a[N];
bool check[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, qq;
    cin >> n >> m >> qq;
    for (int i = 1; i <= qq; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e : g[u]) {
            if (check[e]) continue;
            d1[e] = d1[u] + 1;
            check[e] = 1;
            q.push(e);
        }
    }
    q.push(n);
    memset(check, 0 ,sizeof(check));
    check[n] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int e : g[u]) {
            if (check[e]) continue;
            d2[e] = d2[u] + 1;
            check[e] = 1;
            q.push(e);
        }
    }
    int ans = d1[n];
    int mx = 0;
    int mx2 = d1[a[1]];
    vector<Data> v;
    for (int i = 1; i <= qq; i++) {
        Data tmp;
        tmp.x = d1[a[i]];
        tmp.y = d2[a[i]];
        v.pb(tmp);
    }
    sort(all(v), cmp);
    mx2 = v[0].x;
    for (int i = 1; i < qq; i++) {
        mx = max(mx, v[i].y + mx2 + 1);
        mx2 = max(mx2, v[i].x);
    }
    cout << min(ans, mx);
    return 0;
}