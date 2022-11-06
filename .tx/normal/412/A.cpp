#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    init_cin();
    int n, k;
    string s;
    cin >> n >> k >> s;
    string d;
    int ck;
    if (k - 1 <= n - k) {
        for (int i = 0; i < k - 1; i++) {
            cout << "LEFT\n";
        }
        k = 1;
        ck = 1;
        d = "RIGHT";
    } else {
        for (int i = k; i < n; i++) {
            cout << "RIGHT\n";
        }
        k = n;
        ck = -1;
        d = "LEFT";
    }
    for (int i = 0; i < n; i++) {
        cout << "PRINT " << s[k - 1] << "\n";
        k += ck;
        if (i + 1 < n) {
            cout << d << "\n";
        }
    }

    return 0;
}