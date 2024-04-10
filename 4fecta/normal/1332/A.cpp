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
        int a, b, c, d, x, y, x1, y1, x2, y2;

        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        int sx = x2 - x1;
        int sy = y2 - y1;
        if ((a || b) && !sx) {
            cout << "NO\n";
            continue;
        }
        if ((c || d) && !sy) {
            cout << "NO\n";
            continue;
        }
        int h = b - a, v = d - c;
        int nx = x + h, ny = y + v;
        if (nx <= x2 && nx >= x1 && ny <= y2 && ny >= y1) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}