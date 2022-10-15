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

const int MN = 105;

int n, k, a[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        set<int> s;
        for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
        if (s.size() > k) printf("-1\n");
        else {
            printf("%d\n", n * k);
            int d = k - s.size();
            for (int i = 1; i <= n; i++) {
                for (int j : s) printf("%d ", j);
                for (int j = 1; j <= d; j++) printf("1 ");
            }
            printf("\n");
        }
    }

    return 0;
}