#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5;

int n, w = 1, ans, a[N + 10];
vector<int> p;

int solve(int x) {
    int ret = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < x) ret += x - a[i];
        else ret += min(a[i] % x, x - a[i] % x);
    return ret * w;
}

void work(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            p.push_back(i);
            while (x % i == 0) x /= i;
        }
    if (x > 1) p.push_back(x);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    mt19937 rnd((unsigned long long)(new char));
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    ans = solve(2);
    for (int i = 2; i <= n; i++) swap(a[i], a[rnd() % (i - 1) + 1]);
    for (int _ = 30, pos; _--;) pos = rnd() % n + 1, work(a[pos]), work(a[pos] + 1), work(a[pos] - 1);
    for (auto i : p) ans = min(ans, solve(i));
    return printf("%lld\n", ans), 0;
}