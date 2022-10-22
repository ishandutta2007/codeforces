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
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
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

//#define int li
//const int mod = 1000000007;

struct dp {
    li sumlen = 0;
    int cnt[2] = {};
};

vector<dp> dpDown;
vector<vector<int>> e;

void dpAddChild(dp& to, dp x, int sign = 1) {
    to.sumlen += x.sumlen * sign;
    for (int t = 0; t < 2; ++t) {
        to.cnt[t] += x.cnt[1 - t] * sign;
        to.sumlen += x.cnt[t] * sign;
    }
    to.sumlen += sign;
    to.cnt[1] += sign;
}

void dfsDown(int v, int p) {
    for (int u : e[v]) {
        if (u == p) {
            continue;
        }

        dfsDown(u, v);
        dpAddChild(dpDown[v], dpDown[u]);
    }
    //cout << "at " << v + 1 << " got down " << dpDown[v].sumlen << " " << dpDown[v].cnt[0] << " " << dpDown[v].cnt[1] << endl;
}

li ans = 0;

void secondDfs(int v, int p, dp upDp) {
    dp sumDp;
    if (p != -1) {
        dpAddChild(sumDp, upDp);
    }
    for (int u : e[v]) {
        if (u == p) {
            continue;
        }

        dpAddChild(sumDp, dpDown[u]);
    }

    //cout << "at " << v + 1 << " got " << sumDp.sumlen << " " << sumDp.cnt[0] << " " << sumDp.cnt[1] << endl;

    ans += (sumDp.sumlen + sumDp.cnt[1]) / 2;

    for (int u : e[v]) {
        if (u == p) {
            continue;
        }

        dpAddChild(sumDp, dpDown[u], -1);
        secondDfs(u, v, sumDp);
        dpAddChild(sumDp, dpDown[u], +1);
    }
}

void solve(__attribute__((unused)) bool read) {
    read = true;

    int n;
    if (read) {
        cin >> n;
    } else {
        n = 200000;
    }

    e.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        if (read) {
            cin >> u >> v;
            --u; --v;
        } else {
            //u = i + 1;
            //v = rand() % (i + 1);
            u = 0;
            v = i + 1;
            //v = i / 2;
        }
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dpDown.resize(n);
    dfsDown(0, -1);
    secondDfs(0, -1, dp());
    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << "\n";
}