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

int t, n, q;
set<int> s;

void rec(vector<int> a) {
    if (a.empty()) return;
    vector<int> p1, p2;
    int sum1 = 0, sum2 = 0, mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    for (int p : a) mn = min(mn, p), mx = max(mx, p);
    int val = (mx + mn) / 2;
    for (int p : a) {
        if (p <= val) p1.push_back(p), sum1 += p;
        else p2.push_back(p), sum2 += p;
    }
    s.insert(sum1), s.insert(sum2);
    if (p1.empty() || p2.empty()) return;
    rec(p1), rec(p2);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> a;
        int sum = 0;
        for (int i = 1, u; i <= n; i++) cin >> u, a.push_back(u), sum += u;
        s.insert(sum);
        rec(a);
        for (int u; q > 0; q--) {
            cin >> u;
            if (s.count(u)) printf("Yes\n");
            else printf("No\n");
        }
        s.clear();
    }

    return 0;
}