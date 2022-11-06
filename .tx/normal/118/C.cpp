#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

string s;
pair<int, int> d[11111];

int main() {
    sciid(n, k);
    string s;
    cin >> s;

    int ans = 1e9;
    string as = "";
    string os = s;
    for (char c = '0'; c <= '9'; c++) {
        s = os;
        for (int i = 0; i < n; i++) {
            d[i] = {abs(s[i] - c), s[i] >= c ? -(n - i) : n - i};
        }
        sort(d, d + n);
        int cur = 0;
        for (int i = 0; i < k; i++) {
            cur += d[i].first;
            int x = d[i].second;
            if (x < 0) {
                x = -x;
            }
            x = -x + n;
            s[x] = c;
        }

        if (cur < ans || (cur == ans && s < as)) {
            as = s;
            ans = cur;
        }
    }

    cout << ans << "\n" << as;

    return 0;
}