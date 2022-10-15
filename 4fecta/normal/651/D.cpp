#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 500005;

int N, a[MN * 3], psa[MN * 3], A, B, T;
char c;

bool check(int len) {
    if (!len) return 1;
    int r = N + 1, l = r - len + 1;
    for (; l <= N + 1; r++, l++) {
        int dist = min(abs(r - N - 1), abs(l - N - 1)) + len - 1;
        int ans = dist * A + (psa[r] - psa[l - 1]) * B + len;
        //printf("%d %d\n", len, ans);
        if (ans <= T) return 1;
    }
    return 0;
}

int32_t main() {
    boost();

    cin >> N >> A >> B >> T;
    for (int i = 1; i <= N; i++) {
        cin >> c;
        if (c == 'w') a[i] = a[N + i] = a[2 * N + i] = 1;
    }
    for (int i = 1; i <= 3 * N; i++) psa[i] = a[i] + psa[i - 1];
    int lo = 0, hi = N, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        mid += (lo + hi) & 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d\n", lo);

    return 0;
}