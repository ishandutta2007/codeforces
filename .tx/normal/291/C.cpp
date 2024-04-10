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

unsigned int a[111111];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        unsigned int x, y, z, t;
        scanf("\n%d.%d.%d.%d", &x, &y, &z, &t);
        a[i] = (x << 24) + (y << 16) + (z << 8) + t;
    }
    for (int i = 31; i >= 1; i--) {
        unsigned int mask = (1LL << 32) - (1LL << i);

        set<unsigned int> s;
        for (int j = 0; j < n; j++) {
            s.insert(a[j] & mask);
        }

        if (s.size() == k) {
            unsigned int x[4];
            for (int j = 3; j >= 0; j--) {
                x[j] = mask & 0xFF;
                mask >>= 8;
            }
            printf("%d.%d.%d.%d", x[0], x[1], x[2], x[3]);
            return 0;
        }
    }
    cout << -1;

    return 0;
}