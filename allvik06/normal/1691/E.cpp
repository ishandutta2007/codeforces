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
const int INF = 1e9;

struct segment {
    int l, r, c;
};

vector <segment> a;

inline bool cmp(pair <int, int> f, pair <int, int> s) {
    int f_x, s_x;
    if (f.second == 0) f_x = a[f.first].l;
    else f_x = a[f.first].r;
    if (s.second == 0) s_x = a[s.first].l;
    else s_x = a[s.first].r;
    if (f_x == s_x) return f.second < s.second;
    return f_x < s_x;
}

inline int max_seg(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    if (a[x].r < a[y].r) return y;
    return x;
}

struct dsu {
    vector <int> p;
    vector <array <int, 2>> mx;

    dsu(int n) {
        p.resize(n);
        mx.resize(n, {-1, -1});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            mx[i][a[i].c] = i;
        }
    }

    int parent(int v) {
        if (v == p[v]) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline void unite(int x, int y, array <set <int>, 2>& s) {
        x = parent(x);
        y = parent(y);
        for (int i = 0; i < 2; ++i) {
            s[i].erase(mx[x][i]);
            s[i].erase(mx[y][i]);
            mx[y][i] = max_seg(mx[x][i], mx[y][i]);
            s[i].insert(mx[y][i]);
        }
        p[x] = y;
    }
};

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        a.assign(n, {});
        for (int i = 0; i < n; ++i) {
            cin >> a[i].c >> a[i].l >> a[i].r;
        }
        vector<pair<int, int>> all;
        for (int i = 0; i < n; ++i) {
            all.emplace_back(i, 0);
            all.emplace_back(i, 1);
        }
        sort(all.begin(), all.end(), cmp);
        array<set<int>, 2> s;
        dsu now(n);
        vector <int> tmp;
        for (auto i: all) {
            int j = i.first, t = i.second;
            if (t == 0) {
                int pr = now.parent(j);
                if (now.mx[pr][a[j].c] == j) s[a[j].c].insert(j);
                for (int k : s[a[j].c ^ 1]) tmp.push_back(k);
                for (int k : tmp) now.unite(pr, k, s);
                tmp.clear();
            } else {
                s[a[j].c].erase(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (now.p[i] == i) ++ans;
        }
        cout << ans << "\n";
    }
}

/*

 */