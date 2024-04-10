#include<bits/stdc++.h>

using namespace std;

int cnt[27];

inline int oks(int n, int k, int t) {
    if (n % t == 0 && k % t == 0) {
        int sum = 0;
        for (int j = 0; j < 26; ++j) sum += cnt[j] / (n / t);
        return sum >= t;
    }
    return 0;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k, flag;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;
        flag = 1;
        for (int ans = n; ans >= 1 && flag; --ans) {
            for (int d = 1; d * d <= ans; ++d) {
                if (oks(ans, k, d) || oks(ans, k, ans / d)) {
                    cout << ans << '\n';
                    flag = 0;
                    break;
                }
            }
        }
        assert(flag == 0);
    }
    return 0;
}