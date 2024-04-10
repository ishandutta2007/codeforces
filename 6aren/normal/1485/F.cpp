#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int &e : b) cin >> e;
        map<int, int> cnt;
        int cur = 1;
        cnt[0] = 1;
        int pref = b[0];
        for (int i = 1; i < n; i++) {
            int ncur = (cur - cnt[pref] + MOD) % MOD;
            cnt[pref] = (cnt[pref] + ncur) % MOD;
            cur = (cur + ncur) % MOD;
            pref += b[i];
        }
        cout << cur << '\n';
    }   

    return 0;
}