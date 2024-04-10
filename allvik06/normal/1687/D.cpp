#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>

using namespace std;
#define int long long
const int MAXN = 2e6;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> used(MAXN + 1);
    vector <int> blr(MAXN + 1, -1), bll(MAXN + 1, -1);
    int mn = -1, mx;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        used[x]++;
        if (mn == -1) mn = x;
        mx = x;
    }
    for (int i = 0; i <= MAXN; ++i) {
        if (i > 0) bll[i] = bll[i - 1];
        if (used[i]) bll[i] = i;
    }
    for (int i = MAXN; i >= 0; --i) {
        if (i < MAXN) blr[i] = blr[i + 1];
        if (used[i]) blr[i] = i;
    }
    vector <int> p(MAXN + 2);
    for (int i = 0; i < MAXN + 1; ++i) {
        p[i + 1] = p[i] + used[i];
    }
    int cur = 1, cur_len = 2;
    while (true) {
        if (mn <= cur + cur_len - 1) {
            int d = max(0LL, cur - mn);
            int min_good = INF;
            int max_bad = -INF;
            int tmp_len = cur_len;
            int cur_s = cur;
            while (cur_s <= mx + d) {
                int new_s = cur_s + tmp_len - 1;
                int e = new_s - d;
                int val = bll[min(MAXN, e)];
                if (val != -1 && val + d >= cur_s) {
                    min_good = min(min_good, new_s - (val + d) + 1);
                }
                cur_s = new_s + 1;
                new_s = cur_s + (tmp_len - 1) - 1;
                int s = cur_s - d;
                val = blr[min(MAXN, s)];
                if (val != -1 && val + d >= cur_s && val + d <= new_s) {
                    max_bad = max(max_bad, new_s - (val + d) + 1);
                }
                cur_s = new_s + 1;
                ++tmp_len;
            }
            if (max_bad < min_good) {
                if (max_bad == -INF) {
                    cout << d;
                } else {
                    cout << d + max_bad;
                }
                return 0;
            }
        }
        cur = (cur + cur_len) + (cur_len - 1);
        ++cur_len;
    }
}