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

struct line {
    int m, b;
    int get_val(int x) {
        return m * x + b;
    }
    int intersect(line l) {
        return (l.b - b) / (m - l.m);
    }
};

const int MN = 200005;

int n, a[MN], psa[MN], base, delta;
line deq[MN];

int solve() {
    int l = 1, r = 0, ret = 0; //careful, slopes are in sorted order but queries are **not**
    for (int i = 1; i <= n; i++) psa[i] = a[i] + psa[i - 1];
    for (int i = n; i > 0; i--) { //move num to right
        line cur = {i, -psa[i]};
        while (r - l >= 1 && cur.intersect(deq[r]) > deq[r].intersect(deq[r - 1])) r--;
        deq[++r] = cur;
        int lo = l, hi = r, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (deq[mid].intersect(deq[mid + 1]) > a[i]) lo = mid + 1;
            else hi = mid;
        }
        int tmp = deq[lo].get_val(a[i]) + psa[i] - a[i] * i;
        ret = max(ret, tmp);
    }

    l = 1, r = 0;
    for (int i = 1; i <= n; i++) { //move num to left
        line cur = {i, -psa[i - 1]};
        while (r - l >= 1 && cur.intersect(deq[r]) < deq[r].intersect(deq[r - 1])) r--;
        deq[++r] = cur;
        int lo = l, hi = r, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (deq[mid].intersect(deq[mid + 1]) < a[i]) lo = mid + 1;
            else hi = mid;
        }
        int tmp = deq[lo].get_val(a[i]) + psa[i - 1] - a[i] * i;
        ret = max(ret, tmp);
    }
    return ret;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], base += i * a[i];
    delta = max(delta, solve());
    printf("%lld\n", base + delta);

    return 0;
}