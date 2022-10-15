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
        int a, b;
        cin >> a >> b;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 20; i++) {
            int A = a;
            int d = b + i;
            if (d < 2) continue;
            int tmp = i;
            while (A) A /= d, tmp++;
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }

    return 0;
}