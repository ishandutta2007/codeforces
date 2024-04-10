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

lint d[5555][5555];
char s[5555];
char t[5555];

const int mod = 1e9 + 7;

int main() {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int m = strlen(t);
    lint ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            d[i][j] = d[i][j + 1];
            if (s[i] == t[j]) {
                d[i][j] += d[i + 1][j + 1] + 1;
                if (d[i][j] >= mod) {
                    d[i][j] -= mod;
                }
            }
        }
        ans += d[i][0];
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans;

    return 0;
}