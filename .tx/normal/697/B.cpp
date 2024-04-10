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

int main() {
    int a;
    char d[111];
    int b;
    sci(a);
    char c = '.';
    int xd = 0;
    bool onlyZero = true;
    while (c != 'e') {
        if (c != '.') {
            d[xd++] = c;
            if (c != '0') {
                onlyZero = false;
            }
        }
        scanf("%c", &c);
    }
    sci(b);
    if (a == 0 && onlyZero) {
        cout << 0;
        return 0;
    }
    if (onlyZero) {
        xd = 0;
    }

    cout << a;
    int pp = 0;
    for (int i = 0; i < b; i++) {
        if (pp >= xd) {
            cout << 0;
        } else {
            cout << d[pp++];
        }
    }

    if (pp < xd) {
        cout << ".";
        while (pp < xd) {
            cout << d[pp++];
        }
    }

    return 0;
}