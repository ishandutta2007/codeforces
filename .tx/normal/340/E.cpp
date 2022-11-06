#include <bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

lint d[4444][2222];
const int mod = 1e9 + 7;

bool st[2222];
int a[2222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x != -1) {
            st[--x] = true;
        }
        a[i] = x;
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (st[i]) {
                x++;
            } else {
                y++;
            }
        }
    }

    d[0][0] = 1;
    for (int i = 1; i < 4444; i++) {
        d[i][0] = d[i - 1][0] * i % mod;
        d[i][1] = d[i][0] * i % mod;
    }

    for (int j = 2; j <= y; j++) {
        for (int i = 0; i + 1 < 4444; i++) {
            d[i][j] = (d[i + 1][j - 2] * (j - 1) + d[i][j - 1] * i) % mod;
        }
    }

    cout << d[x][y];


    return 0;
}