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

char s[111111];

bool lt(int i, int j, int len) {
    for (int k = 0; k < len; k++) {
        if (s[i + k] != s[j + k]) {
            return s[i + k] < s[j + k];
        }
    }
    return false;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int len = 1, clen = 0;
    while (len < n && s[len] == '0') {
        len++;
    }
    int st = 0;
    int ans = 1;
    for (int i = len; i < n; ) {
        clen = 1;
        while (i + clen < n && s[i + clen] == '0') {
            clen++;
        }
        if (len < clen || (len == clen && lt(0, i, len))) {
            ans = 1;
        } else {
            ans++;
        }
        len += clen;
        i += clen;
    }
    cout << ans;

    return 0;
}