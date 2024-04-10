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

char a[1111][1111];
int kb[1111];
int d[1111][2];

int main() {
    int n, m, x, y;
    scanf("%d %d %d %d\n", &n, &m, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++) {
            kb[j] += (a[i][j] == '#' ? 1 : 0);
        }
    }
    for (int i = 0; i <= m; i++) {
        d[i][1] = d[i][0] = 1e9;
    }
    d[0][0] = d[0][1] = 0;
    for (int i = x; i <= m; i++) {
        int ktb = 0, ktw = 0;
        for (int j = 0; j < x - 1; j++) {
            ktw += kb[i - j - 1];
            ktb += n - kb[i - j - 1];
        }
        for (int j = x; j <= y && i - j >= 0; j++) {
            ktw += kb[i - j];
            ktb += n - kb[i - j];
            d[i][0] = min(d[i][0], d[i - j][1] + ktb);
            d[i][1] = min(d[i][1], d[i - j][0] + ktw);
        }
    }

    cout << min(d[m][0], d[m][1]);


    return 0;
}