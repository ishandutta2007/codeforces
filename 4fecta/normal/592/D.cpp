#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 130005;

int n, m, u, v;
vector<int> a[MN];
bool tree[MN];
bool pho[MN];
int dist[MN], dist1[MN];
stack<int> s;
int st, cnt = -1;

void dfs(int cur, int par) {
    s.push(cur);
    if (pho[cur]) {
        while (s.size()) {
            tree[s.top()] = 1;
            s.pop();
        }
    }
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
    }
    if (s.size()) {
        s.pop();
    }
}

void dfs1(int cur, int par, int d) {
    dist[cur] = d;
    for (int i : a[cur]) {
        if (i == par || !tree[i]) continue;
        dfs1(i, cur, d + 1);
    }
}

void dfs2(int cur, int par, int d) {
    dist1[cur] = d;
    for (int i : a[cur]) {
        if (i == par || !tree[i]) continue;
        dfs2(i, cur, d + 1);
    }
}

int main() {
    boost();

    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        cin >> u;
        if (m == 1) return 0 * printf("%d\n0", u);
        u--;
        tree[u] = 1;
        pho[u] = 1;
        st = u;
    }
    

    dfs(st, -1);

    for (int i = 0; i < n; i++) {
        if (tree[i]) {
            cnt++;
            //printf("%d ", i);
        }
    }
    //printf("\n");

    dfs1(st, -1, 0);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx && tree[i]) {
            mx = dist[i];
            st = i;
        }
    }

    dfs2(st, -1, 0);
    mx = -1;
    for (int i = 0; i < n; i++) {
        if (dist1[i] > mx && tree[i]) {
            mx = dist1[i];
            st = i;
        }
    }
    dfs1(st, -1, 0);
    //printf("%d\n", mx);
    for (int i = 0; i < n; i++) {
        if (max(dist[i], dist1[i]) == mx) {
            printf("%d\n", i + 1);
            break;
        }
    }

    printf("%d\n", cnt * 2 - mx);

    return 0;
}