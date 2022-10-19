#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long
const int INF = 1e15;

struct Vertex {
    int l, r;
    int d[2][2];

    Vertex() {
        l = -1;
        r = -1;
        d[0][0] = d[0][1] = d[1][0] = d[1][1] = INF;
    }
};

vector <pair <int, int>> doors[2];

inline int dist_lvl(pair <int, int> a, pair <int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

Vertex merge(const Vertex& a, const Vertex& b) {
    if (a.l == -1) return b;
    if (b.l == -1) return a;
    Vertex ans;
    ans.l = a.l;
    ans.r = b.r;
    for (int s1 = 0; s1 < 2; ++s1) {
        for (int e1 = 0; e1 < 2; ++e1) {
            for (int s2 = 0; s2 < 2; ++s2) {
                for (int e2 = 0; e2 < 2; ++e2) {
                    pair <int, int> p1 = doors[e1][a.r];
                    if (e1 == 0) p1.first++;
                    else p1.second++;
                    ans.d[s1][e2] = min(ans.d[s1][e2], a.d[s1][e1] + b.d[s2][e2] + dist_lvl(p1, doors[s2][b.l]) + 1);
                }
            }
        }
    }
    return ans;
}

struct SegTree {
    int n;
    vector <Vertex> t;

    SegTree(int n) : n(n) {
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            t[v].l = t[v].r = l;
            t[v].d[0][0] = t[v].d[1][1] = 0;
            t[v].d[0][1] = t[v].d[1][0] = dist_lvl(doors[0][l], doors[1][l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    Vertex get_seg(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return Vertex();
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return merge(get_seg(2 * v, l, m, A, B), get_seg(2 * v + 1, m + 1, r, A, B));
    }
};

inline int get_lvl(pair <int, int> a) {
    return max(a.first, a.second) - 1;
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i) doors[i].resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> doors[j][i].first >> doors[j][i].second;
        }
    }
    SegTree t(n - 1);
    int q;
    cin >> q;
    while (q--) {
        pair <int, int> f, s;
        cin >> s.first >> s.second >> f.first >> f.second;
        int lvl1 = get_lvl(f), lvl2 = get_lvl(s);
        if (lvl1 == lvl2) {
            cout << dist_lvl(f, s) << "\n";
            continue;
        }
        if (lvl1 > lvl2) {
            swap(f, s);
            swap(lvl1, lvl2);
        }
        Vertex seg = t.get_seg(1, 0, n - 2, lvl1, lvl2 - 1);
        int ans = INF;
        for (int st = 0; st < 2; ++st) {
            for (int e = 0; e < 2; ++e) {
                pair <int, int> nxt = doors[e][lvl2 - 1];
                if (e == 0) nxt.first++;
                else nxt.second++;
                ans = min(ans, dist_lvl(doors[st][lvl1], f) + dist_lvl(nxt, s) + seg.d[st][e] + 1);
            }
        }
        cout << ans << "\n";
    }
}

/*

 */