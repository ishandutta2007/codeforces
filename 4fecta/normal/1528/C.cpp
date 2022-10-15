#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 600005;

int t, n, p1[MN], p2[MN], in[MN], out[MN], tim = 1, bit[MN][2], ins[MN], rem[MN], ans, cnt; //0 = above us, 1 = below us
vector<int> a1[MN], a2[MN];

void upd(int t, int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i][t] += val;
}

int qry(int t, int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i][t];
    return ret;
}

void dfs(int cur) {
    in[cur] = tim++;
    for (int nxt : a2[cur]) dfs(nxt);
    out[cur] = tim++;
}

bool below(int cur) {
    return qry(1, out[cur]) - qry(1, in[cur]) != 0;
}

int above(int cur) {
    return qry(0, in[cur]);
}

void ins_node(int cur) {
    upd(0, in[cur], cur);
    upd(0, out[cur], -cur);
    upd(1, in[cur], 1);
    cnt++;
}

void rem_node(int cur) {
    upd(0, in[cur], -cur);
    upd(0, out[cur], cur);
    upd(1, in[cur], -1);
    cnt--;
}

void solve(int cur) {
    if (!below(cur)) {
        int tmp = above(cur);
        if (tmp) rem[cur] = tmp, rem_node(tmp);
        ins[cur] = cur;
        ins_node(cur);
    }
    ans = max(ans, cnt);
    for (int nxt : a1[cur]) solve(nxt);
    if (ins[cur]) rem_node(ins[cur]);
    if (rem[cur]) ins_node(rem[cur]);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            cin >> p1[i];
            a1[p1[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            cin >> p2[i];
            a2[p2[i]].push_back(i);
        }
        dfs(1);
        solve(1);
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) {
            a1[i].clear();
            a2[i].clear();
            ins[i] = rem[i] = in[i] = out[i] = p1[i] = p2[i] = 0;
        }
        tim = 1;
        ans = cnt = 0;
        assert(!qry(0, MN - 1));
        assert(!qry(1, MN - 1));
    }

    return 0;
}