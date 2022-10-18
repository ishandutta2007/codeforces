#include <bits/stdc++.h>

using namespace std;

int lef[200005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans, t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        string s;
        cin >> s;
        n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (s[i] == '0') lef[i] = 0;
                else lef[i] = n + 20;
            }
            else {
                if (s[i] == '1') lef[i] = n + 20;
                else {
                    lef[i] = min(i, lef[i - 1]);
                }
            }
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j >= max(0, i - 20); --j) {
                sum += ((1 << (i - j)) * (s[j] - '0'));
                if (sum == i - j + 1) ans++;
                if (j == max(0, i - 20) && sum != i - j + 1) {
                    int L = i - sum + 1;
                    if (L < j && L >= 0) {
                        if (lef[max(0, i - 20) - 1] <= L) {
                            ans++;
                            //cout << sum << endl;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}