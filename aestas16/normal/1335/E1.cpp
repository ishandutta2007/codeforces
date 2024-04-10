#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 392699, A = 1e2;

vector<int> qwq[A + 5];

int n, a[N + 5], l[A + 5], r[A + 5], cnt[A + 5][A + 5];

int ffind(int col, int x) {
    int l = 0, r = qwq[col].size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (qwq[col][mid] == x) return mid;
        if (qwq[col][mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void clr(int i) { vector<int> tmp; swap(tmp, qwq[i]); }

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        int up = 0, ans = 0;
        fr(n);
        for (int i = 1; i <= n; i++) fr(a[i]), qwq[a[i]].push_back(i), up = max(up, a[i]);
        for (int i = 1; i <= up; i++) {
            l[i] = 1, r[i] = n;
            for (int j = 1; j <= up; j++) cnt[i][j] = qwq[j].size();
            ans = max(ans, (int)qwq[i].size());
        }
        for (int i = 1; i <= n; i++) {
            int p = ffind(a[i], i);
            int L = i + 1, R = qwq[a[i]][qwq[a[i]].size() - p - 1] - 1, c = 0;
            if (L > R) continue;
            while (l[a[i]] < L) cnt[a[i]][a[l[a[i]]]]--, l[a[i]]++;
            while (r[a[i]] > R) cnt[a[i]][a[r[a[i]]]]--, r[a[i]]--;
            for (int j = 1; j <= up; j++) c = max(c, cnt[a[i]][j]);
            ans = max(ans, (p + 1) * 2 + c);
        }
        printf("%d\n", ans);
        for (int i = 1; i <= up; i++) clr(i);
    }
    return 0;
}