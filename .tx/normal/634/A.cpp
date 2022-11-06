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

int a[444444];
int b[222222];

int main() {
    scid(n);
    int p0 = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] == 0) {
            p0 = i;
        }
    }
    rotate(a, a + p0, a + n);
    for (int i = 0; i < n; i++) {
        sci(b[i]);
        if (b[i] == 0) {
            p0 = i;
        }
    }
    rotate(b, b + p0, b + n);
    int pp = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == b[1]) {
            pp = i;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[pp] != b[i]) {
            cout << "NO";
            return 0;
        }
        pp++;
        if (pp >= n) {
            pp = 1;
        }
    }
    cout << "YES";




    return 0;
}