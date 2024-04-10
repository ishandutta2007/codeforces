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

int n, m, u, v, in[MN], id, ans[MN];
vector<int> a[MN];

int main() {
    boost();

    cin >> n >> m;
    id = n;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[v].push_back(u);
        in[u]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push(i);
    }
    while (q.size()) {
        int cur = q.top(); q.pop();
        ans[cur] = id--;
        for (int nxt : a[cur]) {
            in[nxt]--;
            if (!in[nxt]) q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}