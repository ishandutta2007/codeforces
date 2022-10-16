#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

#define MaxN 500005
#define MaxE 1000010

struct DisjointSets {
    int root[MaxN];
    int height[MaxN];
    pair <int, int> extremeNodes[MaxN];

    DisjointSets(int N = MaxN) {
        for (int i = 0; i < N; i++) {
            root[i] = i;
            height[i] = 1;
            extremeNodes[i] = make_pair(i, i);
        }
    }

    int getRoot(int node) {
        int r = node;
        while (r != root[r]) {
            r = root[r];
        }
        while (node != root[node]) {
            const int son = root[node];
            root[node] = r;
            node = son;
        }
        return r;
    }

    void unionSet(int u, int v) {
        u = getRoot(u); v = getRoot(v);

        if (u == v) {
            return;
        }

        if (height[u] < height[v]) {
            swap(u, v);
        }
        height[u] += (height[u] == height[v]);
        root[v] = u;
        if (extremeNodes[u].first > extremeNodes[v].first) {
            extremeNodes[u].first = extremeNodes[v].first;
        }
        if (extremeNodes[u].second < extremeNodes[v].second) {
            extremeNodes[u].second = extremeNodes[v].second;
        }
    }

    pair <int, int> getExtremeNodes(int node) {
        return extremeNodes[getRoot(node)];
    }
};

struct Edge {
    int u, v;
    int cost;

    Edge() {
    };

    Edge(int a, int b, int weight) : u(a), v(b), cost(weight) {
    };
};

struct EdgeManager {
    Edge heap[MaxE];

    int heapSize;

    EdgeManager() {
        heapSize = 0;
    }

    Edge getMin() const {
        return heap[0];
    }

    void insertEdge(int a, int b, int weight) {
        assert(heapSize < MaxE);
        heap[heapSize] = Edge(a, b, weight);
        int node = heapSize++;
        while (node > 0 && heap[(node - 1) / 2].cost > heap[node].cost) {
            swap(heap[(node - 1) / 2], heap[node]);
            node = (node - 1) / 2;
        }
    }

    void popMin() {
        assert(heapSize > 0);
        heap[0] = heap[--heapSize];
        int node = 0;
        int best, changed;
        do {
            changed = false;
            best = node;
            if (2 * node + 1 < heapSize && heap[2 * node + 1].cost < heap[best].cost) {
                best = 2 * node + 1;
            }
            if (2 * node + 2 < heapSize && heap[2 * node + 2].cost < heap[best].cost) {
                best = 2 * node + 2;
            }
            if (best != node) {
                swap(heap[best], heap[node]);
                node = best;
                changed = true;
            }
        } while (changed);
    }
};

int v[MaxN];
int N, K;
EdgeManager bipartiteMatching;
DisjointSets rangerForestLine, rangerForestDiagonal;
bool used[MaxN];
long long sp[MaxN];

void ReadInput() {
    scanf("%d%d", &K, &N);
    for (int i = 0; i < N; i++)
        scanf("%d", v + i);
    sort(v, v + N);
}

void Solve() {
    for (int i = 1; i < N; i++) {
        bipartiteMatching.insertEdge(i - 1, i, ((v[i] - v[i - 1]) << 1) | (not(i == 1 || i == N - 1)));
        if (i % 2 == 1) {
            sp[i] = sp[i - 1] + v[i] - v[i - 1];
        } else {
            sp[i] = sp[i - 1] + v[i - 1] - v[i];
        }
    }

    long long cost = 0LL;

    for (int i = 0; i < K; i++) {
        Edge E;
        do {
            E = bipartiteMatching.getMin();
            bipartiteMatching.popMin();
        } while (used[E.u] || used[E.v]);
        cost = cost + (E.cost >> 1);
        used[E.u] = true; used[E.v] = true;
        //fprintf(stderr, "%d %d %d\n", 1 + E.u, 1 + E.v, E.cost >> 1);
        if (!(E.cost & 1)) {
            continue;
        }

        pair <int, int> extremeNodes;

        if (E.u % 2 == 1) {
            rangerForestDiagonal.unionSet(E.u, E.v);
            for (int j = -1; j <= 1; j += 2) {
                if (E.u + j >= 0 && E.u + j < N) {
                    rangerForestDiagonal.unionSet(E.u, E.u + j);
                }
                if (E.v + j >= 0 && E.v + j < N) {
                    rangerForestDiagonal.unionSet(E.v, E.v + j);
                }
            }
            extremeNodes = rangerForestDiagonal.getExtremeNodes(E.u);
        } else {
            rangerForestLine.unionSet(E.u, E.v);
            for (int j = -1; j <= 1; j += 2) {
                if (E.u + j >= 0 && E.u + j < N) {
                    rangerForestLine.unionSet(E.u, E.u + j);
                }
                if (E.v + j >= 0 && E.v + j < N) {
                    rangerForestLine.unionSet(E.v, E.v + j);
                }
            }
            extremeNodes = rangerForestLine.getExtremeNodes(E.u);
        }

        if (extremeNodes.first % 2 != extremeNodes.second % 2) {
            //fprintf(stderr, "%d %d\n", extremeNodes.first + 1, extremeNodes.second + 1);
            if (extremeNodes.first % 2 == 0) {
                bipartiteMatching.insertEdge(extremeNodes.first, extremeNodes.second,
                                             ((sp[extremeNodes.second] - sp[extremeNodes.first]) << 1) | 1);
            } else {
                bipartiteMatching.insertEdge(extremeNodes.first, extremeNodes.second,
                                             ((-sp[extremeNodes.second] + sp[extremeNodes.first]) << 1) | 1);
            }
        }
    }
    printf("%lld\n", cost);
}

int main() {
    ReadInput();
    Solve();
    return 0;
}