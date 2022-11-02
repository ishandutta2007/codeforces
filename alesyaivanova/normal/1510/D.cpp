#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

typedef long double ld;

const ld INF = 1e9 + 239;
const int N = 1e5 + 7;
const int D = 10;

int a[N];
ld lg[N];
ld dp[N][D];
pair<int, int> wr[N][D];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    int c1 = 0;
    {
        int rn = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                c1++;
            } else {
                a[rn++] = x;
            }
        }
        n = rn;
    }
    for (int i = 0; i < n; i++) {
        lg[i] = log2(a[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < D; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            if (dp[i][j] == -INF) continue;
            if (dp[i + 1][(j * a[i]) % D] < dp[i][j] + lg[i]) {
                dp[i + 1][(j * a[i]) % D] = dp[i][j] + lg[i];
                wr[i + 1][(j * a[i]) % D] = {1, j};
            }
            if (dp[i + 1][j] < dp[i][j]) {
                dp[i + 1][j] = dp[i][j];
                wr[i + 1][j] = {0, j};
            }
        }
    }
    if (dp[n][d] == -INF) {
        cout << -1 << '\n';
        return 0;
    } else {
        int cj = d;
        vector<int> ans;
        for (int i = n; i > 0; i--) {
            if (wr[i][cj].first) {
                ans.push_back(i);
            }
            cj = wr[i][cj].second;
        }
        reverse(ans.begin(), ans.end());
        if (ans.size() + c1 == 0) {
            cout << -1 << endl;
            exit(0);
        }
        cout << ans.size() + c1 << endl;
        for (auto t : ans) {
            cout << a[t - 1] << ' ';
        }
        for (int i = 0; i < c1; i++) {
            cout << 1 << ' ';
        }
        cout << endl;
    }
}