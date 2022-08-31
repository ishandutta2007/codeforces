#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5, INF = 1e9;

struct seg_t {
    int mn[N << 2];

    void update(int u) {
        mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
    }

    void reset(int n) {
        memset(mn, 0x7f, (n + 1) * 4 * 4);
    }

    void modify(int u, int l, int r, int x, int y) {
        if (l == r) {
            mn[u] = y;
            return;
        }
        int mid = (l + r) >> 1;
        if (mid >= x) modify(u << 1, l, mid, x, y);
        else modify(u << 1 | 1, mid + 1, r, x, y);
        update(u);
    }

    int query(int u, int L, int R, int l, int r) {
        if (l <= L && R <= r) return mn[u];
        int mid = (L + R) >> 1, ans = INF;
        if (mid >= l) ans = min(ans, query(u << 1, L, mid, l, r));
        if (mid + 1 <= r) ans = min(ans, query(u << 1 | 1, mid + 1, R, l, r));
        return ans;
    }
} tr1, tr2;

int st1[N], st2[N], dp[N], a[N];
int T, n, top, top1, top2;

int main() {
    read(T);
    while (T--) {
        read(n);
        tr1.reset(n); tr2.reset(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        top1 = top2 = 0;
        for (int i = n; i >= 1; i--) {
            int pos1 = n, pos2 = n;
            while (top1 && a[i] > a[st1[top1]]) {
                tr1.modify(1, 1, n, st1[top1], INF);
                --top1;
            }
            while (top2 && a[i] < a[st2[top2]]) {
                tr2.modify(1, 1, n, st2[top2], INF);
                --top2;
            }
            if (top1) pos2 = st1[top1] - 1;
            if (top2) pos1 = st2[top2] - 1;
            dp[i] = min(tr1.query(1, 1, n, i, pos1), tr2.query(1, 1, n, i, pos2)) + 1;
            if (i == n) dp[i] = 0;
            tr1.modify(1, 1, n, i, dp[i]); tr2.modify(1, 1, n, i, dp[i]);
            st1[++top1] = i; st2[++top2] = i;
        }
        print(dp[1], '\n');
    }
    return 0;
}