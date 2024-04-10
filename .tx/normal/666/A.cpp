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

bool d[11111][4];

int main() {
    init_cin
    string s;
    cin >> s;
    s = s.substr(5, s.size() - 5);
    int n = s.length();
    set<string> sf;
    if (n >= 2) {
        d[n - 2][2] = true;
        sf.insert(s.substr(n - 2, 2));
    }
    if (n >= 3) {
        d[n - 3][3] = true;
        sf.insert(s.substr(n - 3, 3));
    }

    for (int i = n - 4; i >= 0; i--) {
        bool can2 = false;
        can2 |= d[i + 2][3];
        can2 |= d[i + 2][2] && s.substr(i, 2) != s.substr(i + 2, 2);
        if (can2) {
            d[i][2] = true;
            sf.insert(s.substr(i, 2));
        }

        bool can3 = false;
        can3 |= d[i + 3][2];
        can3 |= d[i + 3][3] && s.substr(i, 3) != s.substr(i + 3, 3);
        if (can3) {
            d[i][3] = true;
            sf.insert(s.substr(i, 3));
        }
    }

    cout << sf.size() << "\n";
    for (auto& i : sf) {
        cout << i << "\n";
    }

    return 0;
}