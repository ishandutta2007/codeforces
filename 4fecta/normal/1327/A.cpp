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

ll sum[10000007];

int main() {
    boost();

    for (int i = 1; i <= 10000000; i++) {
        sum[i] = sum[i - 1] + i * 2 - 1;
    }
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n % 2 == k % 2 && n >= sum[k]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}