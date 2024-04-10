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

struct query {
    int l, r, idx;
};

const int MN = 505, MM = 10005;

int n, m, Q, u, v, par[MN][2], ans[MM * 2];
pii edge[MM];
vector<query> q;

int find(int x, int t) {
    if (x == par[x][t]) return x;
    return par[x][t] = find(par[x][t], t);
}

bool merge(int x, int y, int t) {
    x = find(x, t), y = find(y, t);
    if (x == y) return false;
    par[x][t] = par[y][t];
    return true;
}

bool cmp(query x, query y) {
    if (x.l ^ y.l) return x.l < y.l;
    return x.r > y.r;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 0; i < MN; i++) par[i][0] = par[i][1] = i;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].f >> edge[i].s;
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        query tmp;
        cin >> tmp.l >> tmp.r;
        tmp.idx = i;
        q.push_back(tmp);
    }
    sort(q.begin(), q.end(), cmp);
    int cnt = n, cnt2 = n;
    int lft = 0, rit = m + 1;
    for (query p : q) {
        //printf("%d %d\n", p.l, p.r);
        if (lft != p.l - 1) {
            while (lft < p.l - 1) {
                lft++;
                if (merge(edge[lft].f, edge[lft].s, 0)) cnt--;
            }
            cnt2 = cnt;
            for (int i = 1; i <= n; i++) par[i][1] = par[i][0];
            rit = m + 1;
        }
        while (rit > p.r + 1) {
            rit--;
            if (merge(edge[rit].f, edge[rit].s, 1)) cnt2--;
        }
        ans[p.idx] = cnt2;
    }
    for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);

    return 0;
}