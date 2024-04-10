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

const int N = 5e5, S = 20;

int n;

struct Basis {
    int cnt, p[S + 10], pos[S + 10];
    void insert(int x, int id) {
        for (int i = S; ~i; i--)
            if (x & (1ll << i)) {
                if (p[i] == 0) return p[i] = x, pos[i] = id, void();
                else if (pos[i] < id) swap(pos[i], id), swap(p[i], x);
                x ^= p[i];
            }
    }
    int qmax(int l) {
        int ret = 0;
        for (int i = S; ~i; i--)
            if (p[i] && pos[i] >= l) ret = max(ret, ret ^ p[i]);
        return ret;
    }
} b[N + 10];

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1], b[i].insert(fr(), i);
    for (int i = 1, q = fr(); i <= q; i++) {
        int l = fr(), r = fr();
        printf("%lld\n", b[r].qmax(l));
    }
    return 0;
}