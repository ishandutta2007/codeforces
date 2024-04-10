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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int bc(char a, char b) {
    if (a == b) {
        return 0;
    }
    if (a == 'R' && b == 'S' || a == 'S' && b == 'P' || a == 'P' && b == 'R') {
        return 1;
    }
    return -1;
}

int main() {
    scid(k);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    int nk = n * m / gcd(n, m);

    int f1 = 0, f2 = 0;
    int bn, bm;
    for (int i = 0; i < nk; i++) {
        if (k % nk == i) {
            bn = f1;
            bm = f2;
        }
        int x = bc(s[i % n], t[i % m]);
        if (x == 1) {
            f2++;
        } else if (x == -1) {
            f1++;
        }
    }

    printf("%d %d", bn + f1 * (k / nk), bm + f2 * (k / nk));



    return 0;
}