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

struct node {
    int i, p, q;
    char c;
};

int n, k, rev[MN];
node a[MN];

bool cmp1(node x, node y) {
    return x.p < y.p;
}

bool cmp2(node x, node y) {
    return x.i < y.i;
}

int main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].p, rev[a[i].p] = i;
    for (int i = 1; i <= n; i++) cin >> a[i].q, a[i].i = i;
    set<int> s1, s2;
    int l = 1, inc = 0;
    for (int i = 1; i <= n; i++) {
        if (s2.count(a[i].p)) s2.erase(a[i].p);
        else s1.insert(a[i].p);
        if (s1.count(a[i].q)) s1.erase(a[i].q);
        else s2.insert(a[i].q);
        if (s1.count(a[i].q)) s1.erase(a[i].q), s2.erase(a[i].q);
        if (s1.empty() && s2.empty()) {
            for (int j = l; j <= i; j++) a[a[j].p].c = (char) ('a' + min(inc, 25));
            inc++;
            l = i + 1;
        }
    }
    if (inc < k) return 0 * printf("NO\n");
    else printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%c", a[i].c);

    return 0;
}