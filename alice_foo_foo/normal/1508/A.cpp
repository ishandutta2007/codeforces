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

const int N = 2e5 + 5;

char a[N], b[N], c[N];
int s[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        scanf("%s%s%s", a + 1, b + 1, c + 1);
        int tem[3], cnt[2] = {0, 0};
        for (int i = 1; i <= 2 * n; i++) ++cnt[a[i] - '0'];
        if (cnt[0] <= cnt[1]) tem[0] = 0;
        else tem[0] = 1;
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= 2 * n; i++) ++cnt[b[i] - '0'];
        if (cnt[0] <= cnt[1]) tem[1] = 0;
        else tem[1] = 1;
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= 2 * n; i++) ++cnt[c[i] - '0'];
        if (cnt[0] <= cnt[1]) tem[2] = 0;
        else tem[2] = 1;
        if (tem[0] == tem[1]) {

        } else if (tem[0] == tem[2]) {
            swap(b, c);
            swap(tem[1], tem[2]);
        } else if (tem[1] == tem[2]) {
            swap(a, c);
            swap(tem[0], tem[2]);
        }
        int rev = 0;
        if (tem[0] == 1) {
            for (int i = 1; i <= 2 * n; i++) {
                a[i] ^= 1;
                b[i] ^= 1;
            }
            rev = 1;
        }
        for (int i = 0; i <= 2 * n; i++) s[i] = 0;
        int maxn = 0;
        int now = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (a[i] == '1') ++now;
            if (a[i] == '0') ++s[now];
            // cout << a[i];
        }
        // cout << endl;
        maxn = now;
        now = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (b[i] == '1') ++now;
            if (b[i] == '0') ++s[now];
            // cout << b[i];
        }
        // cout << endl;
        maxn = max(maxn, now);
        // cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << endl;
        int tot = 0;
        for (int i = 0; i <= maxn; i++) {
            if (i != 0) putchar('1' ^ rev), ++tot;
            for (int j = 1; j <= s[i]; j++) putchar('0' ^ rev), ++tot;
        }
        for (int i = 1; i <= 3 * n - tot; i++) putchar('0');
        putchar('\n');
    }
    return 0;
}