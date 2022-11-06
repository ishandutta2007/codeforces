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

int main() {
    sciid(n, m);
    int on = n, om = m;
    int last = 0;
    int k1 = 0, k2 = 0;
    n--;
    if (n >= 0) {
        int i = 1;
        while (n > 0 || m > 0) {
            int cur;
            if (n == 0) {
                cur = 1;
                m--;
            } else if (m == 0) {
                cur = 0;
                n--;
            } else {
                if (i % 2 == 0) {
                    if (last == 0) {
                        n--;
                    } else {
                        m--;
                    }
                    cur = last;
                } else {
                    if (last == 0) {
                        m--;
                    } else {
                        n--;
                    }
                    cur = 1 - last;
                }
            }
            if (cur == last) {
                k1++;
            } else {
                k2++;
            }
            last = cur;
            i++;
        }
    }
    int o1 = k1, o2 = k2;
    n = on;
    m = om;
    last = 1;
    k1 = k2 = 0;
    m--;
    if (m >= 0) {
        int i = 1;
        while (n > 0 || m > 0) {
            int cur;
            if (n == 0) {
                cur = 1;
                m--;
            } else if (m == 0) {
                cur = 0;
                n--;
            } else {
                if (i % 2 == 0) {
                    if (last == 0) {
                        n--;
                    } else {
                        m--;
                    }
                    cur = last;
                } else {
                    if (last == 0) {
                        m--;
                    } else {
                        n--;
                    }
                    cur = 1 - last;
                }
            }
            if (cur == last) {
                k1++;
            } else {
                k2++;
            }
            last = cur;
            i++;
        }
    }
    if (k1 > o1) {
        cout << k1 << " " << k2;
    } else {
        cout << o1 << " " << o2;
    }

    return 0;
}