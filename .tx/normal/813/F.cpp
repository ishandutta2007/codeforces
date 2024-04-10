#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

const int N = 111111;
int a[N];
vector<pair<int, int>> la;
int p[N];
vector<pair<int, int>> lp;
int r[N];
vector<pair<int, int>> lr;

int get(int x) {
    return x == a[x] ? x : get(a[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
        return;
    }
    if (r[x] < r[y]) {
        la.push_back({x, a[x]});
        a[x] = y;
    } else {
        la.push_back({y, a[y]});
        a[y] = x;
        if (r[x] == r[y]) {
            lr.push_back({x, r[x]});
            r[x]++;
        }
    }
}

struct edge {
    int f, t, l, r;
};

vector<edge> es;

void back(int sa, int sp, int sr) {
    while (la.size() > sa) {
        auto l = la.back();
        la.pop_back();
        a[l.first] = l.second;
    }

    while (lp.size() > sp) {
        auto l = lp.back();
        lp.pop_back();
        p[l.first] = l.second;
    }

    while (lr.size() > sr) {
        auto l = lr.back();
        lr.pop_back();
        r[l.first] = l.second;
    }
}

void go(int l, int r, vector<edge> es) {
    int sa = la.size();
    int sp = lp.size();
    int sr = lr.size();
    for (edge& e : es) {
        if (e.l <= l && r <= e.r) {
            int x = get(e.f);
            int y = get(e.t);
            if (x == y) {
                rep(i, l, r + 1) {
                    cout << "NO\n";
                }
                back(sa, sp, sr);
                return;
            }
            if (p[x] != -1) {
                unite(p[x], y);
            }
            if (p[y] != -1) {
                unite(p[y], x);
            }
            int zx = get(x);
            lp.push_back({zx, p[zx]});
            p[zx] = get(y);
            int zy = get(y);
            lp.push_back({zy, p[zy]});
            p[zy] = get(x);
        }
    }

    if (l == r) {
        cout << "YES\n";
    } else {
        int m = (l + r) >> 1;
        vector<edge> le, re;
        for (edge& e : es) {
            if (e.l <= l && r <= e.r) {
                continue;
            }
            if (e.l <= m) {
                le.push_back(e);
            }
            if (e.r >= m + 1) {
                re.push_back(e);
            }
        }
        go(l, m, le);
        go(m + 1, r, re);
    }

    back(sa, sp, sr);
}

void solve(istream& cin, ostream& cout) {
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> cur;
    rep(i, 0, q) {
        pair<int, int> e;
        cin >> e.first >> e.second;
        --e.first;
        --e.second;
        if (cur.count(e)) {
            es.push_back(edge{e.first, e.second, cur[e], i - 1});
            cur.erase(e);
        } else {
            cur[e] = i;
        }
    }

    for (auto& i : cur) {
        es.push_back(edge{i.first.first, i.first.second, i.second, q});
    }

    rep(i, 0, N) {
        a[i] = i;
        p[i] = -1;
    }

    go(0, q - 1, es);
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//lqutnt