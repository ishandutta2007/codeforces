#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> in(n), order(n + 1);
    for (int &v: in) {
        scanf("%d", &v);
    }

    vector <pair <long long, int> > pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = { pref[i].first + in[i], i + 1 };
    }

    int cnt = 0;
    sort(pref.begin(), pref.end());

    order[pref[0].second] = cnt;
    for (int i = 1; i <= n; ++i) {
        if (pref[i].first != pref[i - 1].first) {
            ++cnt;
        }

        order[pref[i].second] = cnt;
    }

    int T = 1;
    while (T <= cnt) {
        T *= 2;
    }

    vector <vector <int> > tree(3, vector <int> (T + T, -2 * n));

    auto update = [&](int id, int p, int v) {
        p += T;
        while (p) {
            tree[id][p] = max(tree[id][p], v);
            p >>= 1;
        }
    };

    auto query = [&](int id, int l, int r) {
        int ret = -2 * n;
        l += T, r += T;

        while (l <= r) {
            if (l & 1) {
                ret = max(ret, tree[id][l]);
            }

            if (!(r & 1)) {
                ret = max(ret, tree[id][r]);
            }

            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }

        return ret;
    };

    update(0, order[0], 0);
    update(1, order[0], 0);
    update(2, order[0], 0);

    int ans;
    for (int i = 1; i <= n; ++i) {
        ans = i + query(0, 0, order[i] - 1);
        ans = max(ans, query(1, order[i], order[i]));
        ans = max(ans, query(2, order[i] + 1, cnt) - i);

        update(0, order[i], ans - i);
        update(1, order[i], ans);
        update(2, order[i], ans + i);
    }

    printf("%d\n", ans);
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