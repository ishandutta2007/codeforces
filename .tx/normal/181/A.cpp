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

char s[111];

int main() {
    sciid(n, m);
    vector<pair<int, vector<int> > > a;
    for (int i = 0; i < n; i++) {
        scanf("\n%s", s);
        vector<int> c;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                c.push_back(j);
            }
        }
        if (!c.empty()) {
            a.push_back({i, c});
        }
    }
    if (a[0].second.size() == 2) {
        swap(a[0], a[1]);
    }
    if (a[0].second[0] == a[1].second[0]) {
        cout << a[0].first + 1 << " " << a[1].second[1] + 1;
    } else {
        cout << a[0].first + 1 << " " << a[1].second[0] + 1;
    }

    return 0;
}