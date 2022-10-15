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

const int MN = 200005, LOG = 30;

int n, a[MN], pre[MN], bit[30];

void split(int v) {
    for (int i = LOG - 1; i >= 0; i--) if (bit[i] != -1 && (v & (1 << i))) v ^= bit[i];
    if (v == 0) return;
    for (int i = LOG - 1; i >= 0; i--) if (v & (1 << i)) {bit[i] = v; return;}
}

int main() {
    boost();

    memset(bit, -1, sizeof(bit));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        split(pre[i]);
    }
    if (pre[n] == 0) return 0 * printf("-1\n");
    int ans = 0;
    for (int i = 0; i < LOG; i++) if (bit[i] != -1) ans++;
    printf("%d\n", ans);

    return 0;
}