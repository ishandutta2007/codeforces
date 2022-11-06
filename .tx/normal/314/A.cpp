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

int a[222222];

int main() {
    sciid(n, k);
    rea(a, n);

    int kt = 1, cn = n;
    lint ps = 0;
    for (int i = 1; i < n; i++) {
        if (ps - 1LL * kt * (cn - kt - 1) * a[i] < k) {
            cn--;
            cout << i + 1 << "\n";
        } else {
            ps += 1LL * kt * a[i];
            kt++;
        }
    }

    return 0;
}