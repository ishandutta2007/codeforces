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

deque<int> mx[5];
int ans[5];

int a[111111][5];

int main() {
    sciiid(n, m, k);
    int ld = -1;
    int alen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            a[i][j] = x;
            while (!mx[j].empty() && mx[j].back() < x) {
                mx[j].pop_back();
            }
            mx[j].push_back(x);
        }
        while (true) {
            int cs = 0;
            for (int j = 0; j < m; j++) {
                if (!mx[j].empty()) {
                    cs += mx[j].front();
                }
            }
            if (cs <= k) {
                break;
            }
            ld++;
            for (int j = 0; j < m; j++) {
                if (mx[j].front() == a[ld][j]) {
                    mx[j].pop_front();
                }
            }
        }
        if (i - ld > alen) {
            alen = i - ld;
            for (int j = 0; j < m; j++) {
                ans[j] = mx[j].front();
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}