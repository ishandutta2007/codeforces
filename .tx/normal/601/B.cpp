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

int a[111111];

int main() {
    sciid(n, q);
    scid(x);
    for (int i = 0; i + 1 < n; i++) {
        scid(y);
        a[i] = abs(x - y);
        x = y;
    }

    while (q-- > 0) {
        sciid(l, r);
        --l;
        r -= 2;
        stack<int> st;
        lint ans = 0;
        lint rem = 0;
        for (int i = l; i <= r; i++) {
            while (!st.empty() && a[i] >= a[st.top()]) {
                int x = st.top();
                st.pop();
                if (st.empty()) {
                    rem = 0;
                } else {
                    rem -= 1LL * a[x] * (x - st.top());
                }
            }
            if (st.empty()) {
                rem = 1LL * a[i] * (i - l + 1);
            } else {
                rem += 1LL * a[i] * (i - st.top());
            }
            st.push(i);
            ans += rem;
        }
        cout << ans << "\n";
    }


    return 0;
}