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

int getNum(string& s, int l, int r) {
    if (l >= r || r - l > 7) {
        return -1;
    }
    if (l + 1 < r && s[l] == '0') {
        return -1;
    }
    int res = 0;
    for (int i = l; i < r; i++) {
        res = res * 10 + s[i] - '0';
    }
    if (res > 1e6) {
        return -1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = -1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = getNum(s, 0, i);
            int x2 = getNum(s, i, j);
            int x3 = getNum(s, j, n);
            if (x1 != -1 && x2 != -1 && x3 != -1) {
                ans = max(ans, x1 + x2 + x3);
            }
        }
    }
    cout << ans;
    return 0;
}