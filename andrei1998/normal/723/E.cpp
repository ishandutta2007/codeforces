#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 200 + 5;
const int MMAX = NMAX * NMAX / 2;

struct Edge {
    int a, b;
    bool vis;

    inline void orient(int node) {
        if (a != node)
            swap(a, b);
    }

    inline int other(int node) {
        return a ^ b ^ node;
    }
} edges[MMAX];

vector <int> graph[NMAX];

void rectify(int node) {
    while (!graph[node].empty() && edges[graph[node].back()].vis)
        graph[node].pop_back();
}

void parc(int node) {
    rectify(node);
    while (!graph[node].empty()) {
        int other = edges[graph[node].back()].other(node);
        edges[graph[node].back()].orient(node);
        edges[graph[node].back()].vis = true;
        graph[node].pop_back();

        node = other;
        rectify(node);
    }
}

int deg[NMAX];

void test() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        deg[i] = 0;

    for (int i = 1; i <= m; ++ i) {
        cin >> edges[i].a >> edges[i].b;
        edges[i].vis = false;

        ++ deg[edges[i].a];
        ++ deg[edges[i].b];

        graph[edges[i].a].push_back(i);
        graph[edges[i].b].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans += (deg[i] & 1);

    for (int i = 1; i <= n; ++ i)
        if (deg[i] & 1) {
            rectify(i);
            parc(i);
        }


    for (int i = 1; i <= n; ++ i) {
        rectify(i);
        while (!graph[i].empty()) {
            parc(i);
            rectify(i);
        }
    }

    cout << n - ans << '\n';
    for (int i = 1; i <= m; ++ i)
        cout << edges[i].a << ' ' << edges[i].b << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int t = 0;
    cin >> t;

    while (t --)
        test();

    return 0;
}