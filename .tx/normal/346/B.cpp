#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

int d[111][111][111];
int p[111][111][111];

char s[111];
char t[111];
char v[111];
int pr[111];
int prd[111][26];

int main() {
    memset(d, -1, sizeof(int) * 111 * 111 * 111);
    scanf("%s", s);
    scanf("%s", t);
    scanf("%s", v);
    int sl = strlen(s);
    int tl = strlen(t);
    int vl = strlen(v);

    d[0][0][0] = 0;

    for (int i = 1; i < vl; i++) {
        int x = pr[i - 1];
        while (x > 0 && v[x] != v[i]) {
            x = pr[x - 1];
        }
        if (v[x] == v[i]) {
            x++;
        }
        pr[i] = x;
    }

    for (int i = 1; i < vl; i++) {
        for (int j = 0; j < 26; j++) {
            char c = j + 'A';
            int x = pr[i - 1];
            while (x > 0 && v[x] != c) {
                x = pr[x - 1];
            }
            if (v[x] == c) {
                x++;
            }
            prd[i][j] = x;
        }
    }

    for (int i = 0; i < sl; i++) {
        for (int j = 0; j < tl; j++) {
            for (int k = 0; k < vl; k++) {
                if (d[i][j][k] == -1) {
                    continue;
                }
                if (d[i + 1][j][k] < d[i][j][k]) {
                    d[i + 1][j][k] = d[i][j][k];
                    p[i + 1][j][k] = 1;
                }
                if (d[i][j + 1][k] < d[i][j][k]) {
                    d[i][j + 1][k] = d[i][j][k];
                    p[i][j + 1][k] = 2;
                }
                if (s[i] == t[j]) {
                    int x = 0;
                    if (s[i] == v[k]) {
                        x = k + 1;
                    } else {
                        x = prd[k][s[i] - 'A'];
                    }
                    if (x == vl) {
                        continue;
                    }
                    if (d[i + 1][j + 1][x] < d[i][j][k] + 1) {
                        d[i + 1][j + 1][x] = d[i][j][k] + 1;
                        p[i + 1][j + 1][x] = -k - 1;
                    }
                }
            }
        }
    }

    int mx = 0;
    int x = -1, y = -1, z = -1;
    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= tl; j++) {
            for (int k = 0; k < vl; k++) {
                if (d[i][j][k] > mx) {
                    mx = d[i][j][k];
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }

    cerr << mx << endl;

    if (mx == 0) {
        cout << 0;
        return 0;
    }

    string ans = "";
    while (true) {
        int cp = p[x][y][z];
        if (cp == 0) {
            break;
        }
        if (cp == 1) {
            x--;
        } else if (cp == 2) {
            y--;
        } else {
            x--;
            y--;
            z = -cp - 1;
            ans += s[x];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;


    return 0;
}