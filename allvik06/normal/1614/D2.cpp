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
const int MAXC = 2e7;
int all[MAXC + 1];
int dp[MAXC + 1];
int mind[MAXC + 1];
int flex[MAXC + 1];

void upd(int cur, int now, const vector <pair <int, int>>& all_d) {
    if (cur == (int)all_d.size()) {
        ++all[now];
        return;
    }
    for (int p = 0; p <= all_d[cur].second; ++p) {
        upd(cur + 1, now, all_d);
        now *= all_d[cur].first;
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector <int> pr;
    for (int i = 2; i <= MAXC; ++i) {
        if (mind[i] == 0) {
            mind[i] = flex[i] = i;
            flex[i] = 1;
            pr.push_back(i);
        }
        for (int j : pr) {
            if (j > mind[i] || j * i > MAXC) break;
            mind[j * i] = j;
            if (j == mind[i]) flex[j * i] = flex[i];
            else flex[i * j] = i;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            ++all[1];
            continue;
        }
        vector <pair <int, int>> all_d;
        while (x > 1) {
            if (!all_d.empty() && all_d.back().first == mind[x]) all_d.back().second++;
            else all_d.emplace_back(mind[x], 1);
            x /= mind[x];
        }
        upd(0, 1, all_d);
    }
    int ans = 0;
    for (int i = MAXC; i > 0; --i) {
        dp[i] = max(dp[i], all[i] * i);
        ans = max(ans, dp[i]);
        int cur = i;
        while (cur > 1) {
            int v = i / mind[cur];
            dp[v] = max(dp[v], dp[i] + (all[v] - all[i]) * v);
            cur = flex[cur];
        }
    }
    cout << ans;
}

/*

 */