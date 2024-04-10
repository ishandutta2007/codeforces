#include <bits/stdc++.h>

using namespace std;

#define sz(a)           int((a).size())
#define all(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for (int i = 0, _n(b); i < _n; ++i)
#define REP(i,n)        FOR(i, 0, n)

int det(int a, int b, int c, int d) {
    return a * d - b * c;
}

bool inside(int x[4], int y[4], int px, int py) {
    int m = 0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        int d = det(x[i] - px, y[i] - py, x[j] - px, y[j] - py);
        if (d < 0) m |= 1;
        if (d > 0) m |= 2;
    }
    return m != 3;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int x1[4], y1[4], x2[4], y2[4];
    int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
    REP (i, 4) {
        cin >> x1[i] >> y1[i];
        x3 += x1[i];
        y3 += y1[i];
        x1[i] *= 4;
        y1[i] *= 4;
    }
    REP (i, 4) {
        cin >> x2[i] >> y2[i];
        x4 += x2[i];
        y4 += y2[i];
        x2[i] *= 4;
        y2[i] *= 4;
    }
    bool ok = inside(x1, y1, x4, y4) || inside(x2, y2, x3, y3);
    REP (i, 4) {
        ok |= inside(x1, y1, x2[i], y2[i]);
        ok |= inside(x2, y2, x1[i], y1[i]);
    }
    puts(ok ? "YES" : "NO");
    return 0;
}