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

int rs[1111];
int cs[1111];

lint a[1111111];
lint b[1111111];

int main() {
    sciiid(n, m, k);
    scid(p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            rs[i] += x;
            cs[j] += x;
        }
    }

    priority_queue<lint> q;
    for (int i = 0; i < n; i++) {
        q.push(rs[i]);
    }
    for (int i = 1; i <= k; i++) {
        lint x = q.top();
        q.pop();
        a[i] = a[i - 1] + x;
        q.push(x - m * p);
    }

    while (!q.empty()) {
        q.pop();
    }

    for (int i = 0; i < m; i++) {
        q.push(cs[i]);
    }
    for (int i = 1; i <= k; i++) {
        lint x = q.top();
        q.pop();
        b[i] = b[i - 1] + x;
        q.push(x - n * p);
    }

    lint ans = -1e18;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, a[i] + b[k - i] - 1LL * i * (k - i) * p);
    }

    cout << ans;

    return 0;
}