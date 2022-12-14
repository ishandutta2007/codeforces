#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Line;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

int n;
vector<pair<int,int>> g[MAXN];
ll dp[MAXN][22];
ll a[MAXN], b[MAXN];

long double intersect(Line a, Line b) {
    return 1.0 * (b.second - a.second) / (a.first - b.first);
}

long long get(Line a, int x) {
    return 1LL * a.first * x + a.second;
}

void use_flight(int k) {
    vector<Line> lines;
    for (int i = 1; i <= n; i++)
        lines.push_back({-2 * i, dp[i][k - 1] + 1LL * i * i});
    vector<Line> CHT;
    for (Line l : lines) {
        int sz = CHT.size();
        while (sz > 1 and intersect(CHT[sz - 2], CHT[sz - 1]) >= intersect(CHT[sz - 1], l)) {
            sz--;
            CHT.pop_back();
        }
        CHT.push_back(l);
    }
    int best = 0;
    for (int i = 1; i <= n; i++) {
        while (best + 1 < CHT.size() and get(CHT[best], i) >= get(CHT[best + 1], i))
            best++;
        dp[i][k] = get(CHT[best], i) + 1LL * i * i;
    }
}

void dijkstra(int k) {
    set<pair<int,int>> S;
    for (int i = 1; i <= n; i++)
        S.insert({dp[i][k], i});
    while (!S.empty()) {
        int v = (*S.begin()).second;
        S.erase(S.begin());
        for (auto [u, w] : g[v]) {
            if (dp[u][k] > dp[v][k] + w) {
                S.erase({dp[u][k], u});
                dp[u][k] = dp[v][k] + w;
                S.insert({dp[u][k], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        dp[i][0] = INF;
    dp[1][0] = 0;
    dijkstra(0);
    for (int i = 1; i <= k; i++) {
        use_flight(i);
        dijkstra(i);
    }
    for (int i = 1; i <= n; i++) {
        ll answer = INF;
        for (int j = 0; j <= k; j++)
            answer = min(answer, dp[i][j]);
        cout << answer << " \n"[i == n];
    }
}