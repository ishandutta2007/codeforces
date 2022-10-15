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

struct voter {
    int m, p;
};

const int MN = 200005;

int n, freq[MN], psa[MN];
voter a[MN];
vector<int> v[MN];

bool cmp(voter x, voter y) {
    return x.m < y.m;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<int, vector<int>, greater<>> q;
        for (int i = 0; i <= n; i++) v[i].clear(), freq[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].m >> a[i].p;
            freq[a[i].m]++;
            v[a[i].m].push_back(a[i].p);
        }
        for (int i = 0; i <= n; i++) {
            psa[i + 1] = psa[i] + freq[i];
        }
        int tot = 0, ans = 0;
        for (int i = n; i > 0; i--) {
            for (int p : v[i]) q.push(p);
            int req = i - psa[i];
            //printf("%d\n", req);
            if (req <= 0) continue;
            while (tot < req) {
                ans += q.top();
                q.pop();
                tot++;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}