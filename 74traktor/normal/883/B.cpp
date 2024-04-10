#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int c[maxn], mx[maxn], cnt[maxn];
vector < int > g[maxn], G[maxn];
set < int > in[maxn];
int gg[maxn], used[maxn], sv[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        if (c[i] != 0) used[c[i]] = 1;
        if (c[i] == 0) mx[i] = k;
        else mx[i] = c[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        G[v].push_back(u);
        cnt[v]++;
    }
    set < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) {
        Q.insert({cnt[i], i});
    }
    set < pair < int, int > > tops;
    while ((int)Q.size()) {
        auto p = (*Q.begin());
        tops.insert({mx[p.second], p.second});
        if (p.first) {
            cout << -1;
            exit(0);
        }
        Q.erase(p);
        for (auto key : g[p.second]) {
            mx[key] = min(mx[key], mx[p.second] - 1);
            Q.erase({cnt[key], key});
            cnt[key]--;
            Q.insert({cnt[key], key});
        }
    }
    vector < pair < int, int > > go;
    for (int i = 1; i <= n; ++i) {
        sv[i] = mx[i];
        if (mx[i] < c[i] || mx[i] == 0) {
            cout << -1;
            exit(0);
        }
        go.push_back({mx[i], i});
    }
    sort(go.begin(), go.end());
    int ptr = 1;
    for (auto key : go) {
        if (c[key.second] != 0) {
            assert(mx[key.second] == c[key.second]);
            continue;
        }
        while (ptr <= k && used[ptr] == 1) ptr++;
        int tmp = 1;
        for (auto elem : g[key.second]) tmp = max(tmp, mx[elem] + 1);
        if (ptr > mx[key.second]) {
            assert(tmp <= mx[key.second]);
            mx[key.second] = tmp;
            used[tmp] = 1;
        } else {
            tmp = min(mx[key.second], max(tmp, ptr));
            while (tmp < mx[key.second] && used[tmp]) tmp++;
            mx[key.second] = max(ptr, tmp);
            used[max(ptr, tmp)] = 1;
            if (tmp == ptr) ptr++;
        }
        assert(mx[key.second] <= sv[key.second]);
    }
    set < int > TT;
    for (int i = 1; i <= n; ++i) {
        TT.insert(mx[i]);
        for (auto key : g[i]) {
            if (mx[i] <= mx[key]) {
                cout << -1;
                exit(0);
            }
        }
        if (mx[i] <= 0 || mx[i] > k) {
            cout << -1;
            exit(0);
        }
    }
    if ((int)TT.size() != k) {
        cout << -1;
        exit(0);
    }
    while (ptr <= k && used[ptr] == 1) ptr++;
    if (ptr != k + 1) {
        cout << -1;
        exit(0);
    }
    set < int > T;
    for (int i = 1; i <= n; ++i) {
        T.insert(mx[i]);
    }
    for (int i = 1; i <= n; ++i) cout << mx[i] << " ";
    cout << '\n';
    return 0;
}