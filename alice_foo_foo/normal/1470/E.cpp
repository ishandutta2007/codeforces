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

const int N = 30005;

struct atom {
    int a, b;
    atom (int k1 = 0, int k2 = 0) : a(k1), b(k2) {}
};

ll f[N][5], sum[N][5][16];
int a[N];
int T, n, c, q;

ll getf(atom x) { return f[x.a][x.b]; }

void addf(atom x, ll y) { f[x.a][x.b] += y; }

int main() {
    read(T);
    while (T--) {
        memset(f, 0, sizeof(f));
        memset(sum, 0, sizeof(sum));
        read(n); read(c); read(q);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 0; i <= 4; i++) f[n + 1][i] = 1;
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j <= 4; j++) {
                for (int k = 0; k <= j && i + k <= n; k++) {
                    if (a[i + k] < a[i]) {
                        sum[i][j][0] += getf(atom(i + k + 1, j - k));
                    }
                    addf(atom(i, j), getf(atom(i + k + 1, j - k)));
                }
                for (int k = 1; k <= 15; k++) {
                    sum[i][j][k] = sum[i][j][k - 1];
                    if (i + (1 << (k - 1)) <= n) sum[i][j][k] += sum[i + (1 << (k - 1))][j][k - 1];
                }
            }
        }
        while (q--) {
            int pos; ll rk;
            read(pos); read(rk);
            if (f[1][c] < rk) {
                print(-1, '\n');
                continue;
            }
            atom now = atom(1, c);
            while (1) {
                ll ss = 0;
                for (int i = 15; i >= 0; i--) {
                    if (now.a + (1 << i) <= n + 1 && ss + sum[now.a][now.b][i] < rk && rk <= ss + sum[now.a][now.b][i] + getf(atom(now.a + (1 << i), now.b))) {
                        ss += sum[now.a][now.b][i];
                        now.a += (1 << i);
                    }
                }
                if (now.a > pos) {
                    print(a[pos], '\n');
                    break;
                }
                rk -= ss;
                vector <pii> seq;
                for (int i = 0; i <= now.b && now.a + i <= n; i++) {
                    seq.push_back(make_pair(a[now.a + i], i));
                }
                sort(seq.begin(), seq.end());
                int tmp = now.a;
                for (int i = 0; i < (int)seq.size(); i++) {
                    if (rk <= getf(atom(now.a + seq[i].second + 1, now.b - seq[i].second))) {
                        now = atom(now.a + seq[i].second + 1, now.b - seq[i].second);
                        break;
                    }
                    rk -= getf(atom(now.a + seq[i].second + 1, now.b - seq[i].second));
                }
                if (now.a > pos) {
                    print(a[now.a - 1 - (pos - tmp)], '\n');
                    break;
                }
            }
        }
    }
    return 0;
}