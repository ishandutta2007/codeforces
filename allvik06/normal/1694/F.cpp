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
#define ll long long
const int INF = 1e9;

struct SegTreeMin {
    int n;
    vector <pair <int, int>> t;
    vector <pair <int, int>> p;

    SegTreeMin(int n) : n(n) {
        t.resize(4 * n, make_pair(-INF, -INF - 1));
        p.resize(4 * n, make_pair(0, 2));
    }

    inline void push(int v) {
        if (p[v].second == 2) return;
        if (p[v].second == 0) {
            t[2 * v].first = t[2 * v + 1].first = p[2 * v].first = p[2 * v + 1].first = p[v].first;
            t[2 * v].second = t[2 * v + 1].second = -INF - 1;
            p[2 * v].second = p[2 * v + 1].second = 0;
        } else {
            t[2 * v].first = min(t[2 * v].first, p[v].first);
            t[2 * v + 1].first = min(t[2 * v + 1].first, p[v].first);
            p[2 * v].first = min(p[2 * v].first, p[v].first);
            p[2 * v + 1].first = min(p[2 * v + 1].first, p[v].first);
            if (p[2 * v].second == 2) p[2 * v].second = 1;
            if (p[2 * v + 1].second == 2) p[2 * v + 1].second = 1;
        }
        p[v].second = 2;
    }

    inline pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
        if (a.first < b.first) {
            a.second = a.first;
            a.first = b.first;
        }
        if (b.first > a.second && a.first != b.first) {
            a.second = b.first;
        }
        if (b.second > a.second && a.first != b.second) {
            a.second = b.second;
        }
        return a;
    }

    void set_val(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (l != r) push(v);
        if (A <= l && r <= B) {
            t[v].first = x;
            t[v].second = -INF - 1;
            p[v].first = x;
            p[v].second = 0;
            return;
        }
        int m = (l + r) / 2;
        set_val(2 * v, l, m, A, B, x);
        set_val(2 * v + 1, m + 1, r, A, B, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void set_min(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (l != r) push(v);
        if (A <= l && r <= B && x > t[v].second) {
            t[v].first = min(t[v].first, x);
            p[v].first = x;
            p[v].second = 1;
            return;
        }
        int m = (l + r) / 2;
        set_min(2 * v, l, m, A, B, x);
        set_min(2 * v + 1, m + 1, r, A, B, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    int get_val(int v, int l, int r, int i) {
        if (l > i || i > r) return -INF - 1;
        if (l == r) return t[v].first;
        push(v);
        int m = (l + r) / 2;
        return max(get_val(2 * v, l, m, i), get_val(2 * v + 1, m + 1, r, i));
    }

    int find_last_more(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r || t[v].first < x) return -1;
        if (l == r) return l;
        push(v);
        int m = (l + r) / 2;
        int rig = find_last_more(2 * v + 1, m + 1, r, A, B, x);
        if (rig != -1) return rig;
        return find_last_more(2 * v, l, m, A, B, x);
    }
};

struct SegTreeMax {
    int n;
    vector <pair <int, int>> t;
    vector <pair <int, int>> p;

    SegTreeMax(int n) : n(n) {
        t.resize(4 * n, make_pair(INF, INF + 1));
        p.resize(4 * n, make_pair(0, 2));
    }

    inline void push(int v) {
        if (p[v].second == 2) return;
        if (p[v].second == 0) {
            t[2 * v].first = t[2 * v + 1].first = p[2 * v].first = p[2 * v + 1].first = p[v].first;
            t[2 * v].second = t[2 * v + 1].second = INF + 1;
            p[2 * v].second = p[2 * v + 1].second = 0;
        } else {
            t[2 * v].first = max(t[2 * v].first, p[v].first);
            t[2 * v + 1].first = max(t[2 * v + 1].first, p[v].first);
            p[2 * v].first = max(p[2 * v].first, p[v].first);
            p[2 * v + 1].first = max(p[2 * v + 1].first, p[v].first);
            if (p[2 * v].second == 2) p[2 * v].second = 1;
            if (p[2 * v + 1].second == 2) p[2 * v + 1].second = 1;
        }
        p[v].second = 2;
    }

    inline pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
        if (a.first > b.first) {
            a.second = a.first;
            a.first = b.first;
        }
        if (b.first < a.second && a.first != b.first) {
            a.second = b.first;
        }
        if (b.second < a.second && a.first != b.second) {
            a.second = b.second;
        }
        return a;
    }

    void set_val(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (l != r) push(v);
        if (A <= l && r <= B) {
            t[v].first = x;
            t[v].second = INF + 1;
            p[v].first = x;
            p[v].second = 0;
            return;
        }
        int m = (l + r) / 2;
        set_val(2 * v, l, m, A, B, x);
        set_val(2 * v + 1, m + 1, r, A, B, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void set_max(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (l != r) push(v);
        if (A <= l && r <= B && x < t[v].second) {
            t[v].first = max(t[v].first, x);
            p[v].first = x;
            p[v].second = 1;
            return;
        }
        int m = (l + r) / 2;
        set_max(2 * v, l, m, A, B, x);
        set_max(2 * v + 1, m + 1, r, A, B, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    int get_val(int v, int l, int r, int i) {
        if (l > i || i > r) return -INF - 1;
        if (l == r) return t[v].first;
        push(v);
        int m = (l + r) / 2;
        return max(get_val(2 * v, l, m, i), get_val(2 * v + 1, m + 1, r, i));
    }

    int find_last_less(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r || t[v].first > x) return -1;
        if (l == r) return l;
        push(v);
        int m = (l + r) / 2;
        int rig = find_last_less(2 * v + 1, m + 1, r, A, B, x);
        if (rig != -1) return rig;
        return find_last_less(2 * v, l, m, A, B, x);
    }
};

inline ll solve1(int n, vector <int> a) {
    ll ans = 0;
    SegTreeMax val1(n);
    SegTreeMin val2(n);
    int r = 0;
    val1.set_val(1, 0, n - 1, 0, 0, INF);
    val2.set_val(1, 0, n - 1, 0, 0, -INF);
    for (int l = 0; l < n; ++l) {
        while (r + 1 < n) {
            int v1 = val1.get_val(1, 0, n - 1, l);
            int v2 = val2.get_val(1, 0, n - 1, l);
            int x = a[r + 1];
            bool ok = false;
            if (x > a[r] && v1 > 0) ok = true;
            if (x < v1) ok = true;
            if (x < a[r] && v2 <= n) ok = true;
            if (x > v2) ok = true;
            if (!ok) break;
            if (x > a[r]) {
                int f_bad = val2.find_last_more(1, 0, n - 1, l, r, x);
                int s_bad = val1.find_last_less(1, 0, n - 1, l, r, x);
                val1.set_max(1, 0, n - 1, f_bad + 1, r, a[r]);
                val2.set_val(1, 0, n - 1, 0, n - 1, INF);
                val2.set_val(1, 0, n - 1, s_bad + 1, r, a[r]);
            } else {
                int f_bad = val1.find_last_less(1, 0, n - 1, l, r, x);
                int s_bad = val2.find_last_more(1, 0, n - 1, l, r, x);
                val2.set_min(1, 0, n - 1, f_bad + 1, r, a[r]);
                val1.set_val(1, 0, n - 1, 0, n - 1, -INF);
                val1.set_val(1, 0, n - 1, s_bad + 1, r, a[r]);
            }
            ++r;
            val1.set_val(1, 0, n - 1, r, r, INF);
            val2.set_val(1, 0, n - 1, r, r, -INF);
        }
        ans += r - l + 1;
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve1(n, a);
    }
}

/*

 */