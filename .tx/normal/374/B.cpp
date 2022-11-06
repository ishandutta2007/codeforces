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
    string s;
    cin >> s;
    int n = s.length();
    s += "9";
    int f = 0;
    lint ans = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] + s[i - 1] - '0' - '0' != 9) {
            int l = i - f;
            if (l % 2 == 1 && l > 1) {
                ans *= (l + 1) / 2;
            }
            f = i;
        }
    }
    cout << ans;


    return 0;
}