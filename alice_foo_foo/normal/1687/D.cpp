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

const int N = 1e6 + 5;

mt19937 rng(time(0));

int a[N];
int n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (a[i] == a[i - 1]) {
            --i; --n;
            continue;
        }
    }
    shuffle(a + 2, a + n + 1, rng);
    for (int i = 2; i <= n; i++) a[i] -= a[1];
    for (int i = 1; ; i++) {
        ll l = max((ll)a[1], 1ll * i * i), r = 1ll * i * (i + 1), tl, tr, x;
        for (int j = 2; j <= n && l <= r; j++) {
            x = l + a[j];
            int tmp = floor(sqrt(x + 0.5));
            tl = 1ll * tmp * tmp; tr = tl + tmp;
            if (tl <= x && x <= tr) {
                tl -= a[j]; tr -= a[j];
                l = max(l, tl); r = min(r, tr);
            } else {
                ++tmp; tl = 1ll * tmp * tmp; tr = tl + tmp;
                tl -= a[j]; tr -= a[j];
                l = max(l, tl); r = min(r, tr);
            }
        }
        if (l <= r) {
            print(l - a[1], '\n');
            return 0;
        }
    }
    return 0;
}