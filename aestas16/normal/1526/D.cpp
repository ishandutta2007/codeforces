/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int n, pos[N + 10];
string s, t;
vector<int> id[30];
map<char, int> cnt;

namespace BIT {
    int c[N + 10];
    int lowbit(int x) { return x & (-x); }
    void update(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i] += val;
    }
    int qsum(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += c[i];
        return ret;
    }
} // namespace BIT
using namespace BIT;

int solve() {
    int tot = 0, ret = 0;
    cnt.clear();
    for (int i = 0; i < n; i++) pos[++tot] = id[t[i] - 'A'][cnt[t[i]]++];
    for (int i = 0; i <= n; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) ret += pos[i] - 1 - qsum(pos[i] - 1), update(pos[i], 1);
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        cin >> s, n = s.size();
        for (int i = 0; i < 26; i++) id[i].clear();
        for (int i = 0; i < n; i++) id[s[i] - 'A'].push_back(i + 1);
        string ans;
        int Max = 0, p[] = {0, 'A', 'N', 'O', 'T'};
        do {
            t = "";
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= id[p[i] - 'A'].size(); j++) t += p[i];
            int tmp = solve();
            if (tmp >= Max) Max = tmp, ans = t;
        } while (next_permutation(p + 1, p + 5));
        cout << ans << endl;
    }
    return 0;
}