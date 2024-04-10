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

pii a[MN];
int n;

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        bool meme = 1;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].f >> a[i].s;
            if (a[i].s > a[i].f) meme = 0;
        }
        for (int i = 2; i <= n; i++) {
            if (a[i].f < a[i - 1].f) meme = 0;
            if (a[i].s < a[i - 1].s) meme = 0;
            int d1 = a[i].f - a[i - 1].f;
            int d2 = a[i].s - a[i - 1].s;
            if (d1 < d2) meme = 0;
        }
        if (meme) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}