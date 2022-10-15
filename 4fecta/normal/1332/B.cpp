#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1005;
int n, m, a[MN], ans[MN], freq[MN];
set<int> s[MN];

bool prime(int b) {
    for (int i = 2; i * i <= b; i++) if (b % i== 0) return false;
    return true;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(freq, 0, sizeof(freq));
        memset(ans, 0, sizeof(ans));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < MN; i++) s[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j == 0) s[i].insert(j), freq[j]++;
            }
        }
        vector<pii> v;
        for (int i = 2; i <= 1000; i++) v.push_back({freq[i], i});
        sort(v.begin(), v.end(), greater<>());
        int col = 1;
        for (pii p : v) {
            //printf("%d %d\n", p.f, p.s);
            int i = p.s;
            if (!p.f) break;
            if (!prime(i)) continue;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (ans[j]) continue;
                if (a[j] % i == 0) cnt++, ans[j] = col;
            }
            if (cnt) col++;
        }
        col = 0;
        for (int i = 1; i <= n; i++) col = max(col, ans[i]);
        assert(col <= 11);
        printf("%lld\n", col);
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    }

    return 0;
}