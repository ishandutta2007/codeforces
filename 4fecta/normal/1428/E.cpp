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

const int MN = 100005;

int n, k, a[MN], cut[MN], ans = 0;
priority_queue<pii, vector<pii>, greater<>> q;

int sq(int x) {
    return x * x;
}

int get_val(int num, int cuts) {
    int part = num / cuts;
    int ex = num % cuts;
    int rem = cuts - ex;
    return sq(part + 1) * ex + sq(part) * rem;
}

int32_t main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cut[i] = 1;
        cin >> a[i];
        ans += sq(a[i]);
        if (a[i] <= cut[i]) continue;
        int val = get_val(a[i], cut[i]), nval = get_val(a[i], cut[i] + 1);
        q.push({nval - val, i});
    }
    int t = k - n;
    while (q.size() && t-- > 0) {
        pii cur = q.top(); q.pop();
        ans += cur.f;
        cut[cur.s]++;
        if (a[cur.s] <= cut[cur.s]) continue;
        int val = get_val(a[cur.s], cut[cur.s]), nval = get_val(a[cur.s], cut[cur.s] + 1);
        q.push({nval - val, cur.s});
    }
    printf("%lld\n", ans);

    return 0;
}