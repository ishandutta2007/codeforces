#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

string a[8];

int main() {
    init_cin();
    int t;
    cin >> t;
    int n = 8;
    while (t-- > 0) {
        int px[2];
        int py[2];
        int p = 0;
        for (int i = 0; i < 8; i++) {
            cin >> a[i];
            for (int j = 0; j < 8; j++) {
                if (a[i][j] == 'K') {
                    px[p] = i;
                    py[p] = j;
                    p++;
                }
            }
        }
        if ((px[0] - px[1]) % 2 != 0 || (py[0] - py[1]) % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        if (abs(px[0] - px[1]) / 2 % 2 != 0 || abs(py[0] - py[1]) / 2 % 2 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }


    return 0;
}