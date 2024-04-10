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
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
const int INF = 1e9;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector <int> cur(10);
    string ans;
    vector <int> suf(n + 1, 10);
    for (int i = n - 1; i >= 0; --i) suf[i] = min(suf[i + 1], s[i] - '0');
    int cha = 0;
    for (int i = 0; i < n; ++i) {
        int mcur = 10;
        for (int j = 0; j < 10; ++j) {
            if (cur[j]) {
                mcur = j;
                break;
            }
        }
        if (suf[cha] < mcur) {
            ans += (char)('0' + suf[cha]);
            while (s[cha] != ans.back()) {
                ++cur[min(9, s[cha] - '0' + 1)];
                ++cha;
            }
            ++cha;
        } else {
            ans += (char)('0' + mcur);
            cur[mcur]--;
        }
    }
    cout << ans << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */