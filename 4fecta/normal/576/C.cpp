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

struct pt {
    int x, y, i;
};

bool cmp(pt x, pt y) {
    if (x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}

int n;
vector<pt> a[1005];

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[y / 1000].push_back({x, y, i});
    }
    for (int i = 0; i <= 1000; i++) {
        sort(a[i].begin(), a[i].end(), cmp);
        if (i % 2) reverse(a[i].begin(), a[i].end());
        for (pt p : a[i]) printf("%d ", p.i);
    }

    return 0;
}