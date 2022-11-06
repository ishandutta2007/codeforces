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

string Dany = "Daenerys";
string Stan = "Stannis";

int main() {
    sciid(n, k);
    int cOdd = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x & 1) {
            cOdd++;
        }
    }
    if (k == n) {
        cout << (cOdd % 2 == 0 ? Dany : Stan);
        return 0;
    }
    int cEven = n - cOdd;
    int len = n - k;
    int cStan = (len + 1) / 2;
    int cDany = len - cStan;
    if (cDany >= cOdd || cDany >= cEven && k % 2 == 0) {
        cout << Dany;
        return 0;
    }
    if (cStan >= cEven && k % 2 == 1) {
        cout << Stan;
        return 0;
    }
    if (len % 2 == 0) {
        cout << Dany;
    } else {
        cout << Stan;
    }

    return 0;
}