#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

#define M 1001000
#define INF 1000000000

int n, st, t, m, d[M], mn[M], mx[M], p[M];
vector<int> in[M];
int q[2 * M];
int f = M, s = M;
bool u[M];

void read() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        ++p[x];
        in[y].push_back(x);
    }
    cin >> st >> t;
}

void relax(int v) {
    u[v] = true;
    for (int &to : in[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                //q.push_back(to);
                q[f++] = to;
            }
            mx[to] = max(mx[to], d[v]);
            mn[to] = min(mn[to], d[v]);
            --p[to];
            if (p[to] == 0 && mn[to] == mx[to] && d[to] > d[v]) {
                //q.push_front(to);
                q[--s] = to;
                d[to] = d[v];
            }
        }
}

void run() {
    fill(d, d + M, INF);
    fill(mn, mn + M, INF);
    fill(mx, mx + M, -INF);
    d[t] = 0;
    //q.push_back(t);
    q[f++] = t;

    while (s != f) {
        int v = q[s];//q.front();
        ++s;//q.pop_front();
        if (u[v])
            continue;
        relax(v);
    }

    if (d[st] == INF)
        cout << "-1\n";
    else
        cout << d[st] << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    run();


    return 0;
}