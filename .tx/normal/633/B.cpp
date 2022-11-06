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
    scid(m);
    int c0 = 0;
    for (int i = 5; c0 < m; i += 5) {
        int x = i;
        while (x % 5 == 0) {
            c0++;
            x /= 5;
        }
        if (c0 == m) {
            cout << 5 << "\n";
            for (int j = 0; j < 5; j++) {
                cout << i + j << " ";
            }
            return 0;
        }
    }
    cout << 0;


    return 0;
}