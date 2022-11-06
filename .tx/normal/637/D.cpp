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

int a[222222];

const string FAIL = "IMPOSSIBLE";

int main() {
    sciid(n, m);
    sciid(s, d);
    rea(a, n);
    random_shuffle(a, a + n);
    sort(a, a + n);
    if (a[0] <= s) {
        cout << FAIL;
        return 0;
    }
    vector<pair<int, int> > b;
    for (int i = 0; i < n; i++) {
        if (b.empty() || a[i] - b.back().second >= s + 2) {
            b.push_back({a[i], a[i]});
        } else {
            b.back().second = a[i];
        }
    }
    for (auto& i : b) {
        if (i.second - i.first + 2 > d) {
            cout << FAIL;
            return 0;
        }
    }

    int cc = 0;
    for (auto& i : b) {
        cout << "RUN " << i.first - cc - 1 << "\n";
        cout << "JUMP " << i.second - i.first + 2 << "\n";
        cc = i.second + 1;
    }
    if (m != cc) {
        cout << "RUN " << m - cc;
    }

    return 0;
}