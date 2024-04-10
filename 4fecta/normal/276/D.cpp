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

ll a, b;

int main() {
    boost();

    cin >> a >> b;
    for (int i = 63; i >= 0; i--) {
        ll ta = a & (1LL << i), tb = b & (1LL << i);
        if (ta ^ tb) {
            cout << (1LL << (i + 1)) - 1 << "\n";
            return 0;
        }
    }
    cout << "0\n";

    return 0;
}