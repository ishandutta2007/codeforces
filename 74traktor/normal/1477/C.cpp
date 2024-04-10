#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;

int x[5005], y[5005];
int ans[5005], used[5005], it;
vector < int > go;
mt19937 rnd;

inline ll dot(ll x1, ll y1, ll x2, ll y2) {
    return x1 * x2 + y1 * y2;
}

inline int check(int i, int j, int k) {
    return dot(x[i] - x[j], y[i] - y[j], x[k] - x[j], y[k] - y[j]) > 0;
}

void dfs(int v) {
    it++;
    if (v == n + 1) {
        for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        exit(0);
    }
    if (it == 1024) {
        it = 0;
        if (1.0 * clock() / CLOCKS_PER_SEC > 1.88) {
            cout << -1 << '\n';
            exit(0);
        }
    }
    for (auto i : go) {
        if (used[i]) continue;
        if (v < 3 || check(ans[v - 2], ans[v - 1], i)) {
            used[i] = 1;
            ans[v] = i;
            dfs(v + 1);
            used[i] = 0;
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        go.push_back(i);
        cin >> x[i] >> y[i];
    }
    shuffle(go.begin(), go.end(), rnd);
    dfs(1);
    return 0;
}