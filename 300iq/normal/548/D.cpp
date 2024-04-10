#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210000, L = 21;

int t[4 * MAXN];
int a[MAXN];
int bin[MAXN];
int mn[MAXN][L];
int n;

void build(int i) {
    mn[i][0] = a[i];
    for (int j = 1; j < L; j++) {
        if (i + (1 << (j - 1)) < n) {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int fl(int x) {
    int j = 0;
    while ((1 << j) <= x) {
        j++;
    }
    return j - 1;
}

int get(int l, int r) {
    int j = bin[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}

int res[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        bin[i] = fl(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        build(i);
    }
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (i + m < n) {
                if (get(i, i + m) == a[i]) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                r = m;
            }
        }
        int left_len = l + 1;
        l = 0;
        r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (i - m > -1) {
                if (get(i - m, i) == a[i]) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                r = m;
            }
        }
        int len = left_len + l;
        res[len] = max(res[len], a[i]);
    }
    int cur = 0;
    for (int p = n; p >= 1; p--) {
        cur = max(cur, res[p]);
        res[p] = cur;
    }
    for (int p = 1; p <= n; p++) {
        printf("%d ", res[p]);
    }
}