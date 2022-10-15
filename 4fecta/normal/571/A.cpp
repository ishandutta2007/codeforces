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

const int MN = 300005;

int cnt(int a, int b, int c, int s) {
    if (s + a < b + c) {
        return 0;
    }
    int cur = min(s, (s + a - b - c) / 2);
    return (cur + 1) * (cur + 2) / 2;
}

int a[5], l;

int32_t main() {
    boost();

    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    cin >> l;
    int ans = 0;
    for (int i = 0; i <= l; ++i) {
        ans += (l - i + 1) * (l - i + 2) / 2;
    }
    for (int i = 0; i < 3; ++i) {
        for (int s = 0; s <= l; ++s) {
            ans -= cnt(a[i], a[(i + 1) % 3], a[(i + 2) % 3], s);
        }
    }
    printf("%lld\n", ans);

    return 0;
}