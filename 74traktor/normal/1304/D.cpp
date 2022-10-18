#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int ans1[maxn], ans2[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ptr = n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) ans1[i] = 0, ans2[i] = 0;
        ptr = n;
        string s;
        cin >> s;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '<') {
                int j = i;
                while (j < n - 1 && s[i] == s[j]) ++j;
                for (int pos = j - 1; pos >= i; --pos) ans1[pos + 2] = ptr--;
                cnt += (j - i);
                i = j - 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (ans1[i] == 0) ans1[i] = ptr--;
            cout << ans1[i] << ' ';
        }
        cout << '\n';
        ptr = n - cnt + 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '<') {
                ans2[i + 2] = ptr++;
            }
        }
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            int j = i;
            if (ans2[j] != 0) continue;
            while (j <= n && ans2[j] == 0) ++j;
            for (int pos = j - 1; pos >= i; --pos) ans2[pos] = cur++;
            i = j - 1;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans2[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}