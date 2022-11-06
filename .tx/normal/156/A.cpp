#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int d[2222][2222];

char s[2222];
char t[2222];

int main() {
    scanf("%s", s);
    scanf("%s", t);

    int n = strlen(s);
    int m = strlen(t);

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = 1e9;
        }
    }

    for (int i = 0; i <= m; i++) {
        d[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
//            d[i][j] = min(d[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1), d[i][j - 1] + 1);
            d[i][j] = d[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1);
        }
    }

//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= m; j++) {
//            cerr << d[i][j] << " ";
//        }
//        cerr << endl;
//    }

    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans = min(ans, d[i][j] + m - j);
        }
    }

    cout << ans;
    return 0;
}