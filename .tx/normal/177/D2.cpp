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

int a[111111];
int b[111111];

int main() {
    sciiid(n, m, c);
    rea(a, n);
    rea(b, m);
    for (int i = 1; i < m; i++) {
        b[i] = (b[i] + b[i - 1]) % c;
    }

    for (int i = 0; i < n; i++) {
        int f = max(0, m - (n - i));
        int t = min(i, m - 1);
        int s = b[t] - (f == 0 ? 0 : b[f - 1]);
        s = (s % c + c) % c;
        a[i] = (a[i] + s) % c;

        cout << a[i] << " ";
    }


    return 0;
}