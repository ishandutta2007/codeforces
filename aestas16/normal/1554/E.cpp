// 392699

#include <bits/stdc++.h>

#define int long long

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, P = 998244353;

int ans, k, flag, p2[N + 10], Ans[N + 10];
vector<int> c[N + 10], e[N + 10];

void Init() {
    p2[0] = 1;
    for (int i = 1; i <= N; i++) p2[i] = p2[i - 1] * 2 % P;
    for (int i = 2; i <= N; i++)
        for (int j = i; j <= N; j += i) c[j].push_back(i);
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dfs(int u, int fa) {
    if (flag == 0) return 0;
    int deg = e[u].size();
    for (auto v : e[u])
        if (fa != v) deg -= dfs(v, u);
    if (deg % k && (deg - 1) % k) flag = 0;
    if (deg % k == 0) return ans = gcd(ans, deg), 1;
    return ans = gcd(ans, (deg - 1)), 0;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init();
    for (int T = fr(); T--;) {
        int n = fr(), f = p2[n - 1], qwq = 0;
        for (int i = 1; i <= n; i++) e[i].clear(), Ans[i] = 0;
        for (int i = 2, u, v; i <= n; i++) fr(u), fr(v), e[u].push_back(v), e[v].push_back(u);
        for (auto i : c[n - 1]) {
            ans = 0, flag = 1, k = i, dfs(1, 0);
            if (flag) Ans[ans] = 1;
        }
        for (int i = 2; i <= n; i++) qwq = (qwq + Ans[i]) % P;
        Ans[1] = (f - qwq + P) % P;
        for (int i = 1; i <= n; i++) printf("%lld ", Ans[i]);
        puts("");
    }
    return 0;
}