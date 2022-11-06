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

int a[555];
bool d[555][555][555];

int main() {
    sciid(n, k);
    rea(a, n);

    d[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int p = 0; p <= k; p++) {
                d[i][j][p] |= d[i - 1][j][p];
                int ai = a[i - 1];
                if (j >= ai) {
                    d[i][j][p] |= d[i - 1][j - ai][p];
                    if (p >= ai) {
                        d[i][j][p] |= d[i - 1][j - ai][p - ai];
                    }
                }
            }
        }
    }

//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= k; j++) {
//            for (int p = 0; p <= k; p++) {
//                cout << (int) d[i][j][p] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }

    vector<int> ans;
    for (int i = 0; i <= k; i++) {
        if (d[n][k][i]) {
            ans.push_back(i);
        }
    }


    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}