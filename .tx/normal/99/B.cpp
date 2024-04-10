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

pair<int, int> a[1111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = {x, i};
    }
    sort(a, a + n);
    if (a[0].first == a[n - 1].first) {
        cout << "Exemplary pages.";
        return 0;
    }
    bool ok = true;
    for (int i = 2; i + 1 < n; i++) {
        if (a[i].first != a[1].first) {
            ok = false;
            break;
        }
    }
    if (n > 2 && a[1].first - a[0].first != a[n - 1].first - a[1].first) {
        ok = false;
    }
    if ((a[n - 1].first - a[0].first) % 2 == 1) {
        ok = false;
    }
    if (!ok) {
        cout << "Unrecoverable configuration.";
        return 0;
    }
    cout << (a[n - 1].first - a[0].first) / 2 << " ml. from cup #" << a[0].second + 1 << " to cup #" << a[n - 1].second + 1 << ".";

    return 0;
}