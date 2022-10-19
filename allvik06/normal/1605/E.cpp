#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> cnt(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int now = 0, x = i, cur = 2;
        while (cur * cur <= x) {
            if (x % cur == 0) {
                x /= cur;
                ++now;
            } else {
                ++cur;
                continue;
            }
            if (x % cur == 0) {
                now = -1;
                break;
            }
            ++cur;
        }
        if (x > 1 && now != -1) ++now;
        cnt[i] = now;
    }
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    b[1] = 0;
    int ans = 0;
    vector <int> val(n + 1);
    for (int i = 1; i <= n; ++i) {
        int c = b[i] - a[i];
        val[i] = c;
        for (int j = i; j <= n; j += i) {
            a[j] += c;
        }
        ans += abs(c);
    }
    vector <int> all;
    int cnt_bad = 0, cnt_good = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == -1) continue;
        if (cnt[i] % 2 == 0) {
            if (val[i] < 0) {
                all.push_back(abs(val[i]));
                ++cnt_good;
            }
            else ++cnt_bad;
        } else {
            if (val[i] > 0) {
                all.push_back(val[i]);
                ++cnt_good;
            }
            else ++cnt_bad;
        }
    }
    int q;
    cin >> q;
    vector <pair <int, int>> all_q(q);
    for (int i = 0; i < q; ++i) {
        cin >> all_q[i].first; all_q[i].second = i;
    }
    sort(all_q.begin(), all_q.end());
    sort(all.begin(), all.end());
    int cha = 0, mom = 0;
    vector <int> answer(q);
    for (auto i : all_q) {
        while (cha < (int)all.size() && all[cha] <= i.first) {
            ans += (all[cha] - mom) * (cnt_bad - cnt_good);
            --cnt_good;
            ++cnt_bad;
            mom = all[cha++];
        }
        ans += (i.first - mom) * (cnt_bad - cnt_good);
        mom = i.first;
        answer[i.second] = ans;
    }
    for (int i : answer) cout << i << "\n";
}

/*

 */