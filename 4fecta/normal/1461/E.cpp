#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1000005;

int l, k, r, vis[MN], t, x, y, dist[MN], loop;

int32_t main() {
    boost();

    cin >> k >> l >> r >> t >> x >> y;
    k -= l, r -= l; //[0, r] range is fine
    if (y < x) { //unsustainable edge case
        int del = x - y;
        int lim = r - y;
        if (k > lim) {
            int times = (k - lim - 1) / x + 1;
            k -= x * times;
            t -= times;
        }
        if (k / del >= t) printf("Yes\n");
        else printf("No\n");
        return 0;
    }
    t -= k / x;
    k %= x;
    memset(dist, -0x3f, sizeof(dist));
    queue<int> q;
    q.push(k);
    vis[k] = 1;
    dist[k] = 0;
    while (q.size()) { //stay in [0, x - 1]
        int cur = q.front(); q.pop();
        int orig = cur;
        if (cur - x >= 0) {
            if (vis[cur - x]) loop = 1;
            else vis[cur - x] = 1, q.push(cur - x), dist[cur - x] = dist[cur] + 1;
        }
        if (cur + y <= r) {
            cur += y - x;
            int aux = cur / x;
            cur %= x;
            if (vis[cur]) loop = 1;
            else vis[cur] = 1, q.push(cur), dist[cur] = dist[orig] + 1 + aux;
        }
    }
    int mx = 0;
    for (int i = 0; i < x; i++) mx = max(mx, dist[i]);
    if (mx >= t || loop) printf("Yes\n");
    else printf("No\n");

    return 0;
}