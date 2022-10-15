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

const int MN = 1005;

int n, cnt = 0;
pii a[MN];

bool lft(pii x, pii y, pii z) {
    return (z.f < y.f && y.s > x.s) || (z.f > y.f && y.s < x.s) || (z.s < y.s && y.f < x.f) || (z.s > y.s && y.f > x.f);
}

int main() {
    boost();

    cin >> n >> a[0].f >> a[0].s >> a[1].f >> a[1].s;
    for (int i = 2; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
        cnt += lft(a[i - 2], a[i - 1], a[i]);
    }
    printf("%d\n", cnt);

    return 0;
}