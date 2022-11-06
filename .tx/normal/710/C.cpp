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
    scid(n);
    int i1 = 1;
    int i2 = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int len = max(abs(i - n / 2), abs(j - n / 2));
            if ((((len + 1)) & 1) ^ ((i + j) & 1)) {
                cout << i1 << " ";
                i1 += 2;
            } else {
                cout << i2 << " ";
                i2 += 2;
            }
        }
        cout << "\n";
    }

    return 0;
}