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

vector <int> vec[N];
queue <int> q;
ll s[N];
int a[N], b[N], f[N], l[N], r[N], cnt[N];
int T, n, m;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) read(b[i]), s[i] = s[i - 1] + a[i] - b[i];
        for (int i = 1; i <= n + 1; i++) f[i] = i, vec[i].clear();
        for (int i = 1; i <= m; i++) {
            cnt[i] = 0;
            read(l[i]); read(r[i]);
            if (s[l[i] - 1] != 0) {
                ++cnt[i];
                vec[l[i]].push_back(i);
            }
            if (s[r[i]] != 0) {
                ++cnt[i];
                vec[r[i]].push_back(i);
            }
            if (!cnt[i]) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop(); int tmp = l[u];
            while (find(tmp) <= r[u]) {
                tmp = find(tmp);
                for (auto i : vec[tmp]) {
                    --cnt[i];
                    if (!cnt[i]) q.push(i);
                }
                f[tmp] = find(tmp + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) {
                f[find(i)] = find(i + 1);
            }
        }
        printf("%s\n", find(1) == n + 1 ? "YES" : "NO");
    }
    return 0;
}