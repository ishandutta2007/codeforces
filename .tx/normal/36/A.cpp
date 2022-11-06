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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(n);
    set<int> ds;
    scanf("\n%s", s);
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (last != -1) {
                ds.insert(i - last);
            }
            last = i;
        }
    }
    cout << (ds.size() == 1 ? "YES" : "NO");

    return 0;
}