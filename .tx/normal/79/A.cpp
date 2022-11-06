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

int main() {
    sciid(x, y);
    for (int i = 0; ; i++) {
        if (y < 2 || x * 10 + y < 22) {
            cout << (i % 2 == 0 ? "Hanako" : "Ciel");
            break;
        }
        if (i % 2 == 0) {
            if (x >= 2) {
                x -= 2;
                y -= 2;
            } else if (x >= 1) {
                x -= 1;
                y -= 12;
            } else {
                y -= 22;
            }
        } else {
            if (y >= 22) {
                y -= 22;
            } else if (y >= 12) {
                x -= 1;
                y -= 12;
            } else {
                x -= 2;
                y -= 2;
            }
        }
    }


    return 0;
}