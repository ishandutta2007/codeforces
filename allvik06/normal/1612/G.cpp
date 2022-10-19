#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;
#define int long long
const int MAXA = 1e6 + 1;
const int mod = 1e9 + 7;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, sum = 0;
    cin >> n;
    vector <int> cnt(MAXA);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        ++cnt[x];
    }
    vector <int> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
    int cur_taken = 0, mx = MAXA - 1, ans = 0, cnt_ans = 1;
    while (mx > 1) {
        while (mx > 1 && cnt[mx] == 0) --mx;
        if (mx == 1) {
            cnt_ans = (cnt_ans * fact[cnt[1]]) % mod;
            break;
        }
        int start = sum - cur_taken - cnt[mx], end = sum - cur_taken - 1;
        int val = (start + end) * cnt[mx] / 2 % mod;
        val = (val * (mx - 1)) % mod;
        ans = (ans + val) % mod;
        start = cur_taken;
        end = cur_taken + cnt[mx] - 1;
        val = (start + end) * cnt[mx] / 2 % mod;
        val = (val * (mx - 1)) % mod;
        ans = (ans - val + mod) % mod;
        cnt_ans = (cnt_ans * fact[cnt[mx]]) % mod * fact[cnt[mx]] % mod;
        cnt[mx - 2] += cnt[mx];
        cur_taken += cnt[mx];
        cnt[mx] = 0;
    }
    cout << ans << " " << cnt_ans << "\n";
}

/*

 */