#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t getValMin(int64_t node, int h1, int h2) {
    int64_t ans = node;
    int64_t val = 2 * node;
    for (int i = 0; i < h1; ++i) {
        ans += val;
        val *= 2;
    }
    val = 2 * node + 1;
    for (int i = 0; i < h2; ++i) {
        ans += val;
        val *= 2;
    }
    return ans;
}

int64_t getDp(int64_t n, int h1, int h2, int k) {
    vector<int64_t> eq(k + 1, 0), ne(k + 1, 0);
    vector<int64_t> neq(k + 1, 0), nne(k + 1, 0);

    eq[0] = 1;
    for (int i = 50; i >= 0; --i) {
        fill(neq.begin(), neq.end(), 0);
        fill(nne.begin(), nne.end(), 0);
        int adm = (!(i >= h1)) + (!(i >= h2));
        if (n & (1LL << i)) {
            for (int j = 0; j <= k; ++j) {
                nne[j] = eq[j];
            }
            if (adm >= 1) {
                for (int j = 0; j < k; ++j) {
                    neq[j + 1] += eq[j];
                }
            }
            if (adm >= 2) {
                for (int j = 0; j < k; ++j) {
                    neq[j + 1] += eq[j];
                }
                for (int j = 0; j < k - 1; ++j) {
                    nne[j + 2] += ne[j];
                }
            }
        } else {
            for (int j = 0; j <= k; ++j) {
                neq[j] = eq[j];
            }
            if (adm >= 1) {
                for (int j = 0; j < k; ++j) {
                    nne[j + 1] += ne[j];
                }
            }
            if (adm >= 2) {
                for (int j = 0; j < k; ++j) {
                    nne[j + 1] += ne[j];
                }
                for (int j = 0; j < k - 1; ++j) {
                    neq[j + 2] += ne[j];
                }
            }
        }
        eq.swap(neq);
        ne.swap(nne);
    }
    return eq[k];
}

int64_t solve(int64_t n, int64_t node, int h1, int h2) {
    n -= node;
    int64_t sub = 2 * node;
    for (int i = 1; i <= h1; ++i) {
        n -= sub;
        sub *= 2;
    }
    sub = 2 * node + 1;
    for (int i = 1; i <= h2; ++i) {
        n -= sub;
        sub *= 2;
    }
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    }
    h1 = max(h1 - 1, 0);
    h2 = max(h2 - 1, 0);
    int64_t ans = 0;
    for (int i = 0; i <= h1 + h2; ++i) {
        if ((n + i) % 2 == 0) {
            ans += getDp((n + i) / 2, h1, h2, i);
        }
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n;
    cin >> n;

    int64_t ans = 0;
    for (int h1 = 0; h1 < 50; ++h1) {
        for (int h2 = 0; h2 < 50; ++h2) {
            int64_t node = 0;
            for (int64_t step = 1LL << 50; step > 0; step /= 2) {
                int64_t nnode = node + step;
                int hm = max(h1, h2);
                int64_t vm = nnode;
                for (int i = 1; i <= hm; ++i) {
                    vm = min(n + 1, vm * 2);
                }
                if (vm > n) {
                    continue;
                }
                int64_t vmin = getValMin(nnode, h1, h2);
                if (vmin <= n) {
                    node += step;
                }
            }
            if (node == 0) {
                continue;
            }
            ans += solve(n, node, h1, h2);
        }
    }
    cout << ans << '\n';
}