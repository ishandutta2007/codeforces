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
typedef long double ldouble;

using namespace std;

int main() {
    init_cin
    ldouble p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ldouble a;
        cin >> a;
        p -= a * q;
        if (i + 1 < n) {
            if (abs(p) <= 1e-10) {
                cout << "NO";
                return 0;
            }
            swap(p, q);
        }
    }
    if (abs(p) <= 1e-10) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}