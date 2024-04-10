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

char a[555][555];

int rows[555][555];
int cols[555][555];

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
//        puts(a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == '.' && a[i][j - 1] == '.') {
                rows[i][j] = 1;
            }
            rows[i][j] += rows[i][j - 1];
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d ", rows[i][j]);
//        }
//        puts("");
//    }
//    puts("");


    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j][i] == '.' && a[j - 1][i] == '.') {
                cols[j][i] = 1;
            }
            cols[j][i] += cols[j - 1][i];
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d ", cols[i][j]);
//        }
//        puts("");
//    }

    scid(q);
    while (q-- > 0) {
        sciid(r1, c1);
        sciid(r2, c2);
        --r1; --c1; --r2; --c2;
        int res = 0;
        for (int i = r1; i <= r2; i++) {
            res += rows[i][c2];
            res -= rows[i][c1];
        }
        for (int i = c1; i <= c2; i++) {
            res += cols[r2][i];
            res -= cols[r1][i];
        }
        printf("%d\n", res);
    }

    return 0;
}