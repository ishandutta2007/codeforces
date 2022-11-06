#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Edge {
    int id, u, v, w;
};

const int MxN = (int) 2e5 + 9;
const ll Inf = MxN * (ll) 1e9 + 9;

vector<Edge> adj[MxN + 9];
Edge edges[MxN + 9];
ll dist1[MxN + 9];
ll distN[MxN + 9];
int parent1[MxN + 9];
int parentN[MxN + 9];
int nodePos[MxN + 9];
int edgePos[MxN + 9];
ll dp[MxN + 9];

void Dijkstra(const int start, ll *dist, int *parent) {
    fill(dist, dist + MxN, Inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(dist[start] = 0, start);

    while (!pq.empty()) {
        const ll du = pq.top().first;
        const int u = pq.top().second;
        pq.pop();
        if (du != dist[u])
            continue;

        for (const Edge &e : adj[u]) {
            const int v = e.v;
            const int w = e.w;
            if (dist[v] > dist[u] + w) {
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void fixParent(int i, int *parent) {
    if (nodePos[i] != -1) {
        parent[i] = i;
        return;
    }
    if (!parent[i])
        return;
    fixParent(parent[i], parent);
    parent[i] = parent[parent[i]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; ++i) {
        Edge &e = edges[i];
        e.id = i;
        cin >> e.u >> e.v >> e.w;
        for (int rep = 0; rep < 2; ++rep) {
            adj[e.u].push_back(e);
            swap(e.u, e.v);
        }
    }

    Dijkstra(1, dist1, parent1);
    Dijkstra(N, distN, parentN);

    memset(nodePos, -1, sizeof nodePos);
    memset(edgePos, -1, sizeof edgePos);
    vector<int> nodePath = {1};
    vector<int> edgePath;
    nodePos[1] = 0;
    for (;;) {
        const int u = nodePath.back();
        if (u == N) break;
        const int v = parentN[u];
        for (const Edge &e : adj[u]) {
            if (e.v == v && e.w == distN[u] - distN[v]) {
                nodePos[e.v] = (int) nodePath.size();
                edgePos[e.id] = (int) edgePath.size();
                nodePath.push_back(e.v);
                edgePath.push_back(e.id);
                break;
            }
        }
        assert(nodePath.back() == v);
    }

/*
    for(int i = 0; i < M; ++i) {
        Edge &e = edges[i];
        if(dist1[e.u] > dist1[e.v])
            swap(e.u, e.v);
    }
*/

    for (int i = 1; i <= N; ++i) {
        fixParent(i, parent1);
        fixParent(i, parentN);
    }

    {
        static vector<ll> startEvents[MxN + 9];
        static vector<ll> endEvents[MxN + 9];
        for (int i = 0; i < M; ++i) {
            Edge e = edges[i];
            if (edgePos[e.id] != -1)
                continue;
            for (int rep = 0; rep < 2; ++rep, swap(e.u, e.v)) {
                const int left = parent1[e.u];
                const int right = parentN[e.v];
                assert(!left == !right);
                if (!left || !right)
                    continue;
                assert(nodePos[left] != -1 && nodePos[right] != -1);
                if (nodePos[left] >= nodePos[right])
                    continue;
                const ll w = dist1[e.u] + e.w + distN[e.v];
                assert(w < Inf);
                startEvents[nodePos[left]].push_back(w);
                endEvents[nodePos[right] - 1].push_back(w);
            }
        }
        multiset<ll> ms = {Inf};
        for (int i = 0; i < MxN; ++i) {
            for (ll x: startEvents[i])
                ms.insert(x);

            assert(!ms.empty());
            dp[i] = *ms.begin();

            for (ll x: endEvents[i]) {
                auto it = ms.find(x);
                assert(it != ms.end());
                ms.erase(it);
            }
        }
        assert(ms == multiset<ll>{Inf});
    }

    while (Q--) {
        int i, newW;
        cin >> i >> newW;
        const Edge &e = edges[--i];

        ll ans = Inf;
        ans = min(ans, dist1[e.u] + newW + distN[e.v]);
        ans = min(ans, dist1[e.v] + newW + distN[e.u]);

        if (newW <= e.w || edgePos[e.id] == -1)
            ans = min(ans, distN[1]);
        else {
            const int pos = min(nodePos[e.u], nodePos[e.v]);
            ans = min(ans, dp[pos]);
        }
        cout << ans << '\n';
    }
    return 0;
}