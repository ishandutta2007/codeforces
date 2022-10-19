#include <bits/stdc++.h>

using namespace std;

int solve(vector <int>& a) {
    if (a.size() == 1 || a.size() == 0) return 0;
    vector <int> b(33);
    vector <vector <int>> bb(33);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            ++b[0];
            continue;
        }
        for (int j = 32; j > 0; --j) {
            if ((a[i] >> (j - 1)) & 1) {
                ++b[j];
                bb[j].push_back(a[i] - (1 << (j - 1)));
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 33; ++i) {
        ans += max(0, b[i] - 1);
    }
    for (int i = 0; i < 33; ++i) {
        int tmp = solve(bb[i]), kol = 0;
        for (int j = 0; j < i; ++j) {
            kol += b[j];
        }
        tmp += max(0, kol - 1);
        for (int j = i + 1; j < 33; ++j) {
            tmp += max(0, b[j] - 1);
        }
        ans = min(ans, tmp);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(a);
}