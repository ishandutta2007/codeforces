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
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }
    int m = divs.size();
    lint mn = 1e18, mx = -1e18;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            lint a = divs[i];
            lint b = divs[j];
            if (n % (a * b) != 0) {
                continue;
            }
            lint c = n / (a * b);
            a++;
            b += 2;
            c += 2;
            lint st = b * c + 2 * a * c + 2 * a * b - 2 * c - 2 * b - 4 * a + 4;
            mn = min(mn, st);
            mx = max(mx, st);
        }
    }

    cout << mn << " " << mx;

    return 0;
}