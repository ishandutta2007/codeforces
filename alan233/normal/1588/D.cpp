// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

int toid(char x) {
    return 'A' <= x && x <= 'Z' ? x - 'A' : x - 'a' + 26;
}
char toc(int x) {
    return x < 26 ? 'A' + x : 'a' + x - 26;
}

int n;
int le[15];
char s[15][120]; bool ss[15][120];
int pos[15][120][2], nxt[15][120][52];
int f[52][1024], fc[52][1024], fs[52][1024];

int sol(int c, int s) {
    int nowpos[15];
    for (int i = 0; i < n; i++) {
        nowpos[i] = pos[i][c][s >> i & 1];
        if (nowpos[i] == -1) return -1;
    }
    if (f[c][s] >= 0) return f[c][s];
    f[c][s] = 0;
    for (int cc = 0; cc < 52; cc++) {
        int tpos[15];
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            tpos[i] = nxt[i][nowpos[i]][cc];
            if (tpos[i] == -1) flag = 0;
        }
        if (!flag) continue;
        int ts = 0;
        for (int i = 0; i < n; i++) ts |= ss[i][tpos[i]] << i;
        int tmp = sol(cc, ts) + 1;
        if (tmp > f[c][s]) {
            f[c][s] = tmp;
            fc[c][s] = cc;
            fs[c][s] = ts;
        }
    }
    return f[c][s];
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i] + 1);
        le[i] = strlen(s[i] + 1);
        for (int j = 1; j <= le[i]; j++) s[i][j] = toid(s[i][j]);
        memset(pos[i], -1, sizeof(pos[i]));
        memset(nxt[i], -1, sizeof(nxt[i]));
    }
    for (int i = 0; i < n; i++) {
        // memset(lst, -1, sizeof(lst));
        for (int j = 1; j <= le[i]; j++) {
            if (pos[i][s[i][j]][0] == -1) pos[i][s[i][j]][0] = j, ss[i][j] = 0;
            else pos[i][s[i][j]][1] = j, ss[i][j] = 1;
        }
        for (int j = le[i]; j >= 1; j--) {
            if (j != le[i]) {
                memcpy(nxt[i][j], nxt[i][j + 1], sizeof(nxt[i][j + 1]));
                nxt[i][j][s[i][j + 1]] = j + 1;
                // for (int k = 0; k < 52; k++)
                //     if (nxt[i][j][k]!=-1)
                //         printf("nxt[%d][%d][%d] = %d\n", i, j, k, nxt[i][j][k]);
            }
        }
    }
    memset(f, 192, sizeof(f));
    int ans = 0, ansc, anss;
    for (int c = 0; c < 52; c++) {
        for (int st = 0; st < 1 << n; st++) {
            int t = sol(c, st) + 1;
            if (t > ans) ans = t, ansc = c, anss = st;
        }
    }
    
    printf("%d\n", ans);
    while (ans--) {
        printf("%c", toc(ansc));
        int tc = fc[ansc][anss];
        int ts = fs[ansc][anss];
        ansc = tc, anss = ts;
    }
    puts("");
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}