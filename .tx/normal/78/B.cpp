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

int ans[111];

int main() {
    srand(31);
    const char* s = " ROYGBIV";
    scid(n);
    for (int i = 0; i < 7; i++) {
        ans[i] = i + 1;
    }
    for (int i = 7; i < n; i++) {
        bool ok;
        int c;
        do {
            ok = true;
            c = rand() % 7 + 1;
            for (int j = 0; j < 3; j++) {
                if (ans[i - j - 1] == c || ans[(i + j + 1) % n] == c) {
                    ok = false;
                    break;
                }
            }
        } while (!ok);
        ans[i] = c;
    }

    for (int i = 0; i < n; i++) {
        cout << s[ans[i]];
    }

    return 0;
}