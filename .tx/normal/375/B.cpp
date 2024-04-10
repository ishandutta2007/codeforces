#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char a[5555][5555];
int bc[5555], cc[5555];

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        memset(bc, 0, sizeof(bc));
        for (int j = 0; j < n; j++) {
            cc[j] = (cc[j] + 1) & -(a[j][i] - '0');
//            if (a[j][i] == '1') {
//                cc[j]++;
//            } else {
//                cc[j] = 0;
//            }
            bc[cc[j]]++;
        }
        int c = 0;
        for (int j = i + 1; j >= 0; j--) {
            if (bc[j] != 0) {
                c += bc[j];
                ans = max(ans, c * j);
            }
        }
    }
    cout << ans;

    return 0;
}