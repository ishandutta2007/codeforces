#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 505;

int deg[NMAX];
bool graph[NMAX][NMAX];
bool mid[NMAX];

int father[NMAX];

char code[NMAX];

void noSol() {
    cout << "No\n";
    exit(0);
}

int find(int x) {
    int y, p;
    for (y = father[x]; y != father[y]; y = father[y]);
    for (; x != y; x = p) {
        p = father[x];
        father[x] = y;
    }
    return y;
}

int unite(int x, int y) {
    father[find(x)] = find(y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m-- > 0) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x][y] = graph[y][x] = true;
        deg[x]++;
        deg[y]++;
    }

    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] == n - 1) {
            mid[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (mid[i]) continue;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (mid[j]) {
                if (!graph[i][j]) noSol();
            } else {
                if (graph[i][j]) {
                    unite(i, j);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (mid[i]) continue;
        if (father[i] == i) {
            code[i] = (cnt == 0 ? 'a': 'c');
            cnt++;
        }
    }

    if (cnt > 2) noSol();

    for (int i = 0; i < n; ++i) {
        if (mid[i]) continue;
        for (int j = 0; j < n; ++j) {
            if (i == j || mid[j]) continue;
            if (find(i) == find(j)) {
                if (!graph[i][j]) noSol();
            } else {
                if (graph[i][j]) noSol();
            }
        }
    }

    string fans(n, 0);
    for (int i = 0; i < n; ++i) {
        if (mid[i]) {
            fans[i] = 'b';
        } else {
            fans[i] = code[find(i)];
        }
    }

    cout << "Yes\n";
    cout << fans << '\n';
}