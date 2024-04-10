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

const int MN = 100005;

int n, k, p, u, cnt = 0;

int main() {
    boost();

    stack<int> odd, even;
    vector<int> ans[MN];
    cin >> n >> k >> p;
    p = k - p;
    for (int i = 0; i < n; i++) {
        cin >> u;
        if (u % 2) odd.push(u), cnt++;
        else even.push(u);
    }
    if (cnt >= p && (cnt - p) % 2 == 0) {
        for (int i = 1; i <= p; i++) {
            ans[i].push_back(odd.top());
            odd.pop();
        }
        int idx = k == p ? 1 : p + 1;
        while (odd.size()) {
            ans[idx].push_back(odd.top()), odd.pop();
            ans[idx].push_back(odd.top()), odd.pop();
            if (idx < k) idx++;
        }
        while (even.size()) {
            ans[idx].push_back(even.top()), even.pop();
            if (idx < k) idx++;
        }
        for (int i = 1; i <= k; i++) {
            if (!ans[i].size()) goto nein;
        }
        printf("YES\n");
        for (int i = 1; i <= k; i++) {
            printf("%lld ", ans[i].size());
            for (int j : ans[i]) printf("%d ", j);
            printf("\n");
        }
    } else {
        nein: printf("NO\n");
    }

    return 0;
}