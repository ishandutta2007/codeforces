#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

struct Edge {
    int x, y, pos;
    Edge(int _x, int _y, int _pos):
        x(_x), y(_y), pos(_pos) {}
};

int find(vector<int>& father, int x) {
    int y, p;
    for (y = father[x]; y != father[y]; y = father[y]);
    for (; x != y; x = p) {
        p = father[x];
        father[x] = y;
    }
    return y;
}

void unite(vector<int>& father, int x, int y) {
    father[find(father, x)] = find(father, y);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    if ((N & 1) == 0) {
        cout << "-1\n";
        return 0;
    }

    vector<Edge> edges[2], allEdges;
    for (int i = 1; i <= M; ++i) {
        int x, y; char c;
        cin >> x >> y >> c;
        //if (x != y) {
            edges[c == 'S' ? 0: 1].push_back(Edge(x, y, i));
            allEdges.push_back(Edge(x, y, i));
        //}
    }

    vector<int> father(N + 1);
    for (int i = 1; i <= N; ++i) father[i] = i;

    for (Edge& p: edges[0]) {
        if (find(father, p.x) != find(father, p.y)) {
            unite(father, p.x, p.y);
        }
    }
    vector<int> ans;
    for (Edge& p: edges[1]) {
        if (find(father, p.x) != find(father, p.y)) {
            ans.push_back(p.pos);
            unite(father, p.x, p.y);
        }
    }
    if (int(ans.size()) > N / 2) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= N; ++i) father[i] = i;
    for (int edge: ans) {
        Edge& p = allEdges[edge - 1];
        if (find(father, p.x) != find(father, p.y)) {
            unite(father, p.x, p.y);
        }
    }
    for (auto& p: edges[1]) {
        if (int(ans.size()) == N / 2) break;
        if (find(father, p.x) != find(father, p.y)) {
            ans.push_back(p.pos);
            unite(father, p.x, p.y);
        }
    }
    if (int(ans.size()) < N / 2) {
        cout << "-1\n";
        return 0;
    }
    for (auto& p: edges[0]) {
        if (find(father, p.x) != find(father, p.y)) {
            ans.push_back(p.pos);
            unite(father, p.x, p.y);
        }
    }
    if (int(ans.size()) < N - 1) {
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << '\n';
    for (int p: ans) cout << p << ' ';
    cout << '\n';
}