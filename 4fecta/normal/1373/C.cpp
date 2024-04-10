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

const int MN = 1000005;

int pfx[MN];

int32_t main() {
    boost();

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        int mn = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '-') pfx[i] = pfx[i - 1] - 1;
            else pfx[i] = pfx[i - 1] + 1;
            mn = min(mn, pfx[i]);
        }
        set<int> st;
        mn = -mn;
        for (int i = 0; i < mn; i++) st.insert(i);
        int ans = s.size();
        for (int i = 1; i <= s.size(); i++) {
            int neg = -pfx[i] - 1;
            if (st.count(neg)) ans += i, st.erase(neg);
        }
        printf("%lld\n", ans);
    }

    return 0;
}