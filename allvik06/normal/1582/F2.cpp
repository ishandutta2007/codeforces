#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
const int INF = 1e9;
const int MAXV = 9000;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> dp(MAXV, MAXV);
    vector <vector <int>> flex(MAXV + 1);
    dp[0] = -1;
    for (int i = 1; i < MAXV; ++i) flex[i].push_back(i);
    for (int i = 0; i < n; ++i) {
        while (!flex[a[i]].empty()) {
            int x = flex[a[i]].back();
            flex[a[i]].pop_back();
            while (dp[x] > a[i]) {
                flex[dp[x]].push_back(x ^ dp[x]);
                dp[x]--;
            }
        }
    }
    vector <int> all;
    for (int i = 0; i < MAXV; ++i) {
        if (dp[i] != MAXV) all.push_back(i);
    }
    cout << (int)all.size() << "\n";
    for (int i : all) cout << i << " ";
}

/*

 */