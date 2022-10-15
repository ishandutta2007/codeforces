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

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p1 = 6, p2 = 10, p3 = 14;
        if (n <= p1 + p2 + p3) {
            printf("NO\n");
            continue;
        }
        int diff = n - p1 - p2 - p3;
        if (diff == 6) {
            printf("YES\n5 6 10 15\n");
            continue;
        }
        if (diff == 14) {
            printf("YES\n6 7 10 21\n");
            continue;
        }
        if (diff == 10) {
            printf("YES\n6 10 15 9\n");
            continue;
        }
        printf("YES\n%d %d %d %d\n", p1, p2, p3, diff);
    }

    return 0;
}