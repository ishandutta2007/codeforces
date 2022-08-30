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

ll f[N];
int T, n; ll k;

int main() {
    read(T);
    while (T--) {
        read(n); read(k);
        if (n <= 61 && (1ll << (n - 1)) < k) {
            print(-1, '\n');
            continue;
        }
        int now = max(0, n - 61);
        for (int i = 1; i <= now; i++) print(i, ' ');
        while (now < n) {
            for (int j = 1; j <= n - now; j++) {
                ll cnt;
                if (j == n - now) cnt = 1;
                else cnt = 1ll << (n - now - j - 1);
                if (cnt >= k) {
                    for (int k = j; k >= 1; k--) print(now + k, ' ');
                    now += j;
                    break;
                }
                k -= cnt;
            }
        }
        putchar('\n');
    }
    return 0;
}