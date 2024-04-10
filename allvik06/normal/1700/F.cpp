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

inline ll solve1(int n, vector <array <int, 2>> a, vector <array <int, 2>> b) {
    int sum = 0;
    for (auto i : a) sum += i[0] + i[1];
    for (auto i : b) sum -= i[0] + i[1];
    if (sum != 0) {
        return -1;
    }
    int cnt0 = 0, cnt1 = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cnt0 += a[i][0];
        cnt1 += a[i][1];
        int c0 = min(b[i][0], cnt0);
        cnt0 -= c0;
        b[i][0] -= c0;
        int c1 = min(b[i][1], cnt1);
        cnt1 -= c1;
        b[i][1] -= c1;
        c0 = min(b[i][0], cnt1);
        b[i][0] -= c0;
        cnt1 -= c0;
        ans += c0;
        c0 = min(b[i][1], cnt0);
        b[i][1] -= c0;
        cnt0 -= c0;
        ans += c0;
        if (i < n - 1) {
            b[i + 1][0] += b[i][0];
            b[i + 1][1] += b[i][1];
            ans += b[i][0] + b[i][1];
        }
        ans += cnt0 + cnt1;
    }
    return ans;
}
const ll INF = 1e15;

inline ll solve2(int n, vector <array <int, 2>> a, vector <array <int, 2>> b) {
    vector <pair <int, int>> all_a, all_b;
    for (int i = 0; i < n; ++i) {
        if (a[i][0]) all_a.emplace_back(i, 0);
        if (a[i][1]) all_a.emplace_back(i, 1);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i][0]) all_b.emplace_back(i, 0);
        if (b[i][1]) all_b.emplace_back(i, 1);
    }
    if (all_a.size() != all_b.size()) return -1;
    vector <int> p((int)all_a.size());
    ll ans = INF;
    for (int i = 0; i < (int)all_a.size(); ++i) p[i] = i + 1;
    do {
        ll cur = 0;
        for (int i = 0; i < (int)all_a.size(); ++i) {
            cur += abs(all_a[i].first - all_b[p[i] - 1].first) + abs(all_a[i].second - all_b[p[i] - 1].second);
        }
        ans = min(ans, cur);
    } while (next_permutation(p.begin(), p.end()));
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
        vector <array <int, 2>> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i][0];
        for (int i = 0; i < n; ++i) cin >> a[i][1];
        for (int i = 0; i < n; ++i) cin >> b[i][0];
        for (int i = 0; i < n; ++i) cin >> b[i][1];
        cout << solve1(n, a, b);
    } else {
        srand(1303);
        int t;
        cin >> t;
        while (t--) {
            if (t % 100 == 0) cout << t << "\n";
            int n = rand() % 5 + 1;
            vector <array <int, 2>> a(n), b(n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] = rand() % 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[i][j] = rand() % 2;
                }
            }
            if (solve1(n, a, b) != solve2(n, a, b)) {
                cout << n << "\n";
                for (auto i : a) cout << i[0] << " ";
                cout << "\n";
                for (auto i : a) cout << i[1] << " ";
                cout << "\n";
                for (auto i : b) cout << i[0] << " ";
                cout << "\n";
                for (auto i : b) cout << i[1] << " ";
                return 0;
            }
        }
    }
}

/*
5
0 1 1 0 1
0 0 0 0 1
0 0 0 0 0
1 0 1 1 1 
 */