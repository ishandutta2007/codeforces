#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
long long good_ans = 0, bad_ans = 0;
vector <pair <int, int> > G[N];

int dfs(int u, int p)
{
    int sz = 1;
    for (auto [v, w]: G[u]) {
        if (v == p) {
            continue;
        }

        int son_sz = dfs(v, u);
        good_ans += (son_sz & 1) * w;
        bad_ans += 1LL * min(son_sz, n - son_sz) * w;
        sz += son_sz;
    }

    return sz;
}

void solve()
{
    scanf("%d", &n);
    n *= 2;

    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    bad_ans = good_ans = 0;
    dfs(1, 0);

    printf("%lld %lld\n", good_ans, bad_ans);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}