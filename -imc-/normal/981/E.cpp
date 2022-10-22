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

bool isPrime(int x) {
    for (int y = 2; y * y <= x; ++y)
        if (x % y == 0)
            return false;

    return true;
}

void solve(bool __attribute__((unused)) read) {
    int P = 0;


    int n, q;
    cin >> n >> q;
    ++n;

    vector<vector<int>> adds(n), dels(n);

    int h = time(0);

    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;

        h += l ^ 231231;
        h *= (1 + l);
        h += r ^ 123412;
        h *= (1 + r);
        h += x ^ 123143;

        adds[l].push_back(x);
        dels[r + 1].push_back(x);
    }

    {
        //cout << "got hash " << h << endl;
        int cnt = abs(h) % 1000;

        for (int t = 1e9 + 7; ; ++t) {
            if (isPrime(t)) {
                --cnt;

                if (cnt == 0) {
                    P = t;
                    break;
                }
            }
        }
    }

    //cout << "got P " << P << endl;
    //return;

    vector<int> nw(n);
    nw[0] = 1;

    auto add = [&](int& to, int x) {
        to += x;
        if (to >= P) {
            to %= P;
        }
    };

    auto doAdd = [&](int x) {
        for (int i = n - x - 1; i >= 0; --i) {
            add(nw[i + x], nw[i]);
        }
    };

    auto doDel = [&](int x) {
        for (int i = 0; i + x < n; ++i) {
            if (nw[i])
                add(nw[i + x], P - nw[i]);
        }
    };

    vector<char> ans(n, false);

    for (int i = 0; i < n; ++i) {
        for (int x: adds[i]) {
            doAdd(x);
        }
        for (int x: dels[i]) {
            doDel(x);
        }

        for (int t = n - 1; t >= 0; --t)
            if (nw[t]) {
                ans[t] = true;
            }
    }

    int cnt = 0;
    for (int i = 1; i <= n - 1; ++i)
        if (ans[i])
            ++cnt;

    cout << cnt << endl;
    for (int i = 1; i <= n - 1; ++i)
        if (ans[i])
            cout << i << " ";
    cout << endl;
}