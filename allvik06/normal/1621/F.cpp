#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
int a, b, c;


inline int solve(vector <int> all_sz, int f0, int l0, int cnt, int mv) {
    sort(all_sz.rbegin(), all_sz.rend());
    int mx = 0, cur = 0, cnt_open = 0;
    while (!all_sz.empty() && all_sz.back() == 1) {
        ++cnt_open;
        all_sz.pop_back();
    }
    while (true) {
        if (mv == 0) {
            if (!all_sz.empty() || f0 > 1 || l0 > 1) mx = max(mx, cur + a);
            if (cnt == 0) {
                if (cnt_open) {
                    --cnt_open;
                    ++cnt;
                    cur -= c;
                } else {
                    break;
                }
            } else {
                if (!all_sz.empty()) {
                    cur += a;
                    all_sz.back()--;
                    if (all_sz.back() == 1) {
                        all_sz.pop_back();
                        ++cnt_open;
                    }
                } else {
                    if (f0 > 1) {
                        f0--;
                        cur += a;
                    } else if (l0 > 1) {
                        l0--;
                        cur += a;
                    } else if (f0) {
                        f0--;
                        cur -= c;
                    } else if (l0) {
                        l0--;
                        cur -= c;
                    } else if (cnt_open) {
                        --cnt_open;
                        ++cnt;
                        cur -= c;
                    } else break;
                }
            }
        } else {
            if (cnt) {
                cur += b;
                --cnt;
            } else {
                break;
            }
            mx = max(mx, cur);
        }
        mv ^= 1;
    }
    return mx;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> a >> b >> c;
        vector <array <int, 3>> all;
        char prev;
        int st = 0;
        for (int i = 0; i < n; ++i) {
            char cur;
            cin >> cur;
            if (i > 0 && cur != prev) {
                all.push_back({st, i - 1, prev - '0'});
                st = i;
            }
            prev = cur;
        }
        all.push_back({st, n - 1, prev - '0'});
        int f0 = 0, l0 = 0, cnt = 0;
        vector <int> all_sz;
        for (auto i : all) {
            if (i[2] == 1) cnt += i[1] - i[0];
            else {
                if (i[0] == 0) f0 = i[1] - i[0] + 1;
                else if (i[1] == n - 1) l0 = i[1] - i[0] + 1;
                else all_sz.push_back(i[1] - i[0] + 1);
            }
        }
        if (f0 == n) {
            if (n == 1) cout << "0\n";
            else cout << a << "\n";
            continue;
        }
        cout << max(solve(all_sz, f0, l0, cnt, 0), solve(all_sz, f0, l0, cnt, 1)) << "\n";
    }
}

/*

 */