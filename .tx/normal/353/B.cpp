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
typedef long double ldouble;

using namespace std;

int ans[111];
vector<int> m[111];

int main() {
    scid(n);
    n *= 2;

    for (int i = 0; i < n; i++) {
        scid(x);
        m[x].push_back(i);
    }
    int x1 = 1;
    set<int> c[3];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 2 && j < m[i].size(); j++) {
            ans[m[i][j]] = x1;
            c[x1].insert(i);
            x1 = 3 - x1;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 2; j < m[i].size(); j++) {
            ans[m[i][j]] = x1;
            c[x1].insert(i);
            x1 = 3 - x1;
        }
    }
    cout << c[1].size() * c[2].size() << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}