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
#include <stack>

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

int a[111111];

int main() {
    scid(n);
    rea(a, n);
    int ans = 0;
    for (int tt = 0; tt < 2; tt++) {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() < a[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans = max(ans, a[i] ^ s.top());
            }
            s.push(a[i]);
        }
        reverse(a, a + n);
    }
    cout << ans;

    return 0;
}