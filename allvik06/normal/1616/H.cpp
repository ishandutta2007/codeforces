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
const int mod = 998244353;
int x;
vector <int> p, p1;

int calc(vector <int>& a, vector <int>& b, int num, bool f = false) {
    if (((a.empty() || b.empty()) && f) || (a.empty() && b.empty())) return 0;
    if (num == -1) {
        return p1[(int)a.size()] * p1[(int)b.size()] % mod;
    }
    vector <int> aa[2];
    vector <int> bb[2];
    int cur = ((x >> num) & 1);
    for (int i : a) {
        if ((i >> num) & 1) aa[1].push_back(i);
        else aa[0].push_back(i);
    }
    for (int i : b) {
        if ((i >> num) & 1) bb[1].push_back(i);
        else bb[0].push_back(i);
    }
    if (cur) {
        int ans = 0;
        if (!f) {
            ans = (ans + p1[(int)aa[0].size()]) % mod;
            ans = (ans + p1[(int)aa[1].size()]) % mod;
            return (ans + calc(aa[0], aa[1], num - 1, true)) % mod;
        }
        ans = (ans + p1[(int)aa[0].size()] * p1[(int)bb[0].size()]) % mod;
        ans = (ans + p1[(int)aa[1].size()] * p1[(int)bb[1].size()]) % mod;
        int cnt1 = calc(aa[0], bb[1], num - 1, true);
        int cnt2 = calc(aa[1], bb[0], num - 1, true);
        ans = (ans + cnt1) % mod;
        ans = (ans + cnt2) % mod;
        ans = (ans + cnt2 * p1[(int)bb[1].size()]) % mod;
        ans = (ans + cnt2 * p1[(int)aa[0].size()]) % mod;
        ans = (ans + cnt1 * p1[(int)bb[0].size()]) % mod;
        ans = (ans + cnt1 * p1[(int)aa[1].size()]) % mod;
        ans = (ans + cnt1 * cnt2) % mod;
        return ans;
    } else {
        return (calc(aa[0], bb[0], num - 1, f) + calc(aa[1], bb[1], num - 1, f)) % mod;
    }
}

inline int solve1(int n, vector <int>& a) {
    p.assign(2 * n + 1, 1);
    p1.resize(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) p[i] = (p[i - 1] * 2) % mod;
    for (int i = 0; i <= 2 * n; ++i) p1[i] = (p[i] - 1 + mod) % mod;
    if (x == 0) {
        map <int, int> cur;
        for (int i : a) ++cur[i];
        int ans = 0;
        for (auto i : cur) {
            ans = (ans + p1[i.second]) % mod;
        }
        return ans;
    }
    vector <int> b;
    return calc(a, b, 29);
}

inline int solve2(int n, vector <int>& a) {
    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (!ok) break;
            if ((mask >> i) & 1) {
                for (int j = i + 1; j < n; ++j) {
                    if ((mask >> j) & 1) {
                        if ((a[i] ^ a[j]) > x) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }
        ans += ok;
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
        cin >> n >> x;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve1(n, a);
    } else {
        srand(1303);
        int t;
        cin >> t;
        while (t--) {
            int n = rand() % 10 + 1;
            x = rand() % 16;
            vector <int> a(n);
            for (int i = 0; i < n; ++i) a[i] = rand() % 16;
            if (solve1(n, a) != solve2(n, a)) {
                cout << n << " " << x << "\n";
                for (int i : a) cout << i << ' ';
                return 0;
            }
        }
    }
}

/*
3 11
1 11 3
 */