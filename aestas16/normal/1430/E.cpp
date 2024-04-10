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

int n, ans, pos[N + 10];
vector<int> id[30];
char str[N + 10];

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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) id[str[i] - 'a'].push_back(i);
    for (int i = 1; i <= n; i++) pos[i] = id[str[i] - 'a'].back(), id[str[i] - 'a'].pop_back(), ans += qsum(pos[i] - 1), update(pos[i], 1);
    return printf("%lld\n", ans), 0;
}