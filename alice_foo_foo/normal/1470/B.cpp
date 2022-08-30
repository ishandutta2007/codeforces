#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

int a[N], pri[N], isp[N], cnt[N], tmp[N];
int T, n, q, len;

int main() {
    for (int i = 2; i <= 1000; i++) {
        if (!isp[i]) {
            pri[++len] = i;
        }
        for (int j = i + i; j <= 1000; j += i) {
            isp[j] = 1;
        }
    }
    read(T);
    while (T--) {
        read(n);
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            int now = a[i];
            for (int j = 1; j <= len; j++) {
                while (now % (pri[j] * pri[j]) == 0) {
                    now /= (pri[j] * pri[j]);
                }
            }
            tmp[i] = now;
            ++cnt[now];
            ans = max(ans, cnt[now]);
            if (now == 1) {
                ++sum;
                continue;
            }
            if (cnt[now] % 2 == 0) sum += cnt[now];
            else sum -= (cnt[now] - 1);
        }
        read(q);
        for (int i = 1; i <= q; i++) {
            ll w;
            read(w);
            if (w == 0) {
                print(ans, '\n');
            } else {
                print(max(ans, sum), '\n');
            }
        }
        for (int i = 1; i <= n; i++) --cnt[tmp[i]];
    }
    return 0;
}