#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

void solve(int s, int t, vector <int> cur)
{
    vector <int> up(4, 0), down(4, 0);
    up[0] = cur[0] - (t == 0);
    down[1] = cur[0] - (s == 0);
    up[1] = cur[1] - (t == 1) - down[1];
    down[2] = cur[1] - (s == 1) - up[0];
    up[2] = cur[2] - (t == 2) - down[2];
    down[3] = cur[2] - (s == 2) - up[1];

    if (down[3] != cur[3] - (t == 3)) {
        return;
    }

    if (up[2] != cur[3] - (s == 3)) {
        return;
    }

    if (down[2] != cur[2] - (t == 2) - up[2]) {
        return;
    }

    if (up[1] != cur[2] - (s == 2) - down[3]) {
        return;
    }

    if (down[1] != cur[1] - (t == 1) - up[1]) {
        return;
    }

    if (up[0] != cur[1] - (s == 1) - down[2]) {
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (up[i] < 0 || down[i + 1] < 0) {
            return;
        }
    }

    vector <int> ans;
    function <void (int)> dfs = [&](int u) {
        ans.push_back(u);
        if (up[u]) {
            up[u]--;
            dfs(u + 1);
        } else if (down[u]) {
            down[u]--;
            dfs(u - 1);
        }
    };

    dfs(s);
    if ((int)ans.size() != cur[0] + cur[1] + cur[2] + cur[3]) {
        return;
    }

    puts("YES");
    for (auto v: ans) {
        printf("%d ", v);
    }

    puts("");
    exit(0);
}

int main()
{
    vector <int> in(4);
    for (auto &v: in) {
        scanf("%d", &v);
    }

    if (in[0] + in[1] + in[2] + in[3] == 1) {
        puts("YES");
        for (int i = 0; i < 4; ++i) {
            if (in[i]) {
                printf("%d\n", i);
            }
        }

        exit(0);
    }

    for (int s = 0; s < 4; ++s) {
        for (int t = 0; t < 4; ++t) {
            if (in[s] && in[t]) {
                solve(s, t, in);
            }
        }
    }

    puts("NO");
    return 0;
}