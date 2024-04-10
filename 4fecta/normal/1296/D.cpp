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

const int MN = 200005;

int n, a, b, k, h[MN];
vector<int> extra;
int ans = 0;

int main() {
    boost();

    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        int rem = h[i] % (a + b);
        if (rem == 0) rem += a + b;
        extra.push_back(ceil((double) rem / (double) a) - 1);
    }
    sort(extra.begin(), extra.end());
    for (int hits : extra) {
        if (k < hits) break;
        ans++;
        k -= hits;
    }
    printf("%d\n", ans);

    return 0;
}