// Wrong solution. Submit just to test whether the test cases are strong or not
#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())
#define u x.x
#define v x.y
#define c y.x
#define id y.y

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int REP = 60;

int n, m, k;
vector<pair<ii, pair<double, int>>> e;
vector<int> ans;

struct DSU {
    int n;
    vector<int> p;

    DSU(int _n) {
        n = _n;
        p.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int root(int x) {
        return (p[x] == x) ? x : (p[x] = root(p[x]));
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return;
        p[x] = y;
    }

    bool inTheSameSet(int x, int y) {
        return (root(x) == root(y));
    }
};

int check(double mid) {
    for (auto &ed : e) {
        if (ed.u == 1 || ed.v == 1) {
            ed.c += mid;
        }
    }
    sort(all(e), [](pair<ii, pair<double, int>> a, pair<ii, pair<double, int>> b) {
        return a.c < b.c;
    });
    // for (auto ed : e) {
    //     cout << ed.c << ' ' << ed.u << ' ' << ed.v << endl;;
    // }
    // cout << endl;
    DSU dsu = DSU(n);
    int cnt = 0;
    for (auto ed : e) {
        if (!dsu.inTheSameSet(ed.u, ed.v)) {
            dsu.merge(ed.u, ed.v);
            if (ed.u == 1 || ed.v == 1) cnt++;
        }
    }
    for (auto &ed : e) {
        if (ed.u == 1 || ed.v == 1) {
            ed.c -= mid;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> k;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        pair<ii, ii> ed;
        cin >> ed.u >> ed.v >> ed.c;
        if (ed.u == 1 || ed.v == 1) cnt++;
        ed.id = i;
        e.pb(ed);
    }
    double l = -1e9;
    double r = 1e9;
    for (int rep = 0; rep < REP; rep++) {
        double mid = (l + r) / 2;
        int foo = check(mid);
        if (foo >= k) {
            l = mid; 
        } else r = mid;
    }
    if (cnt < k) return cout << -1, 0;
    l = l - 0.1;
    for (auto &ed : e) {
        if (ed.u == 1 || ed.v == 1) {
            ed.c += l;
        }
    }
    sort(all(e), [](pair<ii, pair<double, int>> a, pair<ii, pair<double, int>> b) {
        return a.c < b.c;
    });
    DSU dsu = DSU(n);
    cnt = 0;
    int cnt2 = 0;
    for (auto ed : e) {
        if (!dsu.inTheSameSet(ed.u, ed.v)) {
            if ((ed.u == 1 || ed.v == 1) && cnt == k) continue;
            ans.pb(ed.id);
            if (ed.u == 1 || ed.v == 1) cnt++;
            cnt2++;
            dsu.merge(ed.u, ed.v);
        }
    }
    if (cnt2 != n - 1) return cout << -1, 0;
    cout << ans.size() << '\n';
    for (int ed : ans) cout << ed << ' ';
    return 0;
}