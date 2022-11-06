#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 2009;
bitset<MxN> dp[MxN * 2];

void f() {
    int n, mx_so_far = 0;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        if (x > mx_so_far) {
            mx_so_far = x;
            v.push_back({x});
        } else
            v.back().push_back(x);
    }
    vector<bitset<2001>> dp(v.size() + 1, 0);
    for (int i = v.size(); i >= 0; --i)
        for (int s = n; s >= 0; --s)
            dp[i][s] = i == v.size() ? s == 0 : (v[i].size() <= s && dp[i + 1][s - v[i].size()]) || dp[i + 1][s];

        if(!dp[0][n]) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";

        vector<int> p1, p2;
        for(int i = 0, s = n; i < v.size(); ++i) {
            assert(dp[i][s]);
            if(dp[i+1][s])
                p1.insert(p1.end(), v[i].begin(), v[i].end());
            else {
                p2.insert(p2.end(), v[i].begin(), v[i].end());
                s -= v[i].size();
            }
        }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}