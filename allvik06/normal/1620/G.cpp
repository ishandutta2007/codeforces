#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
#define int long long

const int INF = 1e9;
const int mod = 998244353;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    string s;
    vector <vector <int>> all(n, vector <int> (26, 1));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (char c : s) {
            ++all[i][c - 'a'];
        }
    }
    vector <int> val((1 << n)), minn(26, INF);
    for (int mask = 1; mask < (1 << n); ++mask) {
        int lol = 0;
        for (int i = 0; i < n; ++i) {
            if (!((mask >> i) & 1)) continue;
            ++lol;
            for (int j = 0; j < 26; ++j) {
                minn[j] = min(minn[j], all[i][j]);
            }
        }
        int cnt = 1;
        for (int i = 0; i < 26; ++i) {
            cnt = cnt * minn[i] % mod;
            minn[i] = INF;
        }
        if (lol & 1) val[mask] = cnt;
        else val[mask] = mod - cnt;
    }
    for (int i = 0; i < n; ++i) {
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            if (!((mask >> i) & 1)) val[mask + (1 << i)] = (val[mask + (1 << i)] + val[mask]) % mod;
        }
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0, cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((mask >> j) & 1) {
                sum += j + 1;
                ++cnt;
            }
        }
        int x = cnt * sum * val[mask];
        ans ^= x;
    }
    cout << ans;
}

/*


 */