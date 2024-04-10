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

int a[111];
int d[111][3];

int main() {
    scid(n);
    rvei(a, n);
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] & 1) {
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + 1;
        }
        if (a[i - 1] & 2) {
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + 1;
        }
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
    }

//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << d[j][i] << " ";
//        }
//        cout << "\n";
//    }

    cout << n - max(max(d[n][0], d[n][1]), d[n][2]);

    return 0;
}