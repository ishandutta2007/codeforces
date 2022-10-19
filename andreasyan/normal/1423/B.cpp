///////////////////////////////     _LeMur_
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

const int N = 30005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector < pair< int, pair<int, int> > > mas;

struct edge {
    int a, b, c, flow;
};

vector <edge> G;
vector <int> g[N];
int S, T;

void add_edge(int a, int b, int c) {
    edge e1 = {a, b, c, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)G.size());
    G.push_back(e1);
    g[b].push_back((int)G.size());
    G.push_back(e2);
}

int d[N];

bool bfs() {
    for (int i = S; i <= T; i++) d[i] = -1;
    queue <int> q;
    d[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int)g[v].size(); i++) {
            int id = g[v][i];
            int to = G[id].b;
            if (G[id].flow == G[id].c) continue;
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    return d[T] != -1;
}

int pos[N];

int dfs(int v, int flow) {
    if (v == T || flow == 0) return flow;
    for (; pos[v] < (int)g[v].size(); pos[v]++) {
        int id = g[v][ pos[v] ];
        int to = G[id].b;
        if (d[to] != d[v] + 1) continue;
        int x = dfs(to, min(flow, G[id].c - G[id].flow));
        if (x != 0) {
            G[id].flow += x;
            G[id ^ 1].flow -= x;
            return x;
        }
    }
    return 0;
}

int max_flow() {
    int answ = 0;
    while (bfs()) {
        for (int i = S; i <= T; i++) pos[i] = 0;
        while (true) {
            int x = dfs(S, inf);
            if (x == 0) break;
            answ += x;
        }
    }
    return answ;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        mas.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(mas.begin(), mas.end());

    S = 0, T = 2 * n + 1;

    int ina = 0, inb = (int)mas.size() - 1;
    int pat = -1;

    while (ina <= inb) {
        int mid = (ina + inb) / 2;

        G.clear();
        for (int i = S; i <= T; i++) {
            g[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            add_edge(S, i, 1);
            add_edge(i + n, T, 1);
        }

        for (int i = 0; i <= mid; i++) {
            add_edge(mas[i].second.first, mas[i].second.second + n, 1);
        }

        if (max_flow() == n) {
            pat = mas[mid].first;
            inb = mid - 1;
        } else {
            ina = mid + 1;
        }
    }

    cout << pat << endl;
    return 0;
}