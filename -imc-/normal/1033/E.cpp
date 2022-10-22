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

vector<pair<int, int>> secretEdges;

int ask(vector<int> v) {
    if (v.empty()) {
        return 0;
    }

#if defined(LOCAL) && 1
    sort(all(v));
    assert(unique(all(v)) == v.end());
    int cnt = 0;
    for (auto it : secretEdges) {
        if (find(all(v), it.first) != v.end() && find(all(v), it.second) != v.end()) {
            ++cnt;
        }
    }
    return cnt;
#else
    cout << "? " << v.size() << "\n";
    for (int x : v) {
        cout << x + 1 << " ";
    }
    cout << endl;

    int ans;
    cin >> ans;
    int n = v.size();
    assert(ans >= 0 && ans <= n * (n - 1) / 2);
    return ans;
#endif
}

vector<vector<int>> e;
vector<int> color;

bool dfs(int v, int c) {
    if (color[v] != -1) {
        return color[v] == c;
    }
    color[v] = c;

    for (int u : e[v]) {
        if (!dfs(u, 1 - c)) {
            return false;
        }
    }

    return true;
}

struct dsu {
    int n;
    vector<int> p;

    dsu(int n): n(n), p(n) {
        iota(all(p), 0);
    }

    int get(int v) { return v == p[v] ? v : (p[v] = get(p[v])); }

    bool unite(int u, int v) {
        u = get(u);
        v = get(v);
        if (u != v) {
            p[u] = v;
            return true;
        }
        return false;
    }
};

void halfSplit(vector<int> q, vector<int>& ql, vector<int>& qr) {
    ql = vector<int>(q.begin(), q.begin() + q.size() / 2);
    qr = vector<int>(q.begin() + q.size() / 2, q.end());
}

vector<int> cat(vector<int> a, vector<int> b) {
    vector<int> res = a;
    copy(all(b), back_inserter(res));
    sort(all(res));
    assert(unique(all(res)) == res.end());
    return res;
}

vector<char> used;
vector<int> dfsStack;

bool getPath(int v, int to) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    dfsStack.push_back(v);

    if (v == to) {
        return true;
    }

    for (int u : e[v]) {
        if (getPath(u, to)) {
            return true;
        }
    }

    dfsStack.pop_back();
    return false;
}

void solve(__attribute__((unused)) bool read) {
    read = true;

    int n;
    if (read) {
        cin >> n;
    } else {
        n = 10;
        for (int i = 0; i < 5; ++i) {
            for (int j = 5; j < 10; ++j) {
                secretEdges.emplace_back(i, j);
            }
        }
        secretEdges.emplace_back(1, 3);
    }

    e.clear();
    e.resize(n);

    vector<char> used(n, false);
    dsu ds(n);

    while (true) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                v = i;
                break;
            }
        }
        if (v == -1) {
            break;
        }

        vector<int> q;
        for (int i = 0; i < n; ++i) {
            if (ds.get(i) != ds.get(v)) {
                q.push_back(i);
            }
        }
        //int idx = find(all(q), v) - q.begin();
        //assert(idx != q.size());
        //swap(q[idx], q.back());

        if (ask(q) == ask(cat(q, {v}))) {
            used[v] = true;
            continue;
        }

        //q.pop_back();

        while (q.size() > 1) {
            vector<int> ql, qr;
            halfSplit(q, ql, qr);

            int a1 = ask(ql);
            int a2 = ask(cat(ql, {v}));

            if (a2 > a1) {
                q = ql;
            } else {
                q = qr;

                //assert(ask(cat(qr, {v})) > ask(qr));
            }
        }
        assert(q.size() == 1);
        int u = q[0];
        assert(u != v);
        e[u].push_back(v);
        e[v].push_back(u);
        assert(ask({u, v}) == 1);
        assert(ds.unite(u, v));

        //cout << "add edge " << u + 1 << " " << v + 1 << endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j : e[i]) {
            if (j > i) {
                //cout << "found edge " << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    color.assign(n, -1);
    vector<int> s1, s2;
    for (int i = 0; i < n; ++i) {
        // it is just a tree!
        if (color[i] == -1) {
            assert(dfs(i, 0));
        }

        if (color[i] == 0) {
            s1.push_back(i);
        } else {
            s2.push_back(i);
        }
    }

    bool s1Bad = ask(s1) != 0;
    bool s2Bad = ask(s2) != 0;

    if (!s1Bad && !s2Bad) {
        cout << "Y " << s1.size() << "\n";
        for (int x : s1) {
            cout << x + 1 << " ";
        }
        cout << endl;
        return;
    }

    if (!s1Bad) {
        swap(s1Bad, s2Bad);
        swap(s1, s2);
    }
    assert(s1Bad);

    int foundU = -1, foundV = -1;

    vector<int> s1part = s1;

    while (s1part.size() > 2) {
        vector<int> a, b;
        halfSplit(s1part, a, b);

        if (ask(a) != 0) {
            s1part = a;
            continue;
        }

        if (ask(b) != 0) {
            s1part = b;
            continue;
        }

        // all edges on a - b

        for (int t = 0; t < 2; ++t) {
            while (a.size() > 1) {
                vector<int> c, d;
                halfSplit(a, c, d);

                if (ask(cat(b, c)) > 0) {
                    a = c;
                } else {
                    //assert(ask(cat(b, d)) > 0);
                    a = d;
                }
            }
            assert(a.size() == 1);
            swap(a, b);
        }

        assert(a.size() == 1);
        assert(b.size() == 1);
        foundU = a[0];
        foundV = b[0];
        break;
    }

    if (foundU == -1) {
        assert(s1part.size() == 2);
        foundU = s1part[0];
        foundV = s1part[1];
    }
    //cout << "pair of verts " << foundU + 1 << " " << foundV + 1 << endl;

    assert(ask({ foundU, foundV }) == 1);

    ::used.assign(n, false);
    assert(getPath(foundU, foundV));
    assert(dfsStack.size() % 2 == 1);

    cout << "N " << dfsStack.size() << "\n";
    for (int x : dfsStack) {
        cout << x + 1 << " ";
    }
    cout << endl;
}