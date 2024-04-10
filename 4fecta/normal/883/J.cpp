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

int n, m, a[MN], b[MN], p[MN];
vector<pii> v;
vector<int> d[MN];

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> p[i], v.push_back({b[i], p[i]});
    sort(v.begin(), v.end());
    int id = 0;
    for (int i = n; i > 0; i--) while (id < v.size() && v[id].f <= a[i]) d[i].push_back(v[id++].s); //we can demolish this
    int cur = 0, ans = 0;
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        cur += a[i];
        sort(d[i].begin(), d[i].end());
        for (int p : d[i]) {
            if (p <= cur) cur -= p, ans++, s.insert(p);
            else if (s.size() && p < *s.rbegin()) cur += *s.rbegin() - p, s.insert(p), s.erase(s.find(*s.rbegin()));
            else break;
        }
    }
    printf("%lld\n", ans);

    return 0;
}