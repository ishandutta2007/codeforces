#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

bool isLeap(int x) {
    return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0);
}

int main() {
    scid(y);
    int s = 0;
    for (int i = y; ; i++) {
        s += 365;
        if (isLeap(i)) {
            s++;
        }
        if (s % 7 == 0 && isLeap(i + 1) == isLeap(y)) {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}