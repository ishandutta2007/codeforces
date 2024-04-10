#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 200005;
vector < pair < int, int > > can[maxn];
int get_ans[maxn];
int numb[maxn];
int sz[maxn];
int go[maxn];

int gett(int a) {
    if (a == numb[a]) return a;
    return gett(numb[a]);
}

int f(int a, int b) {
    if (go[a] == go[b]) {
        numb[a] = b;
        sz[b] += sz[a];
        go[b]++;
    }
    else if (go[a] < go[b]) {
        numb[a] = b;
        sz[b] += sz[a];
    }
    else {
        numb[b] = a;
        sz[a] += sz[b];
    }
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, c, m, q;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> c;
        can[c].push_back({u, v});
    }
    for (int i = 1; i <= n; ++i) numb[i] = i, sz[i] = 1;
    for (int i = 1; i <= 200000; ++i) {
        get_ans[i] = get_ans[i - 1];
        for (auto key : can[i]) {
            int A = gett(key.first), B = gett(key.second);
            get_ans[i] += (sz[A] * sz[B]);
            f(A, B);
        }
    }
    for (int i = 1; i <= m; ++i) {
        cin >> q;
        cout << get_ans[q] << " ";
    }
    return 0;
}