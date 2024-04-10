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

void make_oper(vector <int>& a, vector <pair <int, int>>& op, int l, int r) {
    op.emplace_back(l, r);
    reverse(a.begin() + l, a.begin() + r + 1);
}

inline void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    vector <pair <int, int>> op;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    vector <int> cnt(n + 1), flex(n + 1);
    for (int i = 1; i < n; ++i) ++cnt[a[i]];
    for (int i = 1; i < n; ++i) {
        if (a[i] == b[i]) {
            --cnt[b[i]];
            continue;
        }
        for (int j = i; j < n - 1; ++j) {
            if (a[j] == b[i] && a[j + 1] == b[i - 1]) {
                make_oper(a, op, i - 1, j + 1);
                break;
            }
        }
        if (a[i] == b[i]) {
            --cnt[b[i]];
            continue;
        }
        int now = 0;
        bool ok = false;
        ++cnt[a[i - 1]];
        ++flex[a[i - 1]];
        if (cnt[a[i - 1]] > 1) ++now;
        for (int j = i; j < n - 1 && !ok; ++j) {
            ++flex[a[j]];
            if (flex[a[j]] == cnt[a[j]] && cnt[a[j]] > 1) --now;
            if (flex[a[j]] == 1 && cnt[a[j]] > 1) ++now;
            if (a[j] == b[i - 1] && a[j + 1] == b[i] && now) {
                for (int r = j + 1; !ok; ++r) {
                    if (flex[a[r]] != cnt[a[r]]) {
                        for (int l = j; !ok && l >= i - 1; --l) {
                            if (a[r] == a[l]) {
                                make_oper(a, op, l, r);
                                ok = true;
                            }
                        }
                    }
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
        --cnt[a[i - 1]];
        flex.assign(n + 1, 0);
        for (int j = i; j < n - 1; ++j) {
            if (a[j] == b[i] && a[j + 1] == b[i - 1]) {
                make_oper(a, op, i - 1, j + 1);
                break;
            }
        }
        --cnt[b[i]];
    }
    assert(a == b);
    cout << "YES\n" << (int)op.size() << "\n";
    for (auto i : op) cout << i.first + 1 << " " << i.second + 1 << "\n";
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */