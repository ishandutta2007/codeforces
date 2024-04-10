/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int n, a[N + 10], h[N + 10];
set<pair<int, int> > s;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        for (int j = 30; j; j--)
            if ((a[i] >> j) & 1) {
                h[i] = j;
                break;
            }
    }
    for (int l = 1; l <= n; l++) {
        int mx = 1 << (h[l] + 1);
        for (int r = l + 2, sum = a[l + 1]; r <= n; r++) {
            if (sum >= mx) break;
            if ((a[l] ^ a[r]) == sum) s.insert(make_pair(l, r));
            sum += a[r];
        }
    }
    for (int r = n; r > 2; r--) {
        int mx = 1 << (h[r] + 1);
        for (int l = r - 2, sum = a[r - 1]; l; l--) {
            if (sum >= mx) break;
            if ((a[l] ^ a[r]) == sum) s.insert(make_pair(l, r));
            sum += a[l];
        }
    }
    return printf("%d\n", s.size()), 0;
}