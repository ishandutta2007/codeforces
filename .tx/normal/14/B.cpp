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

int a[1111];
int b[1111];

int main() {
    sciid(n, x0);
    for (int i = 0; i < n; i++) {
        scii(a[i], b[i]);
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }
    int ans = 1e9;
    for (int x = 0; x <= 1000; x++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (x < a[i] || x > b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans, abs(x - x0));
        }
    }
    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}