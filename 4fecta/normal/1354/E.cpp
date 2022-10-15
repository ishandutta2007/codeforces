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

const int MN = 5005;

int n, m, u, v, col[MN], cnt1, cnt2, cnt3, cmp = 1, id[MN], dp[MN][MN], back[MN][MN], num[MN], num1[MN];
vector<int> a[MN];
vector<pii> sz[MN];

void dfs(int cur) {
    if (id[cur]) return;
    id[cur] = cmp;
    for (int nxt : a[cur]) dfs(nxt);
}

void clear(int cur) {
    if (!col[cur]) return;
    col[cur] = 0;
    for (int nxt : a[cur]) clear(nxt);
}

int opp(int x) {
    return x == 1 ? 2 : 1;
}

void check(int st) {
    clear(st);
    queue<pii> q;
    int cnt = 0;
    bool bad = 0;
    q.push({st, 1});
    col[st] = 1;
    int size = 1;
    while (q.size()) {
        pii cur = q.front(); q.pop();
        for (int nxt : a[cur.f]) {
            if (col[nxt] && col[nxt] != opp(cur.s)) bad = 1;
            if (col[nxt]) continue;
            size++;
            col[nxt] = opp(cur.s);
            if (col[nxt] == 2) cnt++;
            q.push({nxt, opp(cur.s)});
        }
    }
    if (bad) return;
    sz[id[st]].push_back({st, cnt});
    sz[id[st]].push_back({st, size - cnt});
    num[st] = cnt;
    num1[st] = size - cnt;
}

void fill(int st, int colo) {
    clear(st);
    queue<pii> q;
    q.push({st, colo});
    col[st] = colo;
    while (q.size()) {
        pii cur = q.front(); q.pop();
        for (int nxt : a[cur.f]) {
            if (col[nxt]) continue;
            col[nxt] = opp(cur.s);
            q.push({nxt, opp(cur.s)});
        }
    }
}

void proc(int cnt2) {
    printf("YES\n");
    int track = back[cmp - 1][cnt2];
    int i = cmp - 1, j = cnt2;
    while (track) {
        //printf("%d\n", track);
        int sz = num[track];
        if (dp[i - 1][j - sz]) {
            fill(track, 1);
            track = back[i - 1][j - sz], i--, j -= sz;
        }
        else {
            fill(track, 2);
            sz = num1[track], track = back[i - 1][j - sz], i--, j -= sz;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1 && cnt3 > 0) col[i] = 3, cnt3--;
        printf("%d", col[i]);
    }
}

int main() {
    boost();

    cin >> n >> m >> cnt1 >> cnt2 >> cnt3;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i), cmp++;
    }
    for (int i = 1; i <= n; i++) {
        check(i);
    }
    dp[0][0] = 1;
    for (int i = 1; i < cmp; i++) {
        //printf("%d\n", sz[i].size());
        for (pii p : sz[i]) {
            for (int j = 0; j <= n; j++) {
                if (p.s <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - p.s]);
                    if (dp[i][j] && dp[i - 1][j - p.s]) back[i][j] = p.f;
                }
            }
        }
    }
    //bool can = dp[cmp - 1][cnt1] || dp[cmp - 1][cnt2] || dp[cmp - 1][cnt3];
    //if (dp[cmp - 1][cnt1]) {proc(cnt1); return 0;}
    if (dp[cmp - 1][cnt2]) {proc(cnt2); return 0;}
    //if (dp[cmp - 1][cnt3]) {proc(cnt3); return 0;}
    printf("NO\n");

    return 0;
}
/*
9 9
2 3 4
1 2
2 5
3 5
5 6
5 7
6 8
7 4
7 8
8 9
 */