#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, u, v, cnt[MN], bit[MN * 2], in[MN], out[MN], tim = 1, pre[MN], lvs[MN], rem[MN], ans;
vector<int> a[MN];

void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

void dfs(int cur, int par) {
    int num = 0;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        if (!rem[nxt]) num++;
    }
    if (num) ans += num - 1, rem[cur] = 1;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        ans = 1;
        dfs(1, 0);
        printf("%lld\n", ans);
        /*int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].size() != 1) cnt[pre[i]]++;
            else if (i != 1) ans++, lvs[pre[i]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) if (lvs[i] && !cnt[i] && i != 1) q.push(i);
        vector<pii> upds;
        while (q.size()) {
            int cur = q.front(); q.pop();
            printf("%d\n", cur);
            upd(in[cur], 1), upd(out[cur], -1);
            upds.push_back({in[cur], -1}), upds.push_back({out[cur], 1});
            if (lvs[pre[cur]] || cnt[pre[cur]] > 1 || pre[cur] == 1) {
                ans--;
                //if (lvs[pre[cur]] && !cnt[pre[cur]] && pre[cur] != 1) q.push(pre[cur]);
            }
            cnt[pre[cur]]--;
            if (!cnt[pre[cur]] && pre[cur] != 1) {
                if (lvs[pre[cur]]) q.push(pre[cur]);
                else {
                    lvs[pre[pre[cur]]]++;
                    cnt[pre[pre[cur]]]--;
                    if (lvs[pre[pre[cur]]] && !cnt[pre[pre[cur]]] && pre[pre[cur]] > 1) q.push(pre[pre[cur]]);
                }
            }
        }
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) if (a[i].size() == 1 && i != 1) mn = min(mn, qry(in[i]));
        printf("%lld\n", ans + mn);*/
        for (int i = 1; i <= n; i++) {
            rem[i] = 0;
            a[i].clear();
        }
        //for (pii p : upds) upd(p.f, p.s);
    }

    return 0;
}