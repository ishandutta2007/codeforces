/*
     []
*/

// 392699

#include <bits/stdc++.h>

#define ll long long

using namespace std;

template<class T> void fr(register T &a, register bool f = 0, register char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e6, S = 20;

int n, ans[N + 10];
ll s[N + 10];

namespace BIT {
    ll c[N + 10];
    inline int lowbit(register int x) { return x & (-x); }
    void add(register int pos, register int val) {
        for (register int i = pos; i <= n; i += lowbit(i)) c[i] += val;
    }
    int calc(register ll val) {
        register int pos = 0;
        register ll sum = 0;
        for (register int i = S; ~i; i--)
            if ((pos + (1 << i)) <= n && sum + c[pos + (1 << i)] <= val) pos += (1 << i), sum += c[pos];
        return pos + 1;
    }
} // namespace BIT
using namespace BIT;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (register int i = 1; i <= n; i++) fr(s[i]), add(i, i);
    for (register int i = n; i; i--) ans[i] = calc(s[i]), add(ans[i], -ans[i]);
    for (register int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}