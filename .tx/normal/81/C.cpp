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

pair<int, int> t[111111];
int ans[111111];

int main() {
    scid(n);
    sciid(a, b);
    if (a == b) {
        for (int i = 0; i < a; i++) {
            cout << 1 << " ";
        }
        for (int i = 0; i < b; i++) {
            cout << 2 << " ";
        }
        return 0;
    }
    priority_queue<pair<int, int> > q;
    if (a < b) {
        for (int i = 0; i < n; i++) {
            scid(x);
            q.push({-x, i});
        }
    } else {
        for (int i = 0; i < n; i++) {
            scid(x);
            q.push({x, i});
        }
    }
    while (q.size() > a) {
        auto v = q.top();
        q.pop();
        ans[v.second] = 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }



    return 0;
}