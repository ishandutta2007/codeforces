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

int t[222222];
int ac[222222];
int ct[222222];

int main() {
    sciid(n, k);
    sciid(b, c);
    b = min(b, 5 * c);
    for (int i = 0; i < n; i++) {
        scid(x);
        t[i] = x + 1e9;
    }

    sort(t, t + n);
    lint ans = 5e18;

    for (int md = 0; md < 5; md++) {
        for (int i = 0; i < n; i++) {
            int cm = t[i] % 5;
            ac[i] = (md - cm + 5) % 5 * c;
            ct[i] = (t[i] + (md - cm + 5) % 5) / 5;
        }

        priority_queue<lint> q;
        lint add = 0;
        lint sum = 0;
        for (int i = 0; i < n; i++) {
            if (i) {
                if (ct[i] != ct[i - 1]) {
                    add += 1LL * b * (ct[i] - ct[i - 1]);
                    sum += 1LL * q.size() * b * (ct[i] - ct[i - 1]);
                }
            }
            q.push(ac[i] - add);
            sum += ac[i];
            while (q.size() > k) {
                lint mx = q.top();
                q.pop();
                sum -= mx + add;
            }
            if (q.size() == k) {
                ans = min(ans, sum);
            }
        }
    }

    cout << ans;

    return 0;
}