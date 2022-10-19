#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <random>
#include <array>

using namespace std;

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, cnt = 0, last = -1;
    cin >> n;
    vector <pair <int, int>> now;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        now.emplace_back(i, x);
        for (auto& j : now) j.second = gcd(j.second, x);
        vector <pair <int, int>> new_now;
        for (int j = (int)now.size() - 1; j > 0; --j) {
            if (now[j - 1].second != now[j].second) new_now.push_back(now[j]);
        }
        new_now.push_back(now[0]);
        reverse(new_now.begin(), new_now.end());
        now.swap(new_now);
        int cur_max = -1;
        for (int j = 0; j < (int)now.size(); ++j) {
            int r;
            if (j < (int)now.size() - 1) r = now[j + 1].first - 1;
            else r = i;
            int l = i - now[j].second + 1;
            if (l >= now[j].first && l <= r) cur_max = max(cur_max, l);
        }
        if (cur_max > last) {
            ++cnt;
            last = i;
        }
        cout << cnt << " ";
    }
    return 0;
}

/*
3 4
0 0 0
+ 1
+ 2
+ 2
- 1
 */