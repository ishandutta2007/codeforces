
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
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
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> x(n), p(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> p[i];
    vector <array <int, 3>> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({x[i] - p[i] + 1, 1, i});
        events.push_back({x[i] + 1, 0, i});
        events.push_back({x[i] + p[i] + 1, 2, i});
    }
    sort(events.begin(), events.end());
    vector <int> val(n);
    int cur_val = 0, prev_x = events[0][0], delta = 0;
    for (auto i : events) {
        cur_val += (i[0] - prev_x) * delta;
        if (i[1] == 0) {
            val[i[2]] = cur_val;
            delta -= 2;
        } else if (i[1] == 1) {
            delta++;
        } else {
            delta++;
        }
        prev_x = i[0];
    }
    vector <bool> ans(n);
    vector <pair <int, int>> all_x;
    for (int i = 0; i < n; ++i) all_x.emplace_back(x[i], i);
    sort(all_x.begin(), all_x.end());
    set <pair <int, int>> s;
    for (auto i : all_x) {
        int v = val[i.second] - m;
        while (!s.empty() && v + i.first > s.begin()->first && v > 0) {
            ans[s.begin()->second] = true;
            s.erase(s.begin());
        }
        s.insert(make_pair(i.first + p[i.second], i.second));
    }
    s.clear();
    reverse(all_x.begin(), all_x.end());
    for (auto i : all_x) {
        int v = val[i.second] - m;
        while (!s.empty() && v - i.first > s.begin()->first && v > 0) {
            ans[s.begin()->second] = true;
            s.erase(s.begin());
        }
        s.insert(make_pair(p[i.second] - i.first, i.second));
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i]) cout << 0;
        else cout << 1;
    }
    cout << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
=
 */