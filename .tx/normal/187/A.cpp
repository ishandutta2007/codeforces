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
int b[222222];
int p[222222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        sci(b[i]);
        --b[i];
        p[b[i]] = i;
    }
    for (int i = 0; i < n; i++){
        b[i] = p[a[i]];
//        cerr << b[i] + 1 << " ";
    }
//    cerr << endl;

    for (int i = 0; i + 1 < n; i++) {
        if (b[i + 1] < b[i]) {
            cout << n - 1 - i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}