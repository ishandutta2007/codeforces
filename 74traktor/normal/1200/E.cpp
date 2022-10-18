#include <bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 1e6 + 2;
int mod1 = 1e9 + 7, mod2 = 2e9 + 11, P1 = 67, P2 = 71, mod3 = 2e9 - 87;

inline int ff(char t) {
    if (t >= 'a' && t <= 'z') return t - 'a' + 1;
    if (t >= 'A' && t <= 'Z') return t - 'A' + 27;
    return t - '0' + 53;
}

int h1[maxn];
int h2[maxn];
int h3[maxn];
int p1[maxn];
int p2[maxn];
int H1[maxn];
int H2[maxn];
int H3[maxn];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sz = 0;
    cin >> n;
    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i < maxn; ++i) p1[i] = p1[i - 1] * P1 % mod1, p2[i] = p2[i - 1] * P2 % mod2;
    string s, ans = "";
    bool f;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        //cout << sz << endl;
        int k = (int)s.size();
        for (int j = 1; j <= k; ++j) {
            H1[j] = (H1[j - 1] + ff(s[j - 1]) * p1[j - 1]) % mod1;
            H2[j] = (H2[j - 1] + ff(s[j - 1]) * p2[j - 1]) % mod2;
            H3[j] = (H3[j - 1] + ff(s[j - 1]) * p1[j - 1]) % mod1;
        }
        f = true;
        for (int j = k; j >= 1; --j) {
            if (sz - j + 1 >= 1) {
                if (H3[j] * p1[sz - j] % mod1 == (h3[sz] - h3[sz - j] + mod1) % mod1 && H1[j] * p1[sz - j] % mod1 == (h1[sz] - h1[sz - j] + mod1) % mod1 && H2[j] * p2[sz - j] % mod2 == (h2[sz] - h2[sz - j] + mod2) % mod2) {
                    f = false;
                    for (int cur = j; cur < k; ++cur) {
                        h1[sz + 1] = (h1[sz] + ff(s[cur]) * p1[sz]) % mod1;
                        h2[sz + 1] = (h2[sz] + ff(s[cur]) * p2[sz]) % mod2;
                        h3[sz + 1] = (h3[sz] + ff(s[cur]) * p1[sz]) % mod1;
                        ans += s[cur];
                        sz++;
                    }
                    break;
                }
            }
        }
        if (f) {
            for (int cur = 0; cur < k; ++cur) {
                h1[sz + 1] = (h1[sz] + ff(s[cur]) * p1[sz]) % mod1;
                h2[sz + 1] = (h2[sz] + ff(s[cur]) * p2[sz]) % mod2;
                h3[sz + 1] = (h3[sz] + ff(s[cur]) * p1[sz]) % mod1;
                ans += s[cur];
                sz++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}