#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 1e5 + 7;
const int MAXK = 30 + 1;
int a[MAXN];
int y[MAXN][3];
int t[4 * MAXN];
int cnt[MAXK];
int add[MAXN][MAXK];
int del[MAXN][MAXK];

int f(int x, int y) {
    if (x == -1) {
        return y;
    } else if (y == -1) {
        return x;
    } else {
        return (x & y);
    }
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = f(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

int get(int v, int l, int r, int tl, int tr) {
    if (tl >= r || tr <= l) {
        return -1;
    } else if (tl >= l && tr <= r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return f(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}


int main() {
    int n, m;
    int l, r, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        l--, r--;
        y[i][0] = l, y[i][1] = r, y[i][2] = x;
        for (int p = 0; p < MAXK; p++) {
            if (x & (1 << p)) {
                add[l][p]++;
                del[r + 1][p]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < MAXK; p++) {
            cnt[p] += add[i][p] - del[i][p];
        }
        for (int p = 0; p < MAXK; p++) {
            if (cnt[p]) {
                a[i] |= (1 << p);
            }
        }
    }
    build(0, 0, n);
    for (int i = 0; i < m; i++) {
        l = y[i][0], r = y[i][1], x = y[i][2];
        r++;
        if (get(0, l, r, 0, n) != x) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}