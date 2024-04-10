#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int len = 0;
    for (int step = (1 << 18); step > 0; step /= 2) {
        int cLen = len + step;
        if (cLen > SZ(s)) {
            continue;
        }
        int cntAp[26] = {0};
        bool canBe[26];
        for (int i = 0; i < cLen; ++i) {
            cntAp[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            canBe[i] = cntAp[i];
        }
        for (int i = cLen; i < SZ(s); ++i) {
            cntAp[s[i] - 'a']++;
            if (--cntAp[s[i - cLen] - 'a'] == 0) {
                canBe[s[i - cLen] - 'a'] = false;
            }
        }
        bool ok = false;
        for (int i = 0; i < 26; ++i) {
            ok |= canBe[i];
        }
        if (!ok) {
            len += step;
        }
    }
    len++;
    cout << len << '\n';
}