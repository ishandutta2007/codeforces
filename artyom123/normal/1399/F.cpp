#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

vector<vector<int>> dp;
vector<vector<int>> lft;

int get(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    int add = count(all(lft[l]), r);
    dp[l][r] = max(dp[l][r], add + get(l + 1, r));
    for (auto &right : lft[l]) {
        if (right >= r) continue;
        dp[l][r] = max(dp[l][r], add + get(l, right) + get(right + 1, r));
    }
    return dp[l][r];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n), r(n);
        vector<int> val;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            val.pb(l[i]);
            val.pb(r[i]);
        }
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        for (int i = 0; i < n; i++) {
            l[i] = lower_bound(all(val), l[i]) - val.begin();
            r[i] = lower_bound(all(val), r[i]) - val.begin();
        }
        int sz = val.size();
        dp = vector<vector<int>>(sz, vector<int>(sz, -1));
        lft = vector<vector<int>>(sz);
        for (int i = 0; i < n; i++) {
            lft[l[i]].pb(r[i]);
        }
        cout << get(0, sz - 1) << "\n";
    }
    return 0;
}