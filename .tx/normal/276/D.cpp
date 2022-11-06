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

int main() {
    init_cin
    lint l, r;
    cin >> l >> r;
    lint a = l;
    lint b = r;
    for (int i = 62; i >= 0; i--) {
        int ia = (a >> i) & 1;
        int ib = (b >> i) & 1;
        lint ii = (1LL << i);
        if (ia != ib) {
            continue;
        }
        if (ia == 1) {
            if ((b ^ ii) >= l) {
                b ^= ii;
            } else if ((a ^ ii) >= l) {
                a ^= ii;
            }
        } else {
            if ((a ^ ii) <= r) {
                a ^= ii;
            } else if ((b ^ ii) <= r) {
                b ^= ii;
            }
        }
    }
    cout << (a ^ b);
    return 0;
}