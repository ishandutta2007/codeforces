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

int a[111111];

bool check(int x, int n) {
    int y = n / x;
    for (int i = 0; i < y; i++) {
        bool ok = true;
        for (int j = i; j < n; j += y) {
            if (a[j] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    scid(n);
    rea(a, n);
    if (n % 4 == 0 && check(4, n)) {
        cout << "YES";
        return 0;
    }
    int x = n;
    while (x % 2 == 0) {
        x /= 2;
    }
    for (int i = 3; i * i <= x; i++) {
        if (x % i == 0) {
            if (check(i, n)) {
                cout << "YES";
                return 0;
            }
            do {
                x /= i;
            } while (x % i == 0);
        }
    }
    if (x != 1 && check(x, n)) {
        cout << "YES";
        return 0;
    }
    cout << "NO";


    return 0;
}