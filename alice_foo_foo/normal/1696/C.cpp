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

const int N = 1e5 + 5;

int a[N], b[N], A[N], B[N]; ll ca[N], cb[N];
int T, n, m, x;

void solve(int *a, int *b, ll *c, int &n) {
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int now = a[i], cnt = 1;
        while (now % x == 0) {
            now /= x;
            cnt *= x;
        }
        if (len && b[len] == now) c[len] += cnt;
        else {
            ++len;
            b[len] = now;
            c[len] = cnt;
        }
    }
    n = len;
}

int main() {
    read(T);
    while (T--) {
        ll sum = 0;
        read(n); read(x);
        for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
        read(m);
        for (int i = 1; i <= m; i++) read(b[i]), sum -= b[i];
        if (sum != 0) {
            printf("No\n");
            continue;
        }
        solve(a, A, ca, n); solve(b, B, cb, m);
        if (n != m) {
            printf("No\n");
            continue;
        }
        int ok = 1;
        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i] || ca[i] != cb[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}