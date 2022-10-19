#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;
#define int __int128_t
//#define int long long
//#define double __float128
const int INF = 1e16;

struct line {
    int k, b;

    line(int k, int b) : k(k), b(b) {}

    line() {}


    int operator()(int x){
        return k * x + b;
    }
};

struct part {
    line a;
    int x = INF;
};
vector<part> all;

inline double intersection(line a, line b) {
    return (double) (a.b - b.b) / (double) (b.k - a.k);
}

inline void add(line a) {
    if (all.empty()) {
        all.emplace_back();
        all.back().a = a;
        return;
    }
    while ((int) all.size() >= 2) {
        if ((int)intersection(a, all.back().a) <= all[(int) all.size() - 2].x) all.pop_back();
        else break;
    }
    all.back().x = intersection(all.back().a, a);
    all.emplace_back();
    all.back().a = a;
}

int get_flex(line ln, int x){
    int flex = 0;
    if (ln.b >= x) flex = 0;
    else flex = (x - ln.b + ln.k - 1) / ln.k;
    for(int i = flex - 3; i <= flex + 3; i += 1){
        if(ln(i) >= x){
            return i;
        }
    }
    return flex;
}

inline pair<int, int> get(int x) {
    int l = -1, r = (int) all.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int flex = get_flex(all[m].a, x);
        if (flex <= all[m].x) r = m;
        else l = m;
    }
    int flex = get_flex(all[r].a, x);
    return make_pair(flex, flex * all[r].a.k + all[r].a.b);
}

void solve() {
    long long n, s;
    cin >> n >> s;
    vector<pair<int, int>> a;
    int mx = 0;
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        if (y == 0) mx = max(mx, (int)x);
        else {
            if (d.count(x)) d[x] = min(d[x], (int)y);
            else d[x] = y;
        }
    }
    for (auto i : d) {
        if (i.first <= mx) continue;
        a.push_back(i);
    }
    a.emplace_back(INF, s);
    add(line(mx, 0));
    for (auto i: a) {
        auto ans = get(i.second);
        int cnt = ans.second - i.second;
        if (i.first == INF) {
            cout << (long long)ans.first << "\n";
            return;
        }
        int b = cnt - ans.first * i.first;
        add(line(i.first, b));
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        while (t--) {
            solve();
        }
    }
}

/*
5 6
6 0
3 7
1 9
1 7
2 4

 */