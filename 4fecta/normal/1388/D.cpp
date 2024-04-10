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

const int MN = 200005;

int n, a[MN], b[MN], ans, deg[MN], nxt[MN], vis[MN];
deque<int> out;
vector<int> rev[MN];

void collect(int cur) {
    queue<int> q;
    q.push(cur);
    while (q.size()) {
        int cur = q.front(); q.pop();
        vis[cur] = 1;
        out.push_front(cur);
        for (int nxt : rev[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
        }
    }
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == -1) continue;
        deg[b[i]]++;
        nxt[i] = b[i];
        rev[b[i]].push_back(i);
    }
    queue<int> q; //we want to cut this off as soon as it becomes negative. (i.e.) push to very back of answer queue
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) q.push(i);
    }
    while (q.size()) {
        int cur = q.front(); q.pop();
        ans += a[cur];
        if (!nxt[cur]) {
            collect(cur);
            continue;
        }
        deg[nxt[cur]]--;
        if (!deg[nxt[cur]]) q.push(nxt[cur]);

        if (a[cur] > 0) a[nxt[cur]] += a[cur];
        else collect(cur);
    }
    cout << ans << "\n";
    //assert(out.size() == n);
    for (int p : out) cout << p << " ";

    return 0;
}