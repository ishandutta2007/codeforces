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

int a[111];

int main() {
    scid(n);
    int kodd = 0;
    int s = 0;
    int minOdd = 1e9;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] & 1) {
            kodd++;
            minOdd = min(minOdd, a[i]);
        }
        s += a[i];
    }
    if (kodd == 0) {
        cout << 0;
        return 0;
    }

    if (s & 1) {
        cout << s;
    } else {
        cout << s - minOdd;
    }

    return 0;
}