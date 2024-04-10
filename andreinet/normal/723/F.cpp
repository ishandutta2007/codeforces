#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Edge {
    int from, to;
    Edge() = default;
    Edge(int _from, int _to):
        from(_from), to(_to) {}
};

class DSU {
public:
    DSU(int n):
        f(vector<int>(n)) {
            for (int i = 0; i < n; ++i) {
                f[i] = i;
            }
        }

    int find(int x) {
        int y, p;
        for (y = f[x]; y != f[y]; y = f[y]);
        for (; x != y; x = p) {
            p = f[x];
            f[x] = y;
        }
        return y;
    }

    void merge(int x, int y) {
        f[find(x)] = find(y);
    }

    int size() const {
        return SZ(f);
    }
private:
    vector<int> f;
};

bool checkConnected(DSU& t) {
    int n = t.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (t.find(i) == i) {
            cnt++;
        }
    }
    return cnt == 1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    DSU T(n);
    vector<Edge> ans;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        if (from > to) {
            swap(from, to);
        }
        from--; to--;
        edges.push_back(Edge(from, to));
    }
    int s, t, ds, dt;
    cin >> s >> t >> ds >> dt;
    s--; t--;
    for (Edge& e: edges) {
        int from = e.from, to = e.to;
        if (e.to == s || e.to == t) {
            swap(e.from, e.to);
        }
        if (T.find(from) == T.find(to)) {
            continue;
        }
        if (from != s && from != t && to != s && to != t) {
            ans.push_back(Edge(from, to));
            T.merge(from, to);
        }
    }

    vector<bool> aByS(n, false), aByT(n, false);
    for (const Edge& e: edges) {
        if (e.from == s) {
            aByS[T.find(e.to)] = true;
        } else if (e.from == t) {
            aByT[T.find(e.to)] = true;
        }
    }

    for (const Edge& e: edges) {
        int from = e.from;
        int to = e.to;
        if (T.find(from) == T.find(to)) {
            continue;
        }
        if (from == s) {
            if (to != t && !aByT[T.find(to)]) {
                ans.push_back(e);
                T.merge(from, to);
                ds--;
            } 
        } else if (from == t) {
            if (to != s && !aByS[T.find(to)]) {
                ans.push_back(e);
                T.merge(from, to);
                dt--;
            }
        }
    }

    for (const Edge& e: edges) {
        int from = e.from;
        int to = e.to;
        if (T.find(from) == T.find(to)) {
            continue;
        }
        if (from == s) {
            if (to != t && ds > 0) {
                ans.push_back(e);
                T.merge(from, to);
                ds--;
            } 
        } else if (from == t) {
            if (to != s && dt > 0) {
                ans.push_back(e);
                T.merge(from, to);
                dt--;
            }
        }
    }

    for (const Edge& e: edges) {
        int from = e.from;
        int to = e.to;
        if (T.find(from) == T.find(to)) {
            continue;
        }
        if ((from == s && to == t) || (from == t && to == s)) {
            if (ds > 0 && dt > 0) {
                ds--;
                dt--;
                ans.push_back(e);
                T.merge(from, to);
                break;
            }
        }
        if (from == s && T.find(to) == t && ds > 0) {
            ds--;
            ans.push_back(e);
            T.merge(from, to);
            break;
        }
        if (from == t && T.find(to) == s && dt > 0) {
            dt--;
            ans.push_back(e);
            T.merge(from, to);
            break;
        }
    }

    if (checkConnected(T) && ds >= 0 && dt >= 0) {
        cout << "Yes\n";
        for (const Edge& e: ans) {
            cout << e.from + 1 << ' ' << e.to + 1 << '\n';
        }
    } else {
        cout << "No\n";
    }
}