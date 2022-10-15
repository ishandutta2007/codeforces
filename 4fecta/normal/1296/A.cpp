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
        int u, o = 0, e = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> u;
            sum += u;
            if (u % 2) o++;
            else e++;
        }
        if (sum % 2 || (o && e)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}