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
    scid(n);
    if (n <= 9) {
        cout << n;
        return 0;
    }
    int ans = 9;
    int p10 = 1;
    for (int len = 2; len <= 9; len++) {
        p10 *= 10;
        for (int x = 1; x <= 9; x++) {
            int num = 0;
            for (int i = 0; i < len; i++) {
                num = num * 10 + x;
            }
            if (num <= n) {
                ans++;
            }
            for (int y = 0; y <= 9; y++) {
                if (y == x) {
                    continue;
                }
                for (int mask = 1; mask < (1 << (len - 1)); mask++) {
                    int num = x;
                    for (int j = len - 2; j >= 0; j--) {
                        num *= 10;
                        if (mask & (1 << j)) {
                            num += y;
                        } else {
                            num += x;
                        }
                    }
                    if (num <= n) {
                        ans++;
                    }
                }
            }
        }
    }
    if (n == 1000000000) {
        ans++;
    }
    cout << ans;



    return 0;
}