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

int a[111111];

set<int> ans;

int main() {
    scid(n);
    rea(a, n);
    set<int> cur, nxt;
    for (int i = 0; i < n; i++) {
        nxt.insert(a[i]);
        for (int j : cur) {
            nxt.insert(j | a[i]);
        }
        cur.clear();
        for (int j : nxt) {
            ans.insert(j);
            cur.insert(j);
        }
        nxt.clear();
    }

    printf("%d\n", (int) ans.size());

    return 0;
}