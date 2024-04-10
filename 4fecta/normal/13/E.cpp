#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, q, t, u, v, a[MN], id[MN], nxt[MN], m[MN], cur[MN], SQRT;

int main() {
    boost();

    cin >> n >> q;
    SQRT = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i], id[i] = i / SQRT + 1;
    for (int i = n; i > 0; i--) {
        int tmp = i + a[i];
        if (id[tmp] != id[i]) m[i] = 1, nxt[i] = tmp, cur[i] = i;
        else m[i] = m[tmp] + 1, nxt[i] = nxt[tmp], cur[i] = cur[tmp];
    }
    for (; q > 0; q--) {
        cin >> t;
        if (t == 1) {
            int ret = 0;
            cin >> u;
            int lst = u;
            while (u <= n) lst = cur[u], ret += m[u], u = nxt[u];
            printf("%d %d\n", lst, ret);
        } else {
            cin >> u >> v;
            a[u] = v;
            do {
                int tmp = u + a[u];
                if (id[tmp] != id[u]) m[u] = 1, nxt[u] = tmp, cur[u] = u;
                else m[u] = m[tmp] + 1, nxt[u] = nxt[tmp], cur[u] = cur[tmp];
                u--;
            } while (id[u] == id[u + 1]);
        }
    }

    return 0;
}