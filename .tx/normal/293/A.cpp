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

int main() {
    init_cin
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    int c00 = 0, c10 = 0, c11 = 0, c01 = 0;
    n *= 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '0') {
            c00++;
        } else if (s[i] == '0' && t[i] == '1') {
            c01++;
        } else if (s[i] == '1' && t[i] == '0') {
            c10++;
        } else {
            c11++;
        }
    }

    int cy = 0, ca = 0;
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            if (c11 > 0) {
                cy++;
                c11--;
            } else if (c10 > 0) {
                cy++;
                c10--;
            } else if (c01 > 0) {
                c01--;
            } else {
                c00--;
            }
        } else {
            if (c11 > 0) {
                ca++;
                c11--;
            } else if (c01 > 0) {
                ca++;
                c01--;
            } else if (c10 > 0) {
                c10--;
            } else {
                c00--;
            }
        }
    }

    cout << (cy > ca ? "First" : cy == ca ? "Draw" : "Second");

    return 0;
}