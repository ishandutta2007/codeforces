#include <bits/stdc++.h>

using namespace std;

const int N = 2'007;
const int MOD = 1'000'000'007;

int n, root;
int ans[N];
int value[N];

int sz[N];
vector <int> G[N];

int get_size(int u)
{
    sz[u] = 1;
    for (auto v: G[u]) {
        sz[u] += get_size(v);
    }

    return sz[u];
}

void go(int u, vector <int> vals)
{
    if (value[u] >= vals.size()) {
        puts("NO");
        exit(0);
    }

    vector <int> new_vals;
    for (int i = 0; i < (int)vals.size(); ++i) {
        if (i != value[u]) {
            new_vals.push_back(vals[i]);
        }
    }

    ans[u] = vals[value[u]];
    vals.clear();

    reverse(new_vals.begin(), new_vals.end());
    for (auto v: G[u]) {
        while (sz[v]--) {
            vals.push_back(new_vals.back());
            new_vals.pop_back();
        }

        go(v, vals);
        vals.clear();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d %d", &p, &value[i]);

        if (!p) {
            root = i;
        } else {
            G[p].push_back(i);
        }
    }

    vector <int> all(n);
    iota(all.begin(), all.end(), 1);

    get_size(root);
    go(root, all);

    puts("YES");
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}