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

bitset<200> a[222 * 222];

bool used[222];

int main() {
    scid(n);
    n = n * (n - 1) / 2;
    if (n == 1) {
        scid(k);
        scid(x);
        cout << "1 " << x << "\n";
        cout << k - 1 << " ";
        for (int i = 1; i < k; i++) {
            sci(x);
            cout << x << " ";
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scid(k);
        for (int j = 0; j < k; j++) {
            scid(x);
            --x;
            a[i].set(x);
        }
    }

    for (int i = 0; i < 200; i++) {
        if (used[i]) {
            continue;
        }
        bitset<200> cur;
        cur.flip();
        for (int j = 0; j < n; j++) {
            if (a[j][i]) {
                cur &= a[j];
            }
        }
        if (cur.all()) {
            continue;
        }
        cout << cur.count();
        for (int j = 0; j < 200; j++) {
            if (cur[j]) {
                cout << " " << j + 1;
                used[j] = true;
            }
        }
        cout << "\n";
    }


    return 0;
}