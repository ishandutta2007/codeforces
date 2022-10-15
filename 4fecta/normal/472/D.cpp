#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005;

int n, d[MN][MN], dist[MN][MN], par[MN];
vector<pii> a[MN];
vector<pair<int, pii>> edges;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

void dijk(int st) {
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, st});
    dist[st][st] = 0;
    while (q.size()) {
        pii cur = q.top(); q.pop();
        if (cur.f > dist[st][cur.s]) continue;
        for (pii nxt : a[cur.s]) {
            //printf("bruh\n");
            if (dist[st][nxt.f] > dist[st][cur.s] + nxt.s) {
                dist[st][nxt.f] = dist[st][cur.s] + nxt.s;
                q.push({dist[st][nxt.f], nxt.f});
            }
        }
    }
}

int main() {
    boost();

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < MN; i++) par[i] = i;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i][i]) {printf("NO\n"); return 0;}
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (d[i][j] != d[j][i] || d[i][j] <= 0) {printf("NO\n"); return 0;}
            edges.push_back({d[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for (auto p : edges) {
        if (merge(p.s.f, p.s.s)) {
            cnt++;
            //printf("br1");
            a[p.s.f].push_back({p.s.s, p.f});
            a[p.s.s].push_back({p.s.f, p.f});
        }
        if (cnt == n - 1) break;
    }
    for (int i = 1; i <= n; i++) {
        dijk(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //printf("%d ", dist[i][j]);
            if (d[i][j] != dist[i][j]) {printf("NO\n"); return 0;}
        }
        //printf("\n");
    }
    printf("YES\n");


    return 0;
}