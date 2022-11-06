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
    string s;
    cin >> s;
    int k0 = 0;
    bool can[10] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 0};
    int r = 0;
    string t;
    for (char c : s) {
        if (c == '0') {
            k0++;
        } else if (!can[c - '0']) {
            can[c - '0'] = true;
        } else {
            r = (r * 10 + c - '0') % 7;
            t += c;
        }
    }

    int p10 = 1;
    for (int i = 0; i < k0; i++) {
        p10 = p10 * 10 % 7;
    }

    int p[4] = {1, 6, 8, 9};
    do {
        int x = 0;
        for (int i = 0; i < 4; i++) {
            x = x * 10 + p[i];
        }
        if ((r * p10 * 10000 + x * p10) % 7 == 0) {
            break;
        }
    } while (next_permutation(p, p + 4));
    cout << t;
    for (int i = 0; i < 4; i++) {
        cout << p[i];
    }
    for (int i = 0; i < k0; i++) {
        cout << 0;
    }

    return 0;
}