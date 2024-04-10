
#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

#define int li
//const int mod = 1000000007;

struct Graph {
    int n = 0;
    vector<vector<int>> e;
    vector<char> used;
    vector<int> match;

    bool kuhn(int v) {
        if (used[v]) {
            return false;
        }

        used[v] = true;

        for (int u : e[v]) {
            if (match[u] == -1 || kuhn(match[u])) {
                match[u] = v;
                return true;
            }
        }

        return false;
    }

    int getMaxMatching() {
        match.assign(n, -1);

        int matching = 0;
        for (int i = 0; i < n; ++i) {
            used.assign(n, false);
            if (kuhn(i)) {
                ++matching;
            }
        }

        return matching * 2;
    }
};

Graph getGraph(int n, int m) {
    Graph g;
    g.n = n * m;
    g.e.resize(g.n);

    auto get = [&](int i, int j) {
        return i * m + j;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2) {
                continue;
            }

            for (int dx = -3; dx <= 3; ++dx) {
                for (int dy = -3; dy <= 3; ++dy) {
                    if (abs(dx) + abs(dy) != 3) {
                        continue;
                    }

                    int x = i + dx, y = j + dy;
                    if (x >= n || y >= m || x < 0 || y < 0) continue;

                    g.e[get(i, j)].push_back(get(x, y));
                }
            }
        }
    }

    return g;
}

int getAnswer(int n, int m) {
    return getGraph(n, m).getMaxMatching();
}

int xDeficit(int n, int m) {
    /*
1 2 3 2 1 0 1 2 3 2
2 4 2 0 0 0 2 0 0 0
3 2 1 0 1 0 1 0 1 0
2 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 1 0 1 0
0 0 0 0 0 0 0 0 0 0
1 2 1 0 1 0 1 0 1 0
2 0 0 0 0 0 0 0 0 0
3 0 1 0 1 0 1 0 1 0
2 0 0 0 0 0 0 0 0 0
     */

    if (n == 1 || m == 1) {
        int ord = max(n, m) % 6;
        if (ord <= 3) {
            return ord;
        } else {
            return 6 - ord;
        }
    }

    if (min(n, m) == 2 && max(n, m) == 7) {
        return 2;
    }

    if (n + m == 3) {
        return 2;
    }
    if (n + m == 4) {
        return n % 2 == 0 ? 4 : 3;
    }
    if (n + m == 5) {
        return 2;
    }
    return (n % 2 == 1 && m % 2 == 1) ? 1 : 0;
}

void solve(__attribute__((unused)) bool read) {
    int n, m;
    cin >> n >> m;
    cout << n * (li)m - xDeficit(n, m) << endl;
#if 0
    cout << getAnswer(n, m) << endl;

    assert(getAnswer(2, 2) == 0);
    assert(getAnswer(3, 3) == 8);
    assert(getAnswer(3, 6) == 18);

    /*

    for ()*/

    for (int n = 1; n <= 20; ++n) {
        for (int m = 1; m <= 20; ++m) {
            int deficit = n * m - getAnswer(n, m);
            cout << deficit << " ";
        }
        cout << endl;
    }

    for (int n = 1; n <= 30; ++n) {
        for (int m = 1; m <= 30; ++m) {
            int deficit = xDeficit(n, m);
            assert(deficit == n * m - getAnswer(n, m));
            cout << deficit << " ";
        }
        cout << endl;
    }
#endif
}