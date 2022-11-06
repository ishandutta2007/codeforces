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

bool lt[3][3];
int main() {
    string s;
    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (s[1] == '>') {
            reverse(s.begin(), s.end());
        }
        lt[s[0] - 'A'][s[2] - 'A'] = true;
    }

    int p[3] = {1, 2, 3};
    do {
        bool ok = true;
        for (int i = 0; i < 3; i++) {
            int x = p[i];
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    continue;
                }
                int y = p[j];
                if (x < y && !lt[i][j] || x > y && lt[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            char ans[3];
            for (int i = 0; i < 3; i++) {
                ans[p[i] - 1] = i + 'A';
            }
            for (int i = 0; i < 3; i++) {
                cout << ans[i];
            }
            return 0;
        }
    } while (next_permutation(p, p + 3));
    cout << "Impossible";

    return 0;
}