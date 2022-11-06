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

char s[5555];
bool is_p[5555][5555];
int d[5555][5555];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        is_p[i][i] = true;
        d[i][i] = 1;
    }
    for (int i = 0; i + 1 < n; i++) {
        d[i][i + 1] = 2;
        if (s[i] == s[i + 1]) {
            is_p[i][i + 1] = true;
            d[i][i + 1]++;
        }
    }
    for (int l = 2; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            is_p[i][i + l] = is_p[i + 1][i + l - 1] && s[i] == s[i + l];
        }
    }

    for (int l = 2; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            d[i][i + l] = d[i + 1][i + l] + d[i][i + l - 1] - d[i + 1][i + l - 1];
            if (is_p[i][i + l]) {
                d[i][i + l]++;
            }
        }
    }

    scid(q);
    while (q-- > 0) {
        sciid(l, r);
        --l; --r;
        cout << d[l][r] << "\n";
    }

    return 0;
}