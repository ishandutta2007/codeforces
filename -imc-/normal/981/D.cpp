#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

bool isp(string s) {
    string x = s;
    reverse(all(x));
    return x == s;
}

vector<int> deg;
vector<vector<int>> e;
vector<vector<int>> paths;

void dfs(int v, int p) {
    bool one = true;
    for (int u: e[v]) {
        if (u == p) continue;

        if (p != -1 && !one) {
            cout << "No\n";
            exit(0);
        }

        if (p == -1) {
            paths.emplace_back();
        }

        paths.back().push_back(u);

        dfs(u, v);
        one = false;
    }
}

void solve(bool __attribute__((unused)) read) {
    int n, k;
    cin >> n >> k;

    vector<li> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int numNodes = (n + 1) * (k + 1);
    vector<vector<int>> e(numNodes);

    auto getNode = [&](int i, int parts) {
        return parts * (n + 1) + i;
    };

    li curMask = 0;
    li curWant = 0;

    auto build = [&]() {
        e.clear();
        e.resize(numNodes);

        for (int i = 0; i < n; ++i) {
            li sum = 0;
            for (int r = i + 1; r <= n; ++r) {
                sum += a[r - 1];

                if (((sum & curMask) & curWant) != curWant) {
                    continue;
                }

                for (int j = 0; j < k; ++j)
                    e[getNode(i, j)].push_back(getNode(r, j + 1));
            }
        }
    };

    vector<char> can(numNodes, false);

    auto canReach = [&]() {
        can.assign(numNodes, false);
        can[numNodes - 1] = true;

        for (int i = numNodes - 1; i >= 0; --i) {
            for (int u: e[i]) {
                assert(u > i);
                if (can[u]) {
                    can[i] = true;
                    break;
                }
            }

            if (can[i]) {
                //cout << "can reach " << i / (n + 1) << " parts, " << i % (n + 1) << endl;
            }
        }

        return can[0];
    };

    build();
    assert(canReach());

    for (int bit = 60; bit >= 0; --bit) {
        curMask |= 1LL << bit;
        curWant |= 1LL << bit;

        build();
        if (!canReach()) {
            curWant &= ~(1LL << bit);
        }
    }

    cout << curWant << endl;
}