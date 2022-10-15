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

const int MN = 100005;

int n, a[MN], psa[MN], cnt = 0, sum = 0, ans = 0, back = 0;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i], psa[i] = psa[i - 1] + a[i];
    if (sum % 3) return 0 * printf("0\n");
    for (int i = n; i > 0; i--) {
        if (i > 1 && psa[i - 1] == sum / 3) ans += cnt;
        back += a[i];
        if (back == sum / 3) cnt++;
    }
    printf("%lld\n", ans);

    return 0;
}