#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = 2010;

const int p = (int)1e9 + 7, q = (int)1e9 + 9;

pii operator +(pii a, pii b) {
    a.first += b.first;
    a.second += b.second;

    if (a.first >= p) {
        a.first -= p;
    }

    if (a.second >= q) {
        a.second -= q;
    }

    return a;
}

pii operator -(pii a, pii b) {
    a.first -= b.first;
    a.second -= b.second;

    if (a.first < 0) {
        a.first += p;
    }

    if (a.second < 0) {
        a.second += q;
    }

    return a;
}

pii operator *(pii a, pii b) {
    a.first = (ll)a.first * b.first % p;
    a.second = (ll)a.second * b.second % q;

    return a;
}

pii t[maxn];
pii s[maxn];
char a[maxn][maxn], b[maxn][maxn];
pii hsh[2][maxn][maxn];

pii get_hsh(int it, int x1, int y1, int x2, int y2) {
    pii cur = hsh[it][x2][y2];

    x1--;
    y1--;

    if (x1 >= 0) {
        cur = cur - hsh[it][x1][y2] * t[x2 - x1];
    }

    if (y1 >= 0) {
        cur = cur - hsh[it][x2][y1] * s[y2 - y1];
    }

    if (x1 >= 0 && y1 >= 0) {
        cur = cur + hsh[it][x1][y1] * t[x2 - x1] * s[y2 - y1];
    }

    return cur;
}

int main() {
    t[0] = mp(1, 1);
    s[0] = mp(1, 1);

    for (int i = 1; i < maxn; i++) {
        t[i] = t[i - 1] * mp(1234567, 1234567);
        s[i]  = s[i - 1] * mp(123456, 123456);
    }

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", b[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pii cur = mp(a[i][j] - 'a' + 1, a[i][j] - 'a' + 1);

            if (i != 0) {
                cur = cur + hsh[0][i - 1][j] * t[1];
            }

            if (j != 0) {
                cur = cur + hsh[0][i][j - 1] * s[1];
            }

            if (i != 0 && j != 0) {
                cur = cur - hsh[0][i - 1][j - 1] * s[1] * t[1];
            }

            hsh[0][i][j] = cur;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pii cur = mp(b[i][j] - 'a' + 1, b[i][j] - 'a' + 1);

            if (i != 0) {
                cur = cur + hsh[1][i - 1][j] * t[1];
            }

            if (j != 0) {
                cur = cur + hsh[1][i][j - 1] * s[1];
            }

            if (i != 0 && j != 0) {
                cur = cur - hsh[1][i - 1][j - 1] * s[1] * t[1];
            }

            hsh[1][i][j] = cur;
        }
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (get_hsh(0, i, 0, i + m - 1, m - 1) == get_hsh(1, 0, j, m - 1, j + m - 1)) {
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }

    throw 1;
}