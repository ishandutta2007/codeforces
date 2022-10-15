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

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;
        vector<int> inc;
        int rate = 1;
        while (n) {
            int dbl = rate * 2;
            if (rate <= n && n <= dbl) {
                inc.push_back(n - rate);
                break;
            }
            if (dbl * 2 >= n) {
                int p1, p2;
                if (n & 1) p1 = n / 2, p2 = n / 2 + 1;
                else p1 = p2 = n / 2;
                inc.push_back(p1 - rate), inc.push_back(p2 - p1);
                break;
            } else {
                inc.push_back(rate);
                rate += rate;
                n -= rate;
            }
        }
        cout << inc.size() << "\n";
        for (int p : inc) cout << p << " ";
        cout << "\n";
    }

    return 0;
}