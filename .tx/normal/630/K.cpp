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

int main() {
    lint n;
    cin >> n;
    lint f10 = 1;
    for (int i = 2; i <= 10; i++) {
        f10 *= i;
    }
    lint x = n % f10;
    lint cx = 0;
    lint c10 = 0;
    for (int i = 1; i <= f10; i++) {
        bool ok = true;
        for (int j = 2; j <= 10; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            c10++;
            if (i <= x) {
                cx++;
            }
        }
    }

    cout << cx + c10 * (n / f10);

    return 0;
}